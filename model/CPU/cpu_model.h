#ifndef CPUSTATS_CPU_DEVICE_H
#define CPUSTATS_CPU_DEVICE_H

#include "../Generic/generic_device.h"
#include "../Utils/keys.h"
#include <mutex>
#include <vector>

#define CPU_MAX_COUNT 8

class CPU : public GenericDevice  {

private:
    static constexpr keyContainer<CPU_MAX_COUNT> temperature = {
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
    };

    static constexpr keyContainer<CPU_MAX_COUNT> power = {
            SMC_KEY_CPU_POWER_CORE1,
            SMC_KEY_CPU_POWER_CORE2,
            SMC_KEY_CPU_POWER_CORE3,
            SMC_KEY_CPU_POWER_CORE4,
            SMC_KEY_CPU_POWER_CORE5,
            SMC_KEY_CPU_POWER_CORE6,
            SMC_KEY_CPU_POWER_CORE7,
            SMC_KEY_CPU_POWER_CORE8,
    };

    //via SMC Keys
    ValueContainer<std::array<float, CPU_MAX_COUNT>> temperatures;

    //via sysctl
    ValueContainer<char [64]> processorModel;
    ValueContainer<ushort> physicalCoreCount;
    ValueContainer<ushort> cacheSize;
    ValueContainer<ushort> byteOrder;
    ValueContainer<ushort> architecture;

    mutable std::condition_variable cv;

    void readCPUInformation();
    void readTemperature(const int& index);

public:
    enum KEYTYPE {
        TEMPERATURE = 0,
        POWER = 1,
        CURRENT = 2,
        VOLTAGE = 3,
    };

    CPU();
    ~CPU();

    const std::array<float, CPU_MAX_COUNT> & Temperatures();
    void setKey(KEYTYPE,const ushort id);
    ushort getCoreNumber();
    const char*  ProcessorModel() const;
    ushort PhysicalCoreCount() const;
    ushort CacheSize() const;
    ushort ByteOrder() const;
    ushort Architecture() const;


};
#endif //CPUSTATS_CPU_DEVICE_H
