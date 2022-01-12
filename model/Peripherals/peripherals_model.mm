//
// Created by Bartłomiej Kacprzak on 28/09/2021.
//

#include "peripherals_model.h"
Peripherals::Peripherals() {
    loadBluetoothDevices();
    loadScreenDevices();
    for(auto &device : devices)
        std::cout<<"Connected device: " << device.name()<<std::endl;
}

void Peripherals::loadBluetoothDevices() {
    NSArray *paired_devices = [IOBluetoothDevice pairedDevices];
    for(const IOBluetoothDevice *device : paired_devices) {
        std::string deviceName = device.name.UTF8String;
        size_t additionalInfo = deviceName.find("(");
        if(additionalInfo!=std::string::npos)
            deviceName.erase(deviceName.begin()+additionalInfo,deviceName.end());

        if(device.isConnected) {
            devices.emplace_back(deviceName,device.classOfDevice);
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

const std::vector<GenericPeripheral> &Peripherals::Devices() const {
    return devices;
}

std::vector<std::string> Peripherals::deviceNames() {
    std::vector<std::string> names;
    for(const auto& device : devices)
            names.push_back(device.name());

    std::cout<<names.capacity();
    return names;
}

std::vector<std::string> Peripherals::deviceTypes() {
    std::vector<std::string> types;
    for(const auto& device : devices)
        types.push_back(device.deviceType());

    return types;
}
