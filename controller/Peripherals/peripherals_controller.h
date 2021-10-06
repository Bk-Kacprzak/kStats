#ifndef CPUSTATS_PERIPHERALS_CONTROLLER_H
#define CPUSTATS_PERIPHERALS_CONTROLLER_H

#include <iostream>
#include <string>
#include <vector>
#include "generic_peripheral.h"


class Peripherals {
    std::vector<GenericPeripheral> devices;
private:
    void loadBluetoothDevices();
    void loadScreenDevices();
public:
    Peripherals();
    const std::vector<GenericPeripheral> &getDevices() const;
};

#endif //CPUSTATS_PERIPHERALS_CONTROLLER_H




//#include <IOKit/IOKitLib.h>
//#include <Foundation/Foundation.h>
//#include <IOKit/hid/IOHIDLib.h>
//#include <CoreFoundation/CoreFoundation.h>
//#include <IOKit/IOReturn.h>
//#include <IOKit/IOTypes.h>
//#include <IOBluetooth/IOBluetoothUserLib.h>
//#include <IOKit/hid/IOHIDManager.h>
//#include <IOKit/hid/IOHIDDevice.h>
//#include <IOBluetooth/IOBluetoothUtilities.h>
//#include <IOBluetooth/objc/IOBluetoothDevice.h>