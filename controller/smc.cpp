/*
 * Apple System Management Control (SMC) Tool
 * Copyright (C) 2006 devnull
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.
 */

#include <IOKit/IOKitLib.h>
#include <stdio.h>
#include <string.h>
#include "smc.h"
#include "cpu_controller.h"
#include <IOKit/ps/IOPSKeys.h>
#include <IOKit/ps/IOPowerSources.h>

static io_connect_t conn;

//*******************************************
// converters
UInt32 _strtoul(const char* str, int size, int base)
{
    UInt32 total = 0;
    int i;

    for (i = 0; i < size; i++) {
        if (base == 16)
            total += str[i] << (size - 1 - i) * 8;
        else
            total += (unsigned char)(str[i] << (size - 1 - i) * 8);
    }
    return total;
}

void _ultostr(char* str, UInt32 val)
{
    str[0] = '\0';
    sprintf(str, "%c%c%c%c",
            (unsigned int)val >> 24,
            (unsigned int)val >> 16,
            (unsigned int)val >> 8,
            (unsigned int)val);

}

float _fltToFloat(unsigned char *str) {
    fltUnion flt;
    flt.b[0] = str[0];
    flt.b[1] = str[1];
    flt.b[2] = str[2];
    flt.b[3] = str[3];

    return flt.f;
}

double convertToFahrenheit(double celsius)
{
    return (celsius * (9.0 / 5.0)) + 32.0;
}

//*******************************************
//SMC functions

kern_return_t SMCOpen(void)
{
    kern_return_t result;
    io_iterator_t iterator;
    io_object_t device;

    CFMutableDictionaryRef matchingDictionary = IOServiceMatching("AppleSMC");
    result = IOServiceGetMatchingServices(kIOMasterPortDefault, matchingDictionary, &iterator);
    if (result != kIOReturnSuccess) {
        printf("Error: IOServiceGetMatchingServices() = %08x\n", result);
        return 1;
    }

    device = IOIteratorNext(iterator);
    IOObjectRelease(iterator);
    if (device == 0) {
        printf("Error: no SMC found\n");
        return 1;
    }

    result = IOServiceOpen(device, mach_task_self(), 0, &conn);
    IOObjectRelease(device);
    if (result != kIOReturnSuccess) {
        printf("Error: IOServiceOpen() = %08x\n", result);
        return 1;
    }

    return kIOReturnSuccess;
}

kern_return_t SMCClose()
{
    return IOServiceClose(conn);
}

kern_return_t SMCCall(int index, SMCKeyData_t* inputStructure, SMCKeyData_t* outputStructure)
{
    size_t structureInputSize;
    size_t structureOutputSize;

    structureInputSize = sizeof(SMCKeyData_t);
    structureOutputSize = sizeof(SMCKeyData_t);
#if MAC_OS_X_VERSION_10_5
    return IOConnectCallStructMethod(conn, index,
            // inputStructure
                                     inputStructure, structureInputSize,
            // ouputStructure
                                     outputStructure, &structureOutputSize);
#else
    return IOConnectMethodStructureIStructureO(conn, index,
        structureInputSize, /* structureInputSize */
        &structureOutputSize, /* structureOutputSize */
        inputStructure, /* inputStructure */
        outputStructure); /* ouputStructure */
#endif
}
uint32_t stringToKey(const char*str) {
    uint32_t tmp[2];
    strncpy((char*)&tmp, str, 4);
    std::cout<<*tmp<<std::endl;      // This is necessary because a char* might not be 4 byte aligned.
    return ntohl(tmp[0]);
}
kern_return_t SMCReadKey(const UInt32Char_t key, SMCVal_t* val)
{
    kern_return_t result;
    SMCKeyData_t  inputStructure;
    SMCKeyData_t  outputStructure;

    memset(&inputStructure, 0, sizeof(SMCKeyData_t));
    memset(&outputStructure, 0, sizeof(SMCKeyData_t));
    memset(val, 0, sizeof(SMCVal_t));
    inputStructure.key = _strtoul(key, 4, 16);
    inputStructure.data8 = SMC_CMD_READ_KEYINFO;

    result = SMCCall(KERNEL_INDEX_SMC, &inputStructure, &outputStructure);
    if (result != kIOReturnSuccess)
        return result;

    val->dataSize = outputStructure.keyInfo.dataSize;
    _ultostr(val->dataType, outputStructure.keyInfo.dataType);

    inputStructure.keyInfo.dataSize = val->dataSize;
    inputStructure.data8 = SMC_CMD_READ_BYTES;

    result = SMCCall(KERNEL_INDEX_SMC, &inputStructure, &outputStructure);
    if (result != kIOReturnSuccess)
        return result;

    memcpy(val->bytes, outputStructure.bytes, sizeof(outputStructure.bytes));
    return kIOReturnSuccess;
}

