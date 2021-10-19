//
// Created by Bartłomiej Kacprzak on 06/10/2021.
//

#include "gpu_device.h"
#include <Metal/Metal.h>

GPU::GPU() {
    retrieveModelName();
//    retrieveAllTemperatureValues();
}

void GPU::retrieveTemperature(const int &property) {
    try {
        int return_value = readKey(temperature[property]).i;
        std::lock_guard<std::mutex> lock(temperatures.mtx);
        temperatures.value[property] = return_value / 256.0;
        switch(property){
            case 0: {
                std::cout << "GPU PROXIMITY: " << temperatures.value[property] << std::endl;
                break;
            }
            case 1: {
                std::cout << "GPU Radeon : " << temperatures.value[property] << std::endl;
                break;
            }
            case 2: {
                std::cout << "GPU Intel: " << temperatures.value[property] << std::endl;
                break;
            }
            case 3: {
                std::cout << "GPU Heatsink: " << temperatures.value[property] << std::endl;
                break;
            }
        }

    }

    catch (const std::exception& e) {
        std::cout<<e.what();
        exit(0);
    }
}

void GPU::retrieveModelName() {
    NSArray<id <MTLDevice>> *deviceList = nil;
    deviceList = MTLCopyAllDevices();
    for(id<MTLDevice> device : deviceList) {
        std::lock_guard<std::mutex> lock(modelName.mtx);
        modelName.value.emplace_back(device.name.UTF8String);
    }
}

void GPU::retrieveAllTemperatureValues() {
    for(int i = 0; i < GPU_TEMP_COUNT; i++) {
        threadPool.push([=] () {
            retrieveTemperature(i);
        });
    }
}

const std::vector<std::string> &GPU::ModelName() {
    std::unique_lock<std::mutex> lock(modelName.mtx);
    cv.wait(lock,[this] {
        return !modelName.value.empty();
    });
    return modelName.value;
}

const std::array<float, GPU_ALL_TEMP> &GPU::Temperatures() {
    std::unique_lock<std::mutex> lock(temperatures.mtx);
    cv.wait(lock,[this] {
        return !temperatures.value.empty();
    });
    return temperatures.value;
}
