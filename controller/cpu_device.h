#ifndef CPUSTATS_CPU_DEVICE_H
#define CPUSTATS_CPU_DEVICE_H

#define SMC_KEY_CPU_TEMP_CORE_AVG "TC0P" //AVERAGE
#define SMC_KEY_CPU_TEMP_CORE_PECI "TCXC" //PECI
#define SMC_KEY_CPU_TEMP_CORE1 "TC1C" //CORE 1
#define SMC_KEY_CPU_TEMP_CORE2 "TC2C" //CORE 2
#define SMC_KEY_CPU_TEMP_CORE3 "TC3C" //CORE 3
#define SMC_KEY_CPU_TEMP_CORE4 "TC4C" //CORE 4
#define SMC_KEY_CPU_TEMP_CORE5 "TC5C" //CORE 5
#define SMC_KEY_CPU_TEMP_CORE6 "TC6C" //CORE 6
#define SMC_KEY_CPU_TEMP_CORE7 "PC6C"
#define SMC_KEY_CPU_TEMP_CORE8 "PC7C"


#define SMC_KEY_CPU_POWER_CORE1 "PC0C"
#define SMC_KEY_CPU_POWER_CORE2 "PC1C"
#define SMC_KEY_CPU_POWER_CORE3 "PC2C"
#define SMC_KEY_CPU_POWER_CORE4 "PC3C"
#define SMC_KEY_CPU_POWER_CORE5 "PC4C"
#define SMC_KEY_CPU_POWER_CORE6 "PC5C"
#define SMC_KEY_CPU_POWER_CORE7 "PC6C"
#define SMC_KEY_CPU_POWER_CORE8 "PC7C"


#include "generic_device.h"

class CPU : public GenericDevice {
private:
    static constexpr char temperature[10][5] = {
            SMC_KEY_CPU_TEMP_CORE1,
            SMC_KEY_CPU_TEMP_CORE2,
            SMC_KEY_CPU_TEMP_CORE3,
            SMC_KEY_CPU_TEMP_CORE4,
            SMC_KEY_CPU_TEMP_CORE5,
            SMC_KEY_CPU_TEMP_CORE6,
            SMC_KEY_CPU_TEMP_CORE7,
            SMC_KEY_CPU_TEMP_CORE8,
            SMC_KEY_CPU_TEMP_CORE_AVG,
            SMC_KEY_CPU_TEMP_CORE_PECI
    };

    static constexpr char power[8][5] = {
            SMC_KEY_CPU_POWER_CORE1,
            SMC_KEY_CPU_POWER_CORE2,
            SMC_KEY_CPU_POWER_CORE3,
            SMC_KEY_CPU_POWER_CORE4,
            SMC_KEY_CPU_POWER_CORE5,
            SMC_KEY_CPU_POWER_CORE6,
            SMC_KEY_CPU_POWER_CORE7,
            SMC_KEY_CPU_POWER_CORE8,
    };

public:

    CPU();
    //kernel getters
    void getTemperature(const int& core);
    void getVoltage(const int& core);
    void getPower(const int& core);
    void getCurrent(const int& core);
    void getName(const int& core);
    ushort getCoreNumber();
};
#endif //CPUSTATS_CPU_DEVICE_H
