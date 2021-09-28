//
// Created by Bartłomiej Kacprzak on 28/09/2021.
//

#include "peripherals_controller.h"

Peripherals::Peripherals() {
    loadBluetoothDevices();
    for(auto &device : bluetoothDevices)
        std::cout<<"Connected device: " << device.name<<std::endl;
}
//2360344 - headphones
//1344 - keyboard
//1408 - mouse

void Peripherals::loadBluetoothDevices() {
    NSArray *paired_devices = [IOBluetoothDevice pairedDevices];
    for(const IOBluetoothDevice *device : paired_devices) {
        if(device.isConnected) {
            std::string device_name = device.name.UTF8String;
            bluetoothDevices.push_back(BluetoothDevice(device.name.UTF8String,device.classOfDevice));
        }
    }
}
