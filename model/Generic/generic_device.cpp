#include "generic_device.h"


GenericDevice::GenericDevice() {

}

GenericDevice::kernReturnValue GenericDevice::readKey(std::mutex& mtx, const char* key) {
    SMCVal_t val;
    kern_return_t result;
    result = SMCReadKey(mtx,key, &val);

    kernReturnValue value;
    if (result == kIOReturnSuccess) {
        // read succeeded - check returned value
        if (val.dataSize > 0) {
            if (strcmp(val.dataType, DATATYPE_FPE2) == 0) {
                // convert fpe2 value to int
                value.i = Converter::fpe2ToInteger(val.bytes);
                return value;
            }
            else if (strcmp(val.dataType, DATATYPE_SP78) == 0) {
                // convert sp78 value
                value.i = Converter::sp78ToInteger(val.bytes);
//                    value.i /= 4.0;
                return value;
            }
            else if (strcmp(val.dataType, DATATYPE_FLT) == 0) {
                // convert flt value to float
                value.f = Converter::fltToFloat((unsigned char*) val.bytes);
                std::cout<<"Value: " <<value.f << std::endl;
                return value;
            }
            else if(strcmp(val.dataType, DATATYPE_UINT16) == 0) {
                value.i = abs(Converter::ui16ToInteger((unsigned char *)val.bytes));
                return value;
            } else if (strcmp(val.dataType, DATATYPE_SP96) == 0) {
                value.f = val.bytes[0] << 8 | val.bytes[1];
                return value;
            } else if(strcmp(val.dataType, DATATYPE_UINT32) == 0) {

                value.i = Converter::ui32ToInteger(val.bytes);
                std::cout<<"HERE: "<<value.i<<std::endl;
                return value;
            } else {
                throw std::invalid_argument("Unknown type.\n");
            }
        } else
            throw std::invalid_argument("Unknown SMC Key.\n");
    } else
        throw std::invalid_argument("SMC Key read failed.\n");

    // read failed
    value.i = -1.0;
    return value;
}

void GenericDevice::writeKey(std::mutex &mtx, SMCVal_t *writeValue) {
    kern_return_t result = SMCWriteKey(writeValue);
    if(result == kIOReturnSuccess)
        std::cout<<"SUCCESS\n";
    else
        std::cout<<"SHit happens\n";

}

void GenericDevice::writeKey(SMCVal_t *writeValue) {
    kern_return_t result = SMCWriteKey(writeValue);
    if(result == kIOReturnSuccess)
        std::cout<<"Value set to key: "<<writeValue->key<<std::endl;
    else
        std::cout<<"writeKey Error\n";
}


GenericDevice::kernReturnValue GenericDevice::readKey(const char *key) {
    SMCVal_t val;
    kern_return_t result;
    result = SMCReadKey(key, &val);

    kernReturnValue value;
    if (result == kIOReturnSuccess) {
        // read succeeded - check returned value
        if (val.dataSize > 0) {
            if (strcmp(val.dataType, DATATYPE_FPE2) == 0) {
                value.i = Converter::fpe2ToInteger(val.bytes);
                return value;
            }
            else if (strcmp(val.dataType, DATATYPE_SP78) == 0) {
                value.i = Converter::sp78ToInteger(val.bytes);
                return value;
            }
            else if (strcmp(val.dataType, DATATYPE_FLT) == 0) {
                value.f = Converter::fltToFloat((unsigned char*) val.bytes);
                return value;
            }
            else if(strcmp(val.dataType, DATATYPE_UINT16) == 0) {
                value.i = Converter::ui16ToInteger((unsigned char *)val.bytes);

                return value;
            } else if (strcmp(val.dataType, DATATYPE_SINT16) == 0) {
                value.i = Converter::si16ToInteger(val.bytes);
                return value;
            } else if (strcmp(val.dataType, DATATYPE_SP96) == 0) {
                value.f = val.bytes[0] << 8 | val.bytes[1];
                return value;
            } else if(strcmp(val.dataType, DATATYPE_UINT32) == 0) {

                value.i = Converter::ui32ToInteger(val.bytes);
                std::cout<<"HERE: "<<value.i<<std::endl;
                return value;
            } else if (strcmp(val.dataType, DATATYPE_CH8) == 0) {
                std::cout<<"BYTES: " << val.bytes<<std::endl;
            } else if (strcmp(val.dataType, DATATYPE_UINT8) == 0) {
                std::cout<<"BYTES: " << (int)val.bytes[0]<<std::endl;
            }else if (strcmp(val.dataType, DATATYPE_HEX) == 0) {
                std::cout<<"BYTES: " << val.bytes<<std::endl;
            }
            else {
                const char* error_msg= ("Unknown type: %s\n",val.dataType);
                throw std::invalid_argument(error_msg);
            }
        }
        else
        {
            const char * error_msg = ("Unknown SMC Key: %s\n", val.key);
            throw std::invalid_argument(error_msg);
        }
    } else
        throw std::runtime_error("SMC Key read failed. kIOReturnSuccess = false\n");

}

void GenericDevice::writeKey(const char *key, const SMCBytes_t value) {
    SMCVal_t writeVal;
    strncpy(writeVal.key, key, 5);
    for(int i =0 ; i< 32; i++)
        writeVal.bytes[i] = value[i];
    strncpy(writeVal.dataType, DATATYPE_CH8, 32);
    writeVal.dataSize = 4;

    kern_return_t result = SMCWriteKey(&writeVal);
    if(result == kIOReturnSuccess)
        std::cout<<"SUCCESS\n";
    else
        std::cout<<"kIOReturnSuccess returns false\n";

}



