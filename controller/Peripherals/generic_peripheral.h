#ifndef CPUSTATS_GENERIC_PERIPHERAL_H
#define CPUSTATS_GENERIC_PERIPHERAL_H

#include "../Generic/generic_class.h"
#include "iokit_libraries.h"

class GenericPeripheral {
    std::string _name;
    BluetoothClassOfDevice _deviceType;
public:
    enum  {
        KEYBOARD = 1344,
        MOUSE = 1408,
        HEADPHONES = 2360344,
        SCREEN = 1001
    };
    GenericPeripheral(const std::string& _name, const BluetoothClassOfDevice& _deviceType);
    GenericPeripheral(GenericPeripheral&& _obj) noexcept ;
    GenericPeripheral(const GenericPeripheral& _obj);
    GenericPeripheral& operator=(GenericPeripheral&& _obj);
    ~GenericPeripheral() {}
    const std::string& name() const;
    std::string deviceType() const;
};

#endif //CPUSTATS_GENERIC_PERIPHERAL_H
