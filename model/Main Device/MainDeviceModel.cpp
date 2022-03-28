//
// Created by Bartłomiej Kacprzak on 03/02/2022.
//

#include "MainDeviceModel.h"

MainDeviceModel::MainDeviceModel() {
    getDeviceInfo();
}

void MainDeviceModel::getDeviceInfo() {
//OS Version
    sysctlCall(osVersion,"kern.osversion",0);
    for(const auto& item : currentOs) {
        if (strcmp(item.second,osVersion.value) == 0) {
            memcpy(osVersion.value, item.first, strlen(item.first)+1);
        }
    }

    sysctlCall(deviceName,"hw.model",64);
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