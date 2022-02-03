//
// Created by Bartłomiej Kacprzak on 03/02/2022.
//

#include "MainDeviceModel.h"

MainDeviceModel::MainDeviceModel() {
    retrieveDeviceInformation();
}

void MainDeviceModel::retrieveDeviceInformation() {
    //OS Version
//    threadPool.push([&] {
        sysctlCall(osVersion,"kern.osversion",0);
        for(const auto& item : currentOs) {
            if (strcmp(item.second,osVersion.value) == 0) {
                memcpy(osVersion.value, item.first, strlen(item.first)+1);
                printf("%s\n", osVersion.value);
            }
        }
//    });

//    threadPool.push([&] {
        sysctlCall(deviceName,"hw.model",64);
    printf("%s\n", deviceName.value);

//    });
}

const char *MainDeviceModel::DeviceName() const {
    std::unique_lock<std::mutex> lock(deviceName.mtx);
    cv.wait(lock,[this] {
        return strlen(deviceName.value) > 0;
    });
    return deviceName.value;
}

const char *MainDeviceModel::OsVersion() const {
    std::unique_lock<std::mutex> lock(osVersion.mtx);
    cv.wait(lock,[this] {
        return strlen(osVersion.value) > 0;
    });
    return osVersion.value;
}