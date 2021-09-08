#ifndef CPUSTATS_CPU_CONTROLLER_H
#define CPUSTATS_CPU_CONTROLLER_H
//#include "smc.h"

#include <iostream>
#include <array>


//TYPES

#define DATATYPE_FLT "flt "
#define DATATYPE_FPE2 "fpe2"
#define DATATYPE_UINT8 "ui8 "
#define DATATYPE_UINT16 "ui16"
#define DATATYPE_UINT32 "ui32"
#define DATATYPE_SP78 "sp78"
#define DATATYPE_FP88 "fp88"
#define DATATYPE_SP96 "sp96"
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

#define SMC_KEY_CPU_POWER_CORE1 "PC0C"
#define SMC_KEY_CPU_POWER_CORE2 "PC1C"
#define SMC_KEY_CPU_POWER_CORE3 "PC2C"
#define SMC_KEY_CPU_POWER_CORE4 "PC3C"
#define SMC_KEY_CPU_POWER_CORE5 "PC4C"
#define SMC_KEY_CPU_POWER_CORE6 "PC5C"

#define SMC_KEY_CPU_DC_IN "PDTR"
//***FAN
#define SMC_KEY_FAN0_CURRENT_SPEED "F0Ac"
#define SMC_KEY_FAN0_MINIMUM_SPEED "F0Mn"
#define SMC_KEY_FAN0_MAXIMUM_SPEED "F0Mx"

#define SMC_KEY_FAN1_CURRENT_SPEED "F1Ac"
#define SMC_KEY_FAN1_MINIMUM_SPEED "F1Mn"
#define SMC_KEY_FAN1_MAXIMUM_SPEED "F1Mx"


namespace kNet {
    namespace Keys{

        namespace cpu {
            constexpr static char temperature[8][5] = {
                    SMC_KEY_CPU_TEMP_CORE1,
                    SMC_KEY_CPU_TEMP_CORE2,
                    SMC_KEY_CPU_TEMP_CORE3,
                    SMC_KEY_CPU_TEMP_CORE4,
                    SMC_KEY_CPU_TEMP_CORE5,
                    SMC_KEY_CPU_TEMP_CORE6,
                    SMC_KEY_CPU_TEMP_CORE_AVG,
                    SMC_KEY_CPU_TEMP_CORE_PECI
                    };

            constexpr static char power[6][5] = {
                    SMC_KEY_CPU_POWER_CORE1,
                    SMC_KEY_CPU_POWER_CORE2,
                    SMC_KEY_CPU_POWER_CORE3,
                    SMC_KEY_CPU_POWER_CORE4,
                    SMC_KEY_CPU_POWER_CORE5,
                    SMC_KEY_CPU_POWER_CORE6,
            };


        }; //namespace CPU

            enum fan{
                LEFT = 0,
                RIGHT = 3
            };

            constexpr static char fan_speed[6][5] = {
                    SMC_KEY_FAN0_CURRENT_SPEED,
                    SMC_KEY_FAN0_MINIMUM_SPEED,
                    SMC_KEY_FAN0_MAXIMUM_SPEED,
                    SMC_KEY_FAN1_CURRENT_SPEED,
                    SMC_KEY_FAN1_MINIMUM_SPEED,
                    SMC_KEY_FAN1_MAXIMUM_SPEED,
            };



    } //namespace Keys
} //namespace kNET

#endif //CPUSTATS_CPU_CONTROLLER_H
