//
// Created by Bartłomiej Kacprzak on 18/10/2021.
//

#include "kStatsController.h"

const std::array<float, batteryNum>& kStatsController::getEachBatteryVoltage() {
    model.Battery().retrieveEachBatteryVoltage();
    return model.Battery().batteryVoltageValue;
}

const std::array<int, batteryNum>& kStatsController::getEachBatteryCapacity() {
    model.Battery().retrieveEachBatteryCapacity();
    return model.Battery().batteryCapacityValue;
}

const uint &kStatsController::getCycleCount() {
    model.Battery().retrieveCycleCount();
    return model.Battery().cycleCountValue;
}

const float &kStatsController::getBatteryAmperage() {
    model.Battery().retrieveTotalAmperage();
    return model.Battery().totalAmperageValue;
}

const std::array<float, 8> &kStatsController::getCPUTemperature() {
    return model.Cpu().EachCoreTemperature();
}

const char *kStatsController::getCPUProcessorModel() {
    return model.Cpu().ProcessorModel();
}

const ushort &kStatsController::getCPUPhysicalCoreCount() {
    return model.Cpu().PhysicalCoreCount();
}

const ushort &kStatsController::getCPUCacheSize() {
    return model.Cpu().CacheSize();
}

const ushort &kStatsController::getCPUByteOrder() {
    return model.Cpu().ByteOrder();
}

const ushort &kStatsController::getCPUArchitecture() {
    return model.Cpu().Architecture();
}

void kStatsController::setFanSpeed(const int& speed) {
//todo: find out how to do it
}

const std::array<float, 3> &kStatsController::getLeftFanSpeed() {
    model.Fans().retrieveEachFanSpeedRPM();
    return model.Fans().FanLeft();
}


const std::array<float, 3> &kStatsController::getRightFanSpeed() {
    model.Fans().retrieveEachFanSpeedRPM();
    return model.Fans().FanRight();
}

const std::vector<std::string> &kStatsController::getEachGPUModelName() {
    model.Gpu().retrieveModelName();
    return model.Gpu().ModelName();
}


const std::array<float, GPU_ALL_TEMP> &kStatsController::getEachGPUTemperature() {
    model.Gpu().retrieveAllTemperatureValues();
    model.Gpu().Temperatures();
}

const std::string &kStatsController::getWifiIP() {
    return model.Network().WifiIP();
}

const std::string &kStatsController::getAddressIPv6() {
    return model.Network().AddressIPv6();
}

const std::string &kStatsController::getWifiMacAddress() {
    return model.Network().WifiMacAddress();
}

const std::string &kStatsController::getWifiSSID() {
    return model.Network().WifiSSID();
}

const ConnectionStats &kStatsController::getConnectionsStats() {
    return model.Network().ConnectionSpeed();
}

void kStatsController::testConnectionSpeed() {
    model.Network().setConnectionStats();
}

const std::vector<GenericPeripheral> &kStatsController::getDevices() {
    return model.Peripherals().Devices();
}

const std::string &kStatsController::getVolumeStorageName() {
    return model.VolumeStorage().Name();
}

const std::string &kStatsController::getVolumeStorageFormatDescription() {
    return model.VolumeStorage().FormatDescription();
}

const float &kStatsController::getVolumeStorageTotalMemory() {
    return model.VolumeStorage().TotalMemory();
}

const float &kStatsController::getVolumeStorageFreeMemory() {
    return model.VolumeStorage().FreeMemory();
}

bool kStatsController::isTestingConnection() {
    return model.Network().IsTestingConnection();
}



