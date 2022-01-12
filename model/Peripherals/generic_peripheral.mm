
#include "generic_peripheral.h"

GenericPeripheral &GenericPeripheral::operator=(GenericPeripheral &&_obj) {
        if(this != &_obj)  {

            _name = std::move(_obj._name);
            _deviceType = std::move(_obj._deviceType);
        }
        return *this;
}

GenericPeripheral::GenericPeripheral(const GenericPeripheral &_obj) {
    _name = _obj._name;
    _deviceType = _obj._deviceType;
}

GenericPeripheral::GenericPeripheral(const std::string &_name, const BluetoothClassOfDevice &_deviceType)
        : _name(_name), _deviceType(_deviceType) { }

GenericPeripheral::GenericPeripheral(GenericPeripheral &&_obj) noexcept
        : _name(std::move(_obj._name)), _deviceType(std::move(_obj._deviceType))  {
}

const std::string& GenericPeripheral::name() const {
    return _name;
}

const std::string GenericPeripheral::deviceType() const {
    switch(_deviceType) {
        case KEYBOARD:
            return "Keyboard";
            break;
        case HEADPHONES:
            return "Headphones";
            break;
        case MOUSE:
            return "Mouse";
            break;
        case SCREEN:
            return "Monitor";
            break;
        default:
            return "Unknown device type";
            break;
    }
}
