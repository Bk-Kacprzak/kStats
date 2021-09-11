#ifndef CPUSTATS_THREADPOOL_H
#define CPUSTATS_THREADPOOL_H

#include <queue>
#include <functional>
#include <mutex>
#include <condition_variable>
#include <atomic>
#include <cassert>
#include <thread>


namespace knet {
    class threadPool {
    private:
        const int numOfThreads;
        std::queue<std::function<void()>> functionQueue;
        std::mutex mutexLock;
        std::condition_variable dataCondition;
        std::atomic<bool> acceptFunctions;
        std::vector<std::thread> threads;

    public:
        threadPool();
        ~threadPool();
        int getNumOfThreads() const;
        void push(std::function<void()> func);
        void exit();
        void inifiniteLoop();
    };
}




#endif //CPUSTATS_THREADPOOL_H
