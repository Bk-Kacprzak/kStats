#include "Utils/utils.h"
#include "kStats_model.h"

kStatsModel::kStatsModel() {
    SMC_Init_Connection();
}

kStatsModel::~kStatsModel() {
    SMC_Close_Connection();
}


BatteryModel &kStatsModel::Battery() {
    return _battery;
}

CPU &kStatsModel::Cpu() {
    return _cpu;
}

FanModel &kStatsModel::Fans() {
    return _fans;
}

NetworkModel &kStatsModel::Network() {
    return _network;
}

Peripherals &kStatsModel::Peripherals() {
    return _peripherals;
}

VolumeStorage &kStatsModel::VolumeStorage() {
    return _volumeStorage;
}

GPU &kStatsModel::Gpu() {
    return _gpu;
}

MainDeviceModel &kStatsModel::MainDevice() {
    return _mainDevice;
}


