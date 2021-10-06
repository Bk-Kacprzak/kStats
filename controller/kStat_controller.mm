//
// Created by Bartłomiej Kacprzak on 01/10/2021.
//
#include "Utils/utils.h"
#include "kStat_controller.h"

kStat::kStat() {
    SMC_Init_Connection();
}

kStat::~kStat() {
    SMC_Close_Connection();
}


BatteryController &kStat::Battery() {
    return _battery;
}

CPU &kStat::Cpu() {
    return _cpu;
}

FanController &kStat::Fans() {
    return _fans;
}

NetworkController &kStat::Network() {
    return _network;
}

Peripherals &kStat::Peripherals() {
    return _peripherals;
}

VolumeStorage &kStat::VolumeStorage() {
    return _volumeStorage;
}

GPU &kStat::Gpu() {
    return _gpu;
}


