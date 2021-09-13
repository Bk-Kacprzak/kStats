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
#include "smc.h"
#include "Utils/keys.h"
#include "Utils/utilsConverter.h"

//#include <IOKit/ps/IOPSKeys.h>
//#include <IOKit/ps/IOPowerSources.h>

static io_connect_t conn;
namespace SMC {

}
kern_return_t SMC_Init_Connection ()
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

kern_return_t SMC_Close_Connection()
{
    return IOServiceClose(conn);
}

kern_return_t SMCCall(int index, SMCKeyData_t* inputStructure, SMCKeyData_t* outputStructure)
{
    size_t structureInputSize;
    size_t structureOutputSize;

    structureInputSize = sizeof(SMCKeyData_t);
    structureOutputSize = sizeof(SMCKeyData_t);
#if MAC_OS_X_VERSION_10_0
    kern_return_t result =  IOConnectCallStructMethod(conn, index,
                                     inputStructure, structureInputSize,
                                     outputStructure, &structureOutputSize);

    std::cout<<"Kern result: " << result<<std::endl;
    return result;
#else
    return IOConnectMethodStructureIStructureO(conn, index,
        structureInputSize, /* structureInputSize */
        &structureOutputSize, /* structureOutputSize */
        inputStructure, /* inputStructure */
        outputStructure); /* ouputStructure */
#endif
}

kern_return_t SMCReadKey(std::mutex & mtx, const SMC_KEY key, SMCVal_t* val)
{
    kern_return_t result;
    SMCKeyData_t  inputStructure;
    SMCKeyData_t  outputStructure;
    memset(&inputStructure, 0, sizeof(SMCKeyData_t));
    memset(&outputStructure, 0, sizeof(SMCKeyData_t));
    memset(val, 0, sizeof(SMCVal_t));
    inputStructure.key = Converter::strToUl(key, 4, 16);
    inputStructure.data8 = SMC_CMD_READ_KEYINFO;
    result = SMCCall(KERNEL_INDEX_SMC, &inputStructure, &outputStructure);
    if (result != kIOReturnSuccess)
        return result;
    val->dataSize = outputStructure.keyInfo.dataSize;
    Converter::ulToStr(val->dataType, outputStructure.keyInfo.dataType);

    inputStructure.keyInfo.dataSize = val->dataSize;
    inputStructure.data8 = SMC_CMD_READ_BYTES;

    result = SMCCall(KERNEL_INDEX_SMC, &inputStructure, &outputStructure);
    if (result != kIOReturnSuccess)
        return result;

    memcpy(val->bytes, outputStructure.bytes, sizeof(outputStructure.bytes));
    return kIOReturnSuccess;
}


kern_return_t SMCReadKey(const SMC_KEY key, SMCVal_t* val)
{
    kern_return_t result;
    SMCKeyData_t  inputStructure;
    SMCKeyData_t  outputStructure;
    memset(&inputStructure, 0, sizeof(SMCKeyData_t));
    memset(&outputStructure, 0, sizeof(SMCKeyData_t));
    memset(val, 0, sizeof(SMCVal_t));
    inputStructure.key = Converter::strToUl(key, 4, 16);
    inputStructure.data8 = SMC_CMD_READ_KEYINFO;
    result = SMCCall(KERNEL_INDEX_SMC, &inputStructure, &outputStructure);
    if (result != kIOReturnSuccess)
        return result;
    val->dataSize = outputStructure.keyInfo.dataSize;
    Converter::ulToStr(val->dataType, outputStructure.keyInfo.dataType);

    inputStructure.keyInfo.dataSize = val->dataSize;
    inputStructure.data8 = SMC_CMD_READ_BYTES;

    result = SMCCall(KERNEL_INDEX_SMC, &inputStructure, &outputStructure);
    if (result != kIOReturnSuccess)
        return result;
    if(val->dataSize <= 0)
        std::cout<<"INVALID\n";

    memcpy(val->bytes, outputStructure.bytes, sizeof(outputStructure.bytes));
    return kIOReturnSuccess;
}

