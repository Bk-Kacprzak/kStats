#include "generic_device.h"

GenericDevice::kernReturnValue GenericDevice::readKey() {
        SMCVal_t val;
        kern_return_t result;
        result = SMCReadKey(currentKey, &val);
        kernReturnValue value;

    if (result == kIOReturnSuccess) {
            // read succeeded - check returned value
            if (val.dataSize > 0) {
                if (strcmp(val.dataType, DATATYPE_FPE2) == 0) {
                    // convert fpe2 value to int
                    value.i = Converter::fpe2ToInteger(val.bytes);
                    return value;
                }
                else if (strcmp(val.dataType, DATATYPE_FLT) == 0) {
                    // convert flt value to float
                    value.f = Converter::fltToFloat((unsigned char*) val.bytes);
                    return value;
                }
                else if (strcmp(val.dataType, DATATYPE_SP78) == 0) {
                    // convert sp78 value
                    value.i = Converter::sp78ToInteger(val.bytes);
                    value.i /= 4.0;
                    return value;
                }
                else if(strcmp(val.dataType, DATATYPE_UINT16) == 0) {
                    value.i = abs(Converter::ui16ToInteger((unsigned char *)val.bytes));
                    return value;
                }

            }
        }
        // read failed
        value.i = -1.0;
        return value;
}

bool GenericDevice::writeKey() {
    return false;
}