//*******************************************
// Properties functions
// Temperature
double SMCGetTemperature(const char *&& key)
{
    SMCVal_t val;
    kern_return_t result;

    result = SMCReadKey(key, &val);
    if (result == kIOReturnSuccess) {
        // read succeeded - check returned value
        if (val.dataSize > 0) {
            if (strcmp(val.dataType, DATATYPE_SP78) == 0) {
                // convert sp78 value to temperature
                int intValue = val.bytes[0] * 256 + (unsigned char)val.bytes[1];
                return intValue / 256.0;
            }
        }
    }
    // read failed
    return 0.0;
}

typedef union uint16_data {
    int16_t i;
    char b[2];
} uint16Union;

int  _uint16ToInteger(unsigned char* str) {
    uint16Union integer;
    integer.b[0] = str[0];
    integer.b[1] = str[1];
    return abs(integer.i);
}

typedef union test {
    UInt32 x;
    char b[4];
} testUnion;
int ui32ToInt(const unsigned char *str)   {
    testUnion a;
    a.b[0] = str[0];
    a.b[1] = str[1];
    a.b[2] = str[2];
    a.b[3] = str[3];
    return a.x;
}
double SMCGetPower(const char *&& key) {
    SMCVal_t val;
    kern_return_t result;

    result = SMCReadKey(key, &val);
    if(result == kIOReturnSuccess) {
        if(val.dataSize > 0) {
            if(strcmp(val.dataType, DATATYPE_UINT16) == 0) {
                std::cout<<val.dataType<<std::endl;
                float x = (unsigned char)val.bytes[0] * 256 + (unsigned char)val.bytes[1];
                x/=1000;
                int y = _uint16ToInteger((unsigned char*) val.bytes);
                y/=1000;

                std::cout<< x<< "\t"<< y <<std::endl;
            } else if (strcmp(val.dataType, DATATYPE_SP96) == 0) {
                float value = val.bytes[0] << 8 | val.bytes[1];
                std::cout<<"value: "<<value<<std::endl;

            }
            else if (strcmp(val.dataType, DATATYPE_FLT) == 0){

                float power = _fltToFloat((unsigned char*) val.bytes);
                std::cout<<power<<" W"<<std::endl;
            }else if(strcmp(val.dataType, DATATYPE_UINT32) ==0 ) {
                int i = ((unsigned char)val.bytes[0] << 24) | ((unsigned char) val.bytes[1] << 16) | ((unsigned char) val.bytes[2] << 8) | ((unsigned char) val.bytes[3]);
                std::cout<<i<<std::endl;

            }
        } else std::cout<<"size < 0\n";
    }

    return -1.0;
}
//*******************************************
// Fan
float SMCGetFanRPM(char* key)
{
    SMCVal_t val;
    kern_return_t result;

    result = SMCReadKey(key, &val);
    if (result == kIOReturnSuccess) {
        // read succeeded - check returned value
        if (val.dataSize > 0) {
//            std::cout<<"val.dataSize: " << val.dataSize<<std::endl;
//            uint8_t
            if (strcmp(val.dataType, DATATYPE_FLT) == 0) {
                // convert fpe2 value to RPM
                return ntohs(*(UInt16*)val.bytes) / 4.0;
            }
        }
    }
    // read failed
    return -1.f;
}


double SMCGetFanSpeed(const char*&& key)
{
    SMCVal_t val;
    kern_return_t result;
    result = SMCReadKey(key, &val);
    if (result == kIOReturnSuccess) {
        // read succeeded - check returned value
        if (val.dataSize > 0) {
            if (strcmp(val.dataType, DATATYPE_FPE2) == 0) {
                // convert fpe2 value to rpm
                int intValue = (unsigned char)val.bytes[0] * 256 + (unsigned char)val.bytes[1];
                return intValue / 4.0;
            }
            //T2 CHIP
            if (strcmp(val.dataType, DATATYPE_FLT) == 0) {
                float speed = _fltToFloat((unsigned char*) val.bytes);
                return speed;
            }
        }
    }

    // read failed
    return -1.0;
}

