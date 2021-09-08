#ifndef CPUSTATS_SMC_H
#define CPUSTATS_SMC_H
#include <IOKit/IOKitLib.h>

#include <array>
#include <iostream>
#include "cpu_controller.h"
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
#define VERSION "0.01"
#define KERNEL_INDEX_SMC 2


#define SMC_CMD_READ_BYTES 5
#define SMC_CMD_WRITE_BYTES 6
#define SMC_CMD_READ_INDEX 8
#define SMC_CMD_READ_KEYINFO 9
#define SMC_CMD_READ_PLIMIT 11
#define SMC_CMD_READ_VERS 12


//#define DATATYPE_FLT "flt "
//#define DATATYPE_FPE2 "fpe2"
//#define DATATYPE_UINT8 "ui8 "
//#define DATATYPE_UINT16 "ui16"
//#define DATATYPE_UINT32 "ui32"
//#define DATATYPE_SP78 "sp78"

// key values

//***CPU
//TEMPERAURE

#define SMC_KEY_CPU_TEMP_CORE_AVG "TC0P" //AVERAGE
#define SMC_KEY_CPU_TEMP_CORE_PECI "TCXC" //PECI
#define SMC_KEY_CPU_TEMP_CORE1 "TC1C" //CORE 1
#define SMC_KEY_CPU_TEMP_CORE2 "TC2C" //CORE 2
#define SMC_KEY_CPU_TEMP_CORE3 "TC3C" //CORE 3
#define SMC_KEY_CPU_TEMP_CORE4 "TC4C" //CORE 4
#define SMC_KEY_CPU_TEMP_CORE5 "TC5C" //CORE 5
#define SMC_KEY_CPU_TEMP_CORE6 "TC6C" //CORE 6

//***GPU
#define SMC_KEY_GPU_TEMP "TG0P"


//***FAN
#define SMC_KEY_FAN0_CURRENT_SPEED "F0Ac"
#define SMC_KEY_FAN0_MINIMUM_SPEED "F0Mn"
#define SMC_KEY_FAN0_MAXIMUM_SPEED "F0Mx"
#define SMC_KEY_FAN0_MAXIMUM_SPEED "F0Mx"

#define SMC_KEY_FAN1_CURRENT_SPEED "F1Ac"
#define SMC_KEY_FAN1_MINIMUM_SPEED "F1Mn"
#define SMC_KEY_FAN1_MAXIMUM_SPEED "F1Mx"
#define SMC_KEY_FAN1_MAXIMUM_SPEED "F1Mx"

#define SMC_KEY

kern_return_t SMCClose();
kern_return_t SMCOpen(void);
void readAndPrintFanRPMs();
void readAndPrintCpuTemp(int show_title, char scale, int core, char *type = nullptr);
void readAndPrintGpuTemp(int show_title, char scale);
void getFanSpeed(kNet::Keys::fan &&fan);
double getCpuTemp(const char &scale, const int &core, const char* type = nullptr);
double SMCGetPower(const char *&& key);





typedef union data {
    float f;
    char b[4];
} fltUnion;

/***************************************/
typedef struct {
    char major;
    char minor;
    char build;
    char reserved[1];
    UInt16 release;
} SMCKeyData_vers_t;

typedef struct {
    UInt16 version;
    UInt16 length;
    UInt32 cpuPLimit;
    UInt32 gpuPLimit;
    UInt32 memPLimit;
} SMCKeyData_pLimitData_t;

typedef struct {
    UInt32 dataSize;
    UInt32 dataType;
    char dataAttributes;
} SMCKeyData_keyInfo_t;

typedef char SMCBytes_t[32];

typedef struct {
    UInt32 key;
    SMCKeyData_vers_t vers;
    SMCKeyData_pLimitData_t pLimitData;
    SMCKeyData_keyInfo_t keyInfo;
    char result;
    char status;
    char data8;
    UInt32 data32;
    SMCBytes_t bytes;
} SMCKeyData_t;

typedef char UInt32Char_t[5];

typedef struct {
    UInt32Char_t key;
    UInt32 dataSize;
    UInt32Char_t dataType;
    SMCBytes_t bytes;
} SMCVal_t;

// prototypes
double SMCGetTemperature(char*&& key);
kern_return_t SMCSetFanRpm(char* key, int rpm);
int SMCGetFanRpm(char* key);
kern_return_t SMCReadKey(const UInt32Char_t key, SMCVal_t* val);



UInt32 _strtoul(const char* str, int size, int base);

#endif //CPUSTATS_SMC_H
