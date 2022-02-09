//
// Created by Bartłomiej Kacprzak on 06/10/2021.
//

#include "gpu_device.h"
#include <Metal/Metal.h>

GPU::GPU() {
    getModelName();
//    retrieveAllTemperatureValues();
}

void GPU::readTemperature(const int &index) {
    try {
        if (index >= temperature.size())
            throw std::invalid_argument("Invalid gpu number.\n");

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

void GPU::getModelName() {
    NSArray<id <MTLDevice>> *deviceList = nil;
    deviceList = MTLCopyAllDevices();
    for(id<MTLDevice> device : deviceList) {
        std::lock_guard<std::mutex> lock(modelName.mtx);
        modelName.value.emplace_back(device.name.UTF8String);
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
    for(int i = 0; i < GPU_TEMP_COUNT; i++) {

        threadPool.push([=] () {
            readTemperature(i);
        });
    }

    std::unique_lock<std::mutex> lock(temperatures.mtx);
    bool isFinished;

    cv.wait(lock,[& ] {
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