//
//kern_return_t SMCWriteKey(SMCVal_t *writeVal) {
//    kern_return_t result;
//    SMCKeyData_t inputStruct;
//    SMCKeyData_t outputStruct;
//
//    memset(&inputStruct,  0, sizeof(SMCKeyData_t));
//    memset(&outputStruct, 0, sizeof(SMCKeyData_t));
//
//    // First call to AppleSMC - get key info
//    inputStruct.key = Converter::strToUl(writeVal->key, 4, 16);
//    inputStruct.data8 = SMC_CMD_READ_KEYINFO;
//
//    result = SMCCall(KERNEL_INDEX_SMC, &inputStruct, &outputStruct);
//    if (result != kIOReturnSuccess) {
//        return result;
//    }
//
//
//    // Check data is correct
//    if (writeVal->dataSize != outputStruct.keyInfo.dataSize ||
//        Converter::strToUl(writeVal->dataType,4, 16) != outputStruct.keyInfo.dataType) {
//        return kIOReturnBadArgument;
//    }
//
//    // Second call to AppleSMC - now we can write the data
//    inputStruct.data8 = SMC_CMD_WRITE_BYTES;
//    inputStruct.keyInfo.dataSize = outputStruct.keyInfo.dataSize;
//    // Set data to write
//    memcpy(inputStruct.bytes, writeVal->bytes, sizeof(writeVal->bytes));
//    std::cout<<"BYTES: "<<inputStruct.bytes<<std::endl;
//    result = SMCCall(KERNEL_INDEX_SMC, &inputStruct, &outputStruct);
////    result_smc->kSMC = outputStruct.result;
//    if(result != kIOReturnSuccess)
//        std::cout<<"SMC Call errror\n";
//    return result;
//
//}

////
kern_return_t SMCWriteKey(SMCVal_t writeVal)
{
    kern_return_t result;
    SMCKeyData_t  inputStructure;
    SMCKeyData_t  outputStructure;

//
//    SMCVal_t      readVal;
//    result = SMCReadKey(writeVal->key, &readVal);
//    if (result != kIOReturnSuccess)
//        return result;
//
//    if (readVal.dataSize != writeVal->dataSize)
        //        return kIOReturnError;
//        writeVal->dataSize = readVal.dataSize;
    memset(&inputStructure, 0, sizeof(SMCKeyData_t));
    memset(&outputStructure, 0, sizeof(SMCKeyData_t));

    inputStructure.key = Converter::strToUl(writeVal.key, 4, 16);
    inputStructure.data8 = SMC_CMD_WRITE_BYTES;
    inputStructure.keyInfo.dataSize = writeVal.dataSize;
    memcpy(inputStructure.bytes, writeVal.bytes, sizeof(writeVal.bytes));

    result = SMCCall(KERNEL_INDEX_SMC, &inputStructure, &outputStructure);
    if (result != kIOReturnSuccess){
        std::cout<<"SMC Call error\n";
        return result;
    }

    return kIOReturnSuccess;
}


