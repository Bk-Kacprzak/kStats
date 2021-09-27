#ifndef CPUSTATS_CPU_DEVICE_H
#define CPUSTATS_CPU_DEVICE_H

#include "generic_device.h"
#include "Utils/threadPool.h"
#include "Utils/keys.h"
#include <mutex>
#include <vector>
#include <sys/sysctl.h>

class CPU : public GenericDevice {
#define CPU_MAX_COUNT 8

private:
    static constexpr keyContainer<CPU_MAX_COUNT + 2> temperature = {
            SMC_KEY_CPU_TEMP_CORE1,
            SMC_KEY_CPU_TEMP_CORE2,
            SMC_KEY_CPU_TEMP_CORE3,
            SMC_KEY_CPU_TEMP_CORE4,
            SMC_KEY_CPU_TEMP_CORE5,
            SMC_KEY_CPU_TEMP_CORE6,
            SMC_KEY_CPU_TEMP_CORE7,
            SMC_KEY_CPU_TEMP_CORE8,
            SMC_KEY_CPU_TEMP_CORE_AVG,
            SMC_KEY_CPU_TEMP_CORE_PECI,
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
//    void retrieveCPUInformation();

    ValueContainer<char [64]> processorModel;
    ValueContainer<ushort> physicalCoreCount;
    ValueContainer<ushort> cacheSize;
    ValueContainer<ushort> byteOrder;
    ValueContainer<ushort> architecture;
    mutable std::condition_variable cv;
    std::mutex classMtx;
    bool assigning;
    void retrieveCPUInormation();
    template<typename T>
    void sysctlCall(ValueContainer<T> &, const char*, size_t max_byte_size);
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
    void setKey(KEYTYPE,const ushort id);
    ushort getCoreNumber();

    const char* getProcessorModel() const;
    ushort getPhysicalCoreCount() const;
    ushort getCacheSize() const;
    ushort getByteOrder() const;
    ushort getArchitecture() const;
};
#endif //CPUSTATS_CPU_DEVICE_H
