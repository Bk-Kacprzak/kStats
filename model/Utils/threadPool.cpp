//
// Created by Bartłomiej Kacprzak on 09/09/2021.
//

#include "threadPool.h"
#include <iostream>
#include "utils.h"
knet::threadPool::threadPool() : numOfThreads(std::thread::hardware_concurrency()), functionQueue(), mutexLock(), dataCondition(), acceptFunctions(), exitThreads(false) {
    for(int i = 0; i<numOfThreads; i++)
        threads.push_back(std::move(std::thread(&threadPool::inifiniteLoop, this)));
}

knet::threadPool::~threadPool() {
    for(auto& thread : threads) {
        if (thread.joinable())
            thread.detach();
    }
}

void knet::threadPool::push(std::function<void()> func) {
    std::unique_lock<std::mutex> lock(mutexLock);
    functionQueue.push(func);
    //unlock mutex to enable consumer to lock mutex asap
    lock.unlock();
    dataCondition.notify_one();
}

void knet::threadPool::exit() {
    std::unique_lock<std::mutex> lock(mutexLock);
    acceptFunctions = false;
    while(!functionQueue.empty())
        functionQueue.pop();
    lock.unlock();
    //notify all waiting threads
//    dataCondition.notify_all();
}

void knet::threadPool::inifiniteLoop() {
    std::function<void()> func;
    while(!exitThreads) {
        {
            std::unique_lock<std::mutex> lock(mutexLock);
            dataCondition.wait(lock, [this]() {
                return !functionQueue.empty() || acceptFunctions || exitThreads;
            });

            if (functionQueue.empty() && !acceptFunctions)
                return;

            func = std::move(functionQueue.front());
            functionQueue.pop();
            //release the lock
        }

        func();
    }
}

int knet::threadPool::getNumOfThreads() const {
    return numOfThreads;
}
