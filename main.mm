#include <cstdio>
#include <chrono>
#include <thread>
#include "controller/Utils/utils.h"
#include "controller/cpu_device.h"
#include "controller/fan_controller.h"
#include "controller/battery_controller.h"
#include "controller/network_controller.h"
#include <IOKit/IOKitLib.h>
#include <CoreFoundation/CoreFoundation.h>
#include "controller/peripherals_controller.h"
#include "controller/volume_storage_controller.h"
int main(int argc, char* argv[])
{
    SMC_Init_Connection();
    Peripherals devices;
    VolumeStorage ssd;

//    FanController fans;
//    GenericDevice test;
//    BatteryController battery;
//    CPU cpu;
//    while(1) {
//        std::cout<<"\n";
//        cpu.getEachCoreTemperature();
//        std::this_thread::sleep_for(std::chrono::milliseconds(1000));
//    }
//    system_profiler -listDataTypes
//IOKitPersonalities
//    int i =0;
//    while(!i) {
//        Timer timer;
//        std::cout<<"\n\n\n";
//        battery.getAllInformation();
//        ++i;
//    }
    SMC_Close_Connection();
    return 0;
}