kern_return_t SMCWriteKey(SMCVal_t* writeVal)
{
    kern_return_t result;
    SMCKeyData_t  inputStructure;
    SMCKeyData_t  outputStructure;

//
//    SMCVal_t      readVal;
//    result = SMCReadKey(writeVal->key, &readVal);
//    if (result != kIOReturnSuccess)
//        return result;
//
//    if (readVal.dataSize != writeVal->dataSize)
    //        return kIOReturnError;
//        writeVal->dataSize = readVal.dataSize;
    memset(&inputStructure, 0, sizeof(SMCKeyData_t));
    memset(&outputStructure, 0, sizeof(SMCKeyData_t));

    inputStructure.key = Converter::strToUl(writeVal->key, 4, 16);
    inputStructure.data8 = SMC_CMD_WRITE_BYTES;
    inputStructure.keyInfo.dataSize = writeVal->dataSize;
    memcpy(inputStructure.bytes, writeVal->bytes, sizeof(writeVal->bytes));

    result = SMCCall(KERNEL_INDEX_SMC, &inputStructure, &outputStructure);
    if (result != kIOReturnSuccess){
        std::cout<<"SMC Call error\n";
        return result;
    }

    return kIOReturnSuccess;
}
//kern_return_t SMCWriteKey(SMCVal_t *writeVal)
//{
//    kern_return_t result;
//    SMCKeyData_t inputStructure;
//    SMCKeyData_t outputStructure;
//
//    SMCVal_t readVal;
//
//
//    result = SMCReadKey(writeVal->key, &readVal);
//    if (result != kIOReturnSuccess){
//        std::cout<<"SMCReadKey error\n";
//        return result;
//    }
//
//    writeVal->dataSize = readVal.dataSize;
//    memcpy(writeVal->dataType, readVal.dataType, sizeof(SMCVal_t::dataType));
//
//    if (readVal.dataSize != writeVal->dataSize){
//        std::cout<<"Datasize error\n";
//        return kIOReturnError;
//    }
//
//    memset(&inputStructure, 0, sizeof(SMCKeyData_t));
//    memset(&outputStructure, 0, sizeof(SMCKeyData_t));
//
//
//    inputStructure.data8 = SMC_CMD_WRITE_BYTES;
//    inputStructure.key = Converter::strToUl(writeVal->key, 4, 16);
//    inputStructure.keyInfo.dataSize = writeVal->dataSize;
//    inputStructure.keyInfo.dataType = Converter::strToUl(writeVal->dataType, 4, 16);
//    memcpy(inputStructure.bytes, writeVal->bytes, 32);
//    result = SMCCall(KERNEL_INDEX_SMC,&inputStructure,&outputStructure);
//
//    if (result != kIOReturnSuccess) {
//        std::cout<<"SMCCall error\n";
//            return result;
//        }
//        return kIOReturnSuccess;
//}


//double SMCGetPower(const char *&& key) {
//}
//*******************************************
// Fan
//float SMCGetFanRPM(char* key)
//{
//    SMCVal_t val;
//    kern_return_t result;
//
//    result = SMCReadKey(key, &val);
//    if (result == kIOReturnSuccess) {
//        // read succeeded - check returned value
//        if (val.dataSize > 0) {
////            std::cout<<"val.dataSize: " << val.dataSize<<std::endl;
////            uint8_t
//            if (strcmp(val.dataType, DATATYPE_FLT) == 0) {
//                // convert fpe2 value to RPM
//                return ntohs(*(UInt16*)val.bytes) / 4.0;
//            }
//        }
//    }
//    // read failed
//    return -1.f;
//}


//double SMCGetFanSpeed(const char*&& key)
//{
//    SMCVal_t val;
//    kern_return_t result;
//    result = SMCReadKey(key, &val);
//    if (result == kIOReturnSuccess) {
//        // read succeeded - check returned value
//        if (val.dataSize > 0) {
//            if (strcmp(val.dataType, DATATYPE_FPE2) == 0) {
//                // convert fpe2 value to rpm
//                int intValue = (unsigned char)val.bytes[0] * 256 + (unsigned char)val.bytes[1];
//                return intValue / 4.0;
//            }
//            //T2 CHIP
//            if (strcmp(val.dataType, DATATYPE_FLT) == 0) {
//                float speed = Converter::fltToFloat((unsigned char*) val.bytes);
//                return speed;
//            }
//        }
//    }
//
//    // read failed
//    return -1.0;
//}

//****************************************
// printers

