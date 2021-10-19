#include "cpu_model.h"
#include "../Utils/utils.h"
#include <thread>
#include <vector>

CPU::CPU() : physicalCoreCount(0), cacheSize(0), byteOrder(-1), architecture(-1) {
    std::cout<<"********CPUIM HEEEEEEERE********\n\n";
    retrieveCPUInformation();
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

void CPU::retrieveTemperature(const int &core) {
    try {
        if(core >= temperature.size())
            throw std::invalid_argument("Invalid core number.\n");

        int return_value = readKey(temperature[core]).i;

        std::lock_guard<std::mutex> lock(CPUTemperature.mtx);
        CPUTemperature.value[core] = return_value/256.0;
//todo: delete printing
        if(core == 6)  {
            //avg temp
            std::cout<<"Core average: "<<CPUTemperature.value[core]<<std::endl;
        }
        else if (core == 7) {
            std::cout<<"Core PECI: "<<CPUTemperature.value[core]<<std::endl;
        } else {
            std::cout<<"Core "<<core + 1 <<": "<<CPUTemperature.value[core]<<std::endl;
        }
    }

    catch (const std::exception& e) {
       std::cout<<e.what();
       exit(0);
    }
}

ushort CPU::getCoreNumber() {
    return 6;
}

const std::array<float, 8>& CPU::EachCoreTemperature() {
    for(int i = 0; i<physicalCoreCount.value; i++) {
        threadPool.push([=] {
            retrieveTemperature(i);
        });
    }

    std::unique_lock<std::mutex> lock(CPUTemperature.mtx);
    cv.wait(lock,[this] {
        return !CPUTemperature.value.empty();
    });
    return CPUTemperature.value;
}

CPU::~CPU() {

}

template<typename T>
void CPU::sysctlCall(ValueContainer<T>& _value, const char * command, size_t max_byte_size) {
    std::lock_guard<std::mutex> lock(_value.mtx);
    sysctlbyname(command, &_value.value, &max_byte_size, nullptr, 0);
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

void CPU::retrieveCPUInformation() {
    //if they are not empty, dont do anything.
    // those values are
    threadPool.push([&] {
        sysctlCall(processorModel,"machdep.cpu.brand_string", 128);
        std::cout<<"Model name: "<<ProcessorModel()<<std::endl;
    });

    threadPool.push([&] {
        sysctlCall(physicalCoreCount,"machdep.cpu.core_count", 64);
        std::cout<<"Core count: "<<PhysicalCoreCount()<<std::endl;
    });

    threadPool.push([&] {
        sysctlCall(cacheSize,"machdep.cpu.cache.size", 64);
        std::cout<<"Cache Size: "<<CacheSize()<<std::endl;
    });
    threadPool.push([&] {
        sysctlCall(byteOrder,"hw.byteorder", 64);
        std::cout<<"Cache Size: "<<(ByteOrder() == 1234 ? "Little Endian" : "Big Endian" )<<std::endl;
    });
    threadPool.push([&] {
        sysctlCall(architecture, "hw.optional.x86_64", 64);
        std::cout<<"Architecture: " <<(Architecture() == 1 ? "x86_64" : "x86")<<std::endl;
    });
}





