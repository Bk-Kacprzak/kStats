#include "cpu_model.h"
#include "../Utils/utils.h"
#include <thread>
#include <mutex>

#include <vector>

CPU::CPU() : physicalCoreCount(0), cacheSize(0), byteOrder(-1), architecture(-1) {
    readCPUInformation();
}

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

void CPU::readTemperature(const int &index) {
    try {
        if (index >= temperature.size())
            throw std::invalid_argument("Invalid index number.\n");

        int return_value = readKey(temperature[index]).i;
        std::lock_guard<std::mutex> lock(temperatures.mtx);
        temperatures.value[index] = (int)(return_value / 256.0);
        cv.notify_one();
    }

    catch (const std::exception& e) {
        std::cout<<e.what();
        exit(0);
    }
}

ushort CPU::getCoreNumber() {
    return 6;
}

const std::array<float, CPU_MAX_COUNT> & CPU::Temperatures() {
    for(int i = 0; i<physicalCoreCount.value+2; i++) {
        threadPool.push([=] {
            readTemperature(i);
        });
    }

    std::unique_lock<std::mutex> lock(temperatures.mtx);
    bool isFinished;
    cv.wait(lock,[&] {
        isFinished = true;
        for(const auto& value : temperatures.value)
            if(value == 0) {
                isFinished = false;
                break;
            }
        return isFinished;
    });

    return temperatures.value;
}

CPU::~CPU() {

}


const char *CPU::ProcessorModel() const {
    std::unique_lock<std::mutex> lock(processorModel.mtx);
    cv.wait(lock,[this] {
        return strlen(processorModel.value) > 0;
    });
    return processorModel.value;
}

ushort CPU::PhysicalCoreCount() const {
    std::unique_lock<std::mutex> lock(physicalCoreCount.mtx);
    cv.wait(lock,[this] {
        return physicalCoreCount.value!=0;
    });
    return physicalCoreCount.value;
}

ushort CPU::CacheSize() const {
    std::unique_lock<std::mutex> lock(cacheSize.mtx);
    cv.wait(lock,[this] {
        return cacheSize.value!=0;
    });
    return cacheSize.value;
}

ushort CPU::ByteOrder() const {
    std::unique_lock<std::mutex> lock(byteOrder.mtx);
    cv.wait(lock,[this] {
        return byteOrder.value != -1 ;
    });
    return byteOrder.value;
}

ushort CPU::Architecture() const {
    std::unique_lock<std::mutex> lock(architecture.mtx);
    cv.wait(lock,[this] {
        return architecture.value != -1;
    });
    return architecture.value;
}

void CPU::readCPUInformation() {
    //if they are not empty, dont do anything.
    // those values are
    threadPool.push([&] {
        sysctlCall(processorModel,"machdep.cpu.brand_string", 128);
    });

    threadPool.push([&] {
        sysctlCall(physicalCoreCount,"machdep.cpu.core_count", 64);
    });

    threadPool.push([&] {
        sysctlCall(cacheSize,"machdep.cpu.cache.size", 64);
    });

    threadPool.push([&] {
        sysctlCall(byteOrder,"hw.byteorder", 64);
    });

    threadPool.push([&] {
        sysctlCall(architecture, "hw.optional.x86_64", 64);
    });
}




