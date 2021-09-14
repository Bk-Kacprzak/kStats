#include "cpu_device.h"
#include "Utils/utils.h"
#include <thread>
#include <vector>
CPU::CPU() = default;

void CPU::setKey(CPU::KEYTYPE keytype, const ushort id) {
    switch (keytype) {
        case TEMPERATURE:
            memcpy(currentKey, temperature[id], 5);
            break;
        case POWER:
            memcpy(currentKey, power[id], 5);
            break;
        case CURRENT:
//            memcpy(currentKey, temperature[id], 5);
            break;
        case VOLTAGE:
//            memcpy(currentKey, temperature[id], 5);
            break;
        default:
            throw std::invalid_argument("Unkown keytype.\n");
    }
}

void CPU::getTemperature(const int &core) {
    try {
//        if(core >= Utils::getArraySize(temperature))
//            throw std::invalid_argument("Invalid core number.\n");
//        std::lock_guard<std::mutex> lockGuard(mtx);
        int return_value = readKey(temp_mutex,temperature[core]).i;

        //consumer producer problem!!!!
        temp_mutex.lock();
        CPUTemperature[core] = return_value/256.0;

        if(core == 6)  {
            //avg temp
            std::cout<<"Core average: "<<CPUTemperature[core]<<std::endl;
        }
        else if (core == 7) {
            std::cout<<"Core PECI: "<<CPUTemperature[core]<<std::endl;
        } else {
            std::cout<<"Core "<<core + 1 <<": "<<CPUTemperature[core]<<std::endl;
        }
        temp_mutex.unlock();
    }

    catch (const std::exception& e) {
       std::cout<<e.what();
       exit(0);
    }

}

void CPU::getVoltage(const int &core) {

}

void CPU::getPower(const int &core) {

}

void CPU::getCurrent(const int &core) {

}

void CPU::getName(const int &core) {

}

ushort CPU::getCoreNumber() {
    return 6;
}

void CPU::getEachCoreTemperature() {
    for(int i = 0; i<temperature.size(); i++) {
        threadPool.push([=] {
            getTemperature(i);
        });
    }


//
//    for(int i = 0 ; i< 6; i++) {
//        if (threads[i].joinable())
//            threads[i].join();
//    }


//
//    std::thread a(&CPU::getTemperature,this, 0);
//    std::thread b(&CPU::getTemperature,this, 1);
//    std::thread c(&CPU::getTemperature,this, 2);
//    std::thread d(&CPU::getTemperature,this, 3);
//    std::thread e(&CPU::getTemperature,this, 4);
//    std::thread f(&CPU::getTemperature,this, 5);
//
//    a.join();
//    b.join();
//    c.join();
//    d.join();
//    e.join();
//    f.join();
}

CPU::~CPU() {

}



