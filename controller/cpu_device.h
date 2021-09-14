#ifndef CPUSTATS_CPU_DEVICE_H
#define CPUSTATS_CPU_DEVICE_H

#include "generic_device.h"
#include "Utils/threadPool.h"
#include "Utils/keys.h"
#include <mutex>
#include <vector>
class CPU : public GenericDevice {
private:
    static constexpr keyContainer<10> temperature = {
            SMC_KEY_CPU_TEMP_CORE1,
            SMC_KEY_CPU_TEMP_CORE2,
            SMC_KEY_CPU_TEMP_CORE3,
            SMC_KEY_CPU_TEMP_CORE4,
            SMC_KEY_CPU_TEMP_CORE5,
            SMC_KEY_CPU_TEMP_CORE6,
//            SMC_KEY_CPU_TEMP_CORE7,
//            SMC_KEY_CPU_TEMP_CORE8,
            SMC_KEY_CPU_TEMP_CORE_AVG,
            SMC_KEY_CPU_TEMP_CORE_PECI,
            SMC_KEY_CPU_TEMP_CORE6,
            SMC_KEY_CPU_TEMP_CORE6,
    };
//    static constexpr char temperature[10][5] = {
//
//    };

    static constexpr keyContainer<8> power = {
            SMC_KEY_CPU_POWER_CORE1,
            SMC_KEY_CPU_POWER_CORE2,
            SMC_KEY_CPU_POWER_CORE3,
            SMC_KEY_CPU_POWER_CORE4,
            SMC_KEY_CPU_POWER_CORE5,
            SMC_KEY_CPU_POWER_CORE6,
            SMC_KEY_CPU_POWER_CORE7,
            SMC_KEY_CPU_POWER_CORE8,
    };

    std::mutex temp_mutex;
    //concurrency
//    std::vector<std::thread> threads;
//    knet::threadPool threadPool;
    std::array<float, 8> CPUTemperature = { 0,0,0,0,0,0,0,0};

    //?????
public:

    enum KEYTYPE {
        TEMPERATURE = 0,
        POWER = 1,
        CURRENT = 2,
        VOLTAGE = 3,
    };

    CPU();
    ~CPU();
    //kernel getters
    void getTemperature(const int& core);
    void getEachCoreTemperature();
    void getVoltage(const int& core);
    void getPower(const int& core);
    void getCurrent(const int& core);
    void getName(const int& core);
    void setKey(KEYTYPE,const ushort id);
    ushort getCoreNumber();

};
#endif //CPUSTATS_CPU_DEVICE_H
