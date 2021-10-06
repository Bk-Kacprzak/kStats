#ifndef CPUSTATS_KSTAT_CONTROLLER_H
#define CPUSTATS_KSTAT_CONTROLLER_H

#include "Battery/battery_controller.h"
#include "CPU/cpu_device.h"
#include "Fan/fan_controller.h"
#include "Network/network_controller.h"
#include "Peripherals/peripherals_controller.h"
#include "Peripherals/volume_storage_controller.h"
#include "GPU/gpu_device.h"
class kStat{
    BatteryController _battery;
    CPU _cpu;
    GPU _gpu;
    FanController _fans;
    NetworkController _network;
    Peripherals _peripherals;
    VolumeStorage _volumeStorage;
public:
    kStat();
    ~kStat();

    BatteryController &Battery();
    CPU &Cpu();
    GPU &Gpu();
    FanController &Fans();
    NetworkController &Network();
    Peripherals &Peripherals();
    VolumeStorage &VolumeStorage();
};


#endif //CPUSTATS_KSTAT_CONTROLLER_H