//****************************************
// printers

// Requires SMCOpen()
void readAndPrintFanRPMs(void) {
    kern_return_t result;
    SMCVal_t val;
    UInt32Char_t key;
    int totalFans, i;

    result = SMCReadKey("FNum", &val);

    if (result == kIOReturnSuccess) {
        totalFans = _strtoul((char*)val.bytes, val.dataSize, 10);

//        printf("Num fans: %d\n", totalFans);
        for (i = 0; i < totalFans; i++) {
            sprintf(key, "F%dID", i);
            result = SMCReadKey(key, &val);
            std::cout<<val.bytes<<std::endl;
            if (result != kIOReturnSuccess) {
                continue;
            }

            sprintf(key, "F%dAc",i);
            float actual_speed = SMCGetFanSpeed(key);
            if (actual_speed < 0.f) {
                continue;
            }

            sprintf(key, "F%dMn", i);
            float minimum_speed = SMCGetFanSpeed(key);
            if (minimum_speed < 0.f) {
                continue;
            }

            sprintf(key, "F%dMx", i);
            float maximum_speed = SMCGetFanSpeed(key);
            if (maximum_speed < 0.f) {
                continue;
            }

            float rpm = actual_speed - minimum_speed;

            std::cout<<"*************Fan " << i+1 << " actual speed: "<< actual_speed<<"*************"<<std::endl;
            std::cout<<"Fan " << i+1 << " minimum speed: "<< minimum_speed<<std::endl;
            std::cout<<"Fan " << i+1 << " maximum speed: "<< maximum_speed<<std::endl;

        }
    }
}

void readAndPrintCpuTemp(int show_title, char scale, int core, char* type)
{
    double temperature = SMCGetTemperature(kNet::Keys::cpu::temperature[core]);
    if (scale == 'F') {
        temperature = convertToFahrenheit(temperature);
    }

    char* title = "";
    if (show_title) {
        title = "CPU Core ";
    }

    if(type)
        std::cout<<title<<type<<": "<<temperature<<" "<<scale<<std::endl;
    else
    std::cout<<title<<core<<" temperature: "<<temperature<<" "<<scale<<std::endl;
}
double getCpuTemp(const char &scale, const int &core, const char* type) {
    double temperature = SMCGetTemperature(kNet::Keys::cpu::power[core]);
    if (scale == 'F') {
        temperature = convertToFahrenheit(temperature);
    }

    if(type)
        std::cout<<"CPU Core "<<type<<": "<<temperature<<" "<<scale<<std::endl;
    else
        std::cout<<"CPU Core "<<core<<" temperature: "<<temperature<<" "<<scale<<std::endl;
}

// Requires SMCOpen()
void readAndPrintGpuTemp(int show_title, char scale)
{
    double temperature = SMCGetTemperature(SMC_KEY_GPU_TEMP);
    if (scale == 'F') {
        temperature = convertToFahrenheit(temperature);
    }

    char* title = "";
    if (show_title) {
        title = "GPU: ";
    }
    printf("%s%0.1f °%c\n", title, temperature, scale);
}

void getFanSpeed(kNet::Keys::fan &&fan) {
    using namespace kNet::Keys;
    kern_return_t result;
    SMCVal_t val;
    UInt32Char_t key;
    int totalFans;

    result = SMCReadKey("FNum", &val);
    float actual_speed, minimum_speed, maximum_speed, rpm;
    ushort index = fan;
    actual_speed = SMCGetFanSpeed(fan_speed[index++]);
    minimum_speed = SMCGetFanSpeed(fan_speed[index++]);
    maximum_speed = SMCGetFanSpeed(fan_speed[index]);

    rpm = actual_speed - minimum_speed;
    std::string fan_name;
    if(fan == fan::LEFT)
        fan_name = "left";
    else
        fan_name = "right";

    std::cout<<"*************Fan " << fan_name<< " actual speed: "<< actual_speed<<"*************"<<std::endl;
    std::cout<<"Fan " << fan_name << " minimum speed: "<< minimum_speed<<std::endl;
    std::cout<<"Fan " << fan_name << " maximum speed: "<< maximum_speed<<std::endl;
}
