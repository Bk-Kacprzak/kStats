#ifndef CPUSTATS_PERIPHERALS_CONTROLLER_H
#define CPUSTATS_PERIPHERALS_CONTROLLER_H

#include <string>
#include <vector>
#include <iostream>


#include <IOKit/IOKitLib.h>
#include <Foundation/Foundation.h>
#include <IOKit/hid/IOHIDLib.h>
#include <CoreFoundation/CoreFoundation.h>
#include <IOKit/IOReturn.h>
#include <IOKit/IOTypes.h>
#include <IOBluetooth/IOBluetoothUserLib.h>
#include <IOKit/hid/IOHIDManager.h>
#include <IOKit/hid/IOHIDDevice.h>
//#include <IOBluetooth
#include <IOBluetooth/IOBluetoothUtilities.h>
#import <IOBluetooth/objc/IOBluetoothDevice.h>
#include <CoreFoundation/CoreFoundation.h>



struct BluetoothDevice {
    std::string name;
    BluetoothClassOfDevice deviceType;
    BluetoothDevice(const std::string& _name, const BluetoothClassOfDevice& _deviceType) :
            name(_name), deviceType(_deviceType) { }

    BluetoothDevice(BluetoothDevice&& _obj)  noexcept : name(std::move(_obj.name)), deviceType(std::move(_obj.deviceType))  {

    }
    BluetoothDevice(const BluetoothDevice& _obj) {
        name = _obj.name;
        deviceType = _obj.deviceType;
    }

    BluetoothDevice& operator=(BluetoothDevice&& _obj) {
        if(this != &_obj)  {
            name = std::move(_obj.name);
            deviceType = std::move(_obj.deviceType);
        }
        return *this;
    }
};


enum deviceType {
    KEYBOARD = 1344,
    MOUSE = 1408,
    HEADPHONES = 2360344
//2360344 - headphones
//1344 - keyboard
//1408 - mouse
};

class Peripherals {
    std::vector<BluetoothDevice> bluetoothDevices;
    void loadBluetoothDevices();
public:
    Peripherals();
    std::vector<BluetoothDevice> getBluetoothDevices;
};


#endif //CPUSTATS_PERIPHERALS_CONTROLLER_H
