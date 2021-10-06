#ifndef CPUSTATS_SMC_H
#define CPUSTATS_SMC_H

#include <IOKit/IOKitLib.h>
#include <array>
#include <iostream>
#include "Utils/keys.h"

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

/***************************************/

typedef char SMCBytes_t[32];
typedef char UInt32Char_t[5];
typedef char SMC_KEY[5];


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


typedef struct {
    UInt32Char_t key;
    UInt32 dataSize;
    UInt32Char_t dataType;
    SMCBytes_t bytes;
} SMCVal_t;

//controllers
kern_return_t SMCReadKey(std::mutex&, const SMC_KEY key, SMCVal_t* val);
kern_return_t SMCReadKey(const SMC_KEY key, SMCVal_t* val);
kern_return_t SMC_Init_Connection();
kern_return_t SMC_Close_Connection();
kern_return_t SMCWriteKey(SMCVal_t* writeValue);

#endif //CPUSTATS_SMC_H
