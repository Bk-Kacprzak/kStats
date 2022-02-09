//
// Created by Bartłomiej Kacprzak on 18/10/2021.
//

#include "kStatsController.h"

const std::array<float, batteryNum>& kStatsController::getEachBatteryVoltage() {
    model.Battery().readEachBatteryVoltage();
    return model.Battery().BatteryVoltage();
}

const std::array<int, batteryNum>& kStatsController::getEachBatteryCapacity() {
//    model.Battery().readEachBatteryCapacity();
    return model.Battery().BatteryCapacity();
}

const uint &kStatsController::getCycleCount() {
    model.Battery().readCycleCount();
    return model.Battery().CycleCount();
}

const float &kStatsController::getBatteryAmperage() {
    model.Battery().readTotalAmperage();
    return model.Battery().TotalAmperage();
}

const std::array<float, 8> &kStatsController::getCPUTemperature() {
    return model.Cpu().Temperatures();
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

std::string kStatsController::getCPUArchitecture() {
    return (model.Cpu().Architecture() == 1 ? "x86_64" : "x86");
}

void kStatsController::setFanSpeed(const int& speed) {
//todo: find out how to do it
}

const std::array<int, 3> &kStatsController::getLeftFanSpeed() {
    model.Fans().readEachFanSpeedRPM();
    return model.Fans().FanLeft();
}


const std::array<int, 3> &kStatsController::getRightFanSpeed() {
    model.Fans().readEachFanSpeedRPM();
    return model.Fans().FanRight();
}

const std::vector<std::string> &kStatsController::getEachGPUModelName() {
//    model.Gpu().getModelName();
    return model.Gpu().ModelName();
}


const std::array<float, GPU_ALL_TEMP> &kStatsController::getEachGPUTemperature() {
    return model.Gpu().Temperatures();
}

const char * kStatsController::getWifiIP() {
    return model.Network().WifiIP();
}

const char * kStatsController::getAddressIPv6() {
    return model.Network().AddressIPv6();
}

const std::string &kStatsController::getWifiMacAddress() {
    return model.Network().WifiMacAddress();
}

const std::string &kStatsController::getWifiSSID() {
    return model.Network().WifiSSID();
}

ConnectionStats &kStatsController::getConnectionsStats() {
    return model.Network().ConnectionSpeed();
}

void kStatsController::lockConnectionSpeedTest() {
    model.Network().lockConnectionSpeedTest();
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

std::string kStatsController::getBestServer() {
    return model.Network().getBestServer();
}

float  kStatsController::getDownloadSpeed() {
    return model.Network().getDownloadSpeed();
}

float kStatsController::getUploadSpeed() {
    return model.Network().getUploadSpeed();
}

int kStatsController::getLatency() {
    return model.Network().getLatency();
}

void kStatsController::closeConnectionSpeedTest() {
    model.Network().closeConnectionSpeedTest();
}

std::vector<std::string> kStatsController::getDeviceTypes() {
    return model.Peripherals().deviceTypes();
}

std::vector<std::string> kStatsController::getDeviceNames() {
    return model.Peripherals().deviceNames();
}

const std::array<int, 2> &&kStatsController::getFansCurrentSpeed() {
    model.Fans().getEachFanSpeedRPM(FanModel::CURRENT_SPEED);
    return model.Fans().FansCurrentSpeed();
}

const std::array<int, 4> &&kStatsController::getFansMinMaxSpeed() {
    model.Fans().getEachFanSpeedRPM(FanModel::MINIMUM_SPEED);
    model.Fans().getEachFanSpeedRPM(FanModel::MAXIMUM_SPEED);
    return model.Fans().FansMinMaxSpeed();
}

const char * kStatsController::getMainDeviceName() {
    return model.MainDevice().DeviceName();
}

const char * kStatsController::getOsVersion() {
    return model.MainDevice().OsVersion();
}

const long &kStatsController::getRamSize() {
    return model.Ram().RamSize();
}




