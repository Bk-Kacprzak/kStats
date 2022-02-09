#ifndef CPUSTATS_KSTAT_CONTROLLER_H
#define CPUSTATS_KSTAT_CONTROLLER_H

#include "Battery/battery_model.h"
#include "CPU/cpu_model.h"
#include "Fan/fan_model.h"
#include "Network/network_model.h"
#include "Peripherals/peripherals_model.h"
#include "Peripherals/volume_storage_model.h"
#include "Main Device/MainDeviceModel.h"
#include "GPU/gpu_device.h"
#include "RAM/ram_model.h"
class kStatsModel {
    BatteryModel _battery;
    CPU _cpu;
    GPU _gpu;
    FanModel _fans;
    NetworkModel _network;
    Peripherals _peripherals;
    VolumeStorage _volumeStorage;
    MainDeviceModel _mainDevice;
    RamModel _ram;

public:
    kStatsModel();
    ~kStatsModel();
    MainDeviceModel &MainDevice();
    BatteryModel &Battery();
    CPU &Cpu();
    GPU &Gpu();
    RamModel &Ram();
    FanModel &Fans();
    NetworkModel &Network();
    Peripherals &Peripherals();
    VolumeStorage &VolumeStorage();
};

#endif //CPUSTATS_KSTAT_CONTROLLER_H