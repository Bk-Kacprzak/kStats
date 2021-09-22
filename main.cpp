#include <stdio.h>
#include <chrono>
#include <thread>
#include "controller/Utils/keys.h"
#include "controller/Utils/utils.h"
#include "controller/cpu_device.h"
#include "controller/fan_controller.h"
#include "controller/battery_controller.h"
#include "controller/network_controller.h"
static double latency;
static double download;
static double upload;

int main(int argc, char* argv[])
{
    SMC_Init_Connection();

    CPU cpu;
    FanController fans;
    GenericDevice test;
    BatteryController battery;
    NetworkController net;
    int i =0 ;
    while(!i) {
        Timer timer;
        std::cout<<"\n\n\n";
        battery.getAllInformation();
        std::this_thread::sleep_for(std::chrono::milliseconds(1000));
        ++i;
    }

    SMC_Close_Connection();
    return 0;
}
