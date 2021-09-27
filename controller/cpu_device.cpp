#include "cpu_device.h"
#include "Utils/utils.h"
#include <thread>
#include <vector>

CPU::CPU() : physicalCoreCount(0), cacheSize(0), byteOrder(-1), architecture(-1), assigning(true) {
    retrieveCPUInormation();

//    threadPool.push([&] {
//
//        retrieveCPUInformation(processorModel,"machdep.cpu.brand_string", 128);
//    });

//    threadPool.push([&] {
//        retrieveCPUInformation(processorModel,"machdep.cpu.brand_string", 128);
//    });



//
//    std::unique_lock<std::mutex> lock(classMtx);
//    cv.wait(lock, [&] {
//        return !assigning;
//    });
//    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
//    std::cout<<"Byte order: "<<getByteOrder()<<std::endl;
//    std::cout<<"Architecture: "<<getArchitecture()<<std::endl;
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

void CPU::getTemperature(const int &core) {
    try {
//        if(core >= Utils::getArraySize(temperature))
//            throw std::invalid_argument("Invalid core number.\n");
//        std::lock_guard<std::mutex> lockGuard(mtx);
        int return_value = readKey(temp_mutex,temperature[core]).i;

        //consumer producer problem!!!!
        std::lock_guard<std::mutex> lock(temp_mutex);
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
    }

    catch (const std::exception& e) {
       std::cout<<e.what();
       exit(0);
    }

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
}

CPU::~CPU() {

}

template<typename T>
void CPU::sysctlCall(ValueContainer<T>& _value, const char * command, size_t max_byte_size) {
    std::lock_guard<std::mutex> lock(_value.mtx);
    sysctlbyname(command, &_value.value, &max_byte_size, nullptr, 0);
}

const char *CPU::getProcessorModel() const {
    std::unique_lock<std::mutex> lock(processorModel.mtx);
    cv.wait(lock,[this] {
        return strlen(processorModel.value) > 0;
    });
    return processorModel.value;
}

ushort CPU::getPhysicalCoreCount() const {
    std::unique_lock<std::mutex> lock(physicalCoreCount.mtx);
    cv.wait(lock,[this] {
        return physicalCoreCount.value!=0;
    });
    return physicalCoreCount.value;
}

ushort CPU::getCacheSize() const {
    std::unique_lock<std::mutex> lock(cacheSize.mtx);
    cv.wait(lock,[this] {
        return cacheSize.value!=0;
    });
    return cacheSize.value;
}

ushort CPU::getByteOrder() const {
    std::unique_lock<std::mutex> lock(byteOrder.mtx);
    cv.wait(lock,[this] {
        return byteOrder.value != -1 ;
    });
    return byteOrder.value;
}

ushort CPU::getArchitecture() const {
    std::unique_lock<std::mutex> lock(architecture.mtx);
    cv.wait(lock,[this] {
        return architecture.value != -1;
    });
    return architecture.value;
}

void CPU::retrieveCPUInormation() {
    //if they are not empty, dont do anything.
    // those values are
    threadPool.push([&] {
        sysctlCall(processorModel,"machdep.cpu.brand_string", 128);
        std::cout<<"Model name: "<<getProcessorModel()<<std::endl;
    });

    threadPool.push([&] {
        sysctlCall(physicalCoreCount,"machdep.cpu.core_count", 64);
        std::cout<<"Core count: "<<getPhysicalCoreCount()<<std::endl;
    });

    threadPool.push([&] {
        sysctlCall(cacheSize,"machdep.cpu.cache.size", 64);
        std::cout<<"Cache Size: "<<getCacheSize()<<std::endl;
    });
    threadPool.push([&] {
        sysctlCall(byteOrder,"hw.byteorder", 64);
        std::cout<<"Cache Size: "<<(getByteOrder() == 1234 ? "Little Endian" : "Big Endian" )<<std::endl;
    });
    threadPool.push([&] {
        sysctlCall(architecture, "hw.optional.x86_64", 64);
        std::cout<<"Architecture: " <<(getArchitecture() == 1 ? "x86_64" : "x86")<<std::endl;
    });
}



