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
#include <IOKit/IOTypes.h>
#include <device/device_types.h>

#include "smc.h"
#include "Utils/keys.h"
#include "Utils/utilsConverter.h"
//#include <IOKit/ps/IOPSKeys.h>
//#include <IOKit/ps/IOPowerSources.h>

static io_connect_t conn;

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
    return IOConnectCallStructMethod(conn, index,
                                     inputStructure, structureInputSize,
                                     outputStructure, &structureOutputSize);
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
        throw std::runtime_error("read key failed. dataSize <= 0\n");

    memcpy(val->bytes, outputStructure.bytes, sizeof(outputStructure.bytes));
    return kIOReturnSuccess;
}


kern_return_t SMCWriteKey(SMCVal_t* writeVal)
{
    kern_return_t result;
    SMCKeyData_t  inputStructure;
    SMCKeyData_t  outputStructure;

    SMCVal_t      readVal;

    result = SMCReadKey(writeVal->key, &readVal);
    if (result != kIOReturnSuccess)
        return result;

    if (readVal.dataSize != writeVal->dataSize)
        return kIOReturnError;

    memset(&inputStructure, 0, sizeof(SMCKeyData_t));
    memset(&outputStructure, 0, sizeof(SMCKeyData_t));

    inputStructure.key = Converter::strToUl(writeVal->key, 4, 16);
    inputStructure.data8 = SMC_CMD_WRITE_BYTES;
    inputStructure.keyInfo.dataSize = writeVal->dataSize;
    memcpy(inputStructure.bytes, writeVal->bytes, sizeof(writeVal->bytes));
    result = SMCCall(KERNEL_INDEX_SMC, &inputStructure, &outputStructure);

    if (result != kIOReturnSuccess)
        return result;

    return kIOReturnSuccess;
}
