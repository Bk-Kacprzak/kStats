//
// Created by Bartłomiej Kacprzak on 28/09/2021.
//

#include "peripherals_controller.h"
Peripherals::Peripherals() {
    loadBluetoothDevices();
    loadScreenDevices();
    for(auto &device : devices)
        std::cout<<"Connected device: " << device.name()<<std::endl;
}

void Peripherals::loadBluetoothDevices() {
    NSArray *paired_devices = [IOBluetoothDevice pairedDevices];
    for(const IOBluetoothDevice *device : paired_devices) {
        if(device.isConnected) {
            devices.emplace_back(device.name.UTF8String,device.classOfDevice);
        }
    }
}

void Peripherals::loadScreenDevices() {
    NSArray<NSScreen *> *screens = [NSScreen screens];
    for(const NSScreen * screen : screens) {
        std::string screen_name = screen.localizedName.UTF8String;
        size_t found = screen_name.find("Built-in"); //ignore built in screen
        if(found==std::string::npos)
            devices.emplace_back(screen_name, GenericPeripheral::SCREEN);
    }
}

const std::vector<GenericPeripheral> &Peripherals::getDevices() const {
    return devices;
}