// Requires SMCOpen()
//void readAndPrintFanRPMs(void) {
//    kern_return_t result;
//    SMCVal_t val;
//    UInt32Char_t key;
//    int totalFans, i;
//
//    result = SMCReadKey("FNum", &val);
//
//    if (result == kIOReturnSuccess) {
//        totalFans = _strtoul((char*)val.bytes, val.dataSize, 10);
//
////        printf("Num fans: %d\n", totalFans);
//        for (i = 0; i < totalFans; i++) {
//            sprintf(key, "F%dID", i);
//            result = SMCReadKey(key, &val);
//            std::cout<<val.bytes<<std::endl;
//            if (result != kIOReturnSuccess) {
//                continue;
//            }
//
//            sprintf(key, "F%dAc",i);
//            float actual_speed = SMCGetFanSpeed(key);
//            if (actual_speed < 0.f) {
//                continue;
//            }
//
//            sprintf(key, "F%dMn", i);
//            float minimum_speed = SMCGetFanSpeed(key);
//            if (minimum_speed < 0.f) {
//                continue;
//            }
//
//            sprintf(key, "F%dMx", i);
//            float maximum_speed = SMCGetFanSpeed(key);
//            if (maximum_speed < 0.f) {
//                continue;
//            }
//
//            float rpm = actual_speed - minimum_speed;
//
//            std::cout<<"*************Fan " << i+1 << " actual speed: "<< actual_speed<<"*************"<<std::endl;
//            std::cout<<"Fan " << i+1 << " minimum speed: "<< minimum_speed<<std::endl;
//            std::cout<<"Fan " << i+1 << " maximum speed: "<< maximum_speed<<std::endl;
//
//        }
//    }
//}
//
//void readAndPrintCpuTemp(int show_title, char scale, int core, char* type)
//{
//    double temperature = SMCGetTemperature(kNet::Keys::cpu::temperature[core]);
//    if (scale == 'F') {
//        temperature = Converter::convertToFahrenheit(temperature);
//    }
//
//    char* title = "";
//    if (show_title) {
//        title = "CPU Core ";
//    }
//
//    if(type)
//        std::cout<<title<<type<<": "<<temperature<<" "<<scale<<std::endl;
//    else
//    std::cout<<title<<core<<" temperature: "<<temperature<<" "<<scale<<std::endl;
//}
//double getCpuTemp(const char &scale, const int &core, const char* type) {
//    double temperature = SMCGetTemperature(kNet::Keys::cpu::power[core]);
//    if (scale == 'F') {
//        temperature = Converter::convertToFahrenheit(temperature);
//    }
//
//    if(type)
//        std::cout<<"CPU Core "<<type<<": "<<temperature<<" "<<scale<<std::endl;
//    else
//        std::cout<<"CPU Core "<<core<<" temperature: "<<temperature<<" "<<scale<<std::endl;
//}
//
//// Requires SMCOpen()
//void readAndPrintGpuTemp(int show_title, char scale)
//{
//    double temperature = SMCGetTemperature(SMC_KEY_GPU_TEMP);
//    if (scale == 'F') {
//        temperature = Converter::convertToFahrenheit(temperature);
//    }
//
//    char* title = "";
//    if (show_title) {
//        title = "GPU: ";
//    }
//    printf("%s%0.1f °%c\n", title, temperature, scale);
//}
//
//void getFanSpeed(kNet::Keys::fan &&fan) {
//    using namespace kNet::Keys;
//    kern_return_t result;
//    SMCVal_t val;
//    UInt32Char_t key;
//    int totalFans;
//
//    result = SMCReadKey("FNum", &val);
//    float actual_speed, minimum_speed, maximum_speed, rpm;
//    ushort index = fan;
//    actual_speed = SMCGetFanSpeed(fan_speed[index++]);
//    minimum_speed = SMCGetFanSpeed(fan_speed[index++]);
//    maximum_speed = SMCGetFanSpeed(fan_speed[index]);
//
//    rpm = actual_speed - minimum_speed;
//    std::string fan_name;
//    if(fan == fan::LEFT)
//        fan_name = "left";
//    else
//        fan_name = "right";
//
//    std::cout<<"*************Fan " << fan_name<< " actual speed: "<< actual_speed<<"*************"<<std::endl;
//    std::cout<<"Fan " << fan_name << " minimum speed: "<< minimum_speed<<std::endl;
//    std::cout<<"Fan " << fan_name << " maximum speed: "<< maximum_speed<<std::endl;
//}
//
//
//
//uint32_t stringToKey(const char*str) {
//    uint32_t tmp[2];
//    strncpy((char*)&tmp, str, 4);
//    std::cout<<*tmp<<std::endl;      // This is necessary because a char* might not be 4 byte aligned.
//    return ntohl(tmp[0]);
//}
//
//double SMCGetTemperature(const char *&& key)
//{
//    SMCVal_t val;
//    kern_return_t result;
//
//    result = SMCReadKey(key, &val);
//    if (result == kIOReturnSuccess) {
////         read succeeded - check returned value
//        if (val.dataSize > 0) {
//            if (strcmp(val.dataType, DATATYPE_SP78) == 0) {
////                 convert sp78 value to temperature
//                int intValue = val.bytes[0] * 256 + (unsigned char)val.bytes[1];
//                return intValue / 256.0;
//            }
//        }
//    }
////     read failed
//    return 0.0;
//}