#ifndef CPUSTATS_GPU_DEVICE_H
#define CPUSTATS_GPU_DEVICE_H

#include "../Generic/generic_device.h"
#include "../Utils/keys.h"
class GPU : GenericDevice {
#define GPU_MAX_COUNT 2
#define GPU_TEMP_COUNT 4
    static constexpr keyContainer<GPU_TEMP_COUNT> temperature = {
        SMC_KEY_GPU_PROXIMITY,
        SMC_KEY_GPU0_HEATSINK,
        SMC_KEY_GPU1_DIE,
        SMC_KEY_GPU1_HEATSINK,
    };
    ValueContainer<std::vector<std::string>> modelName;
    ValueContainer<std::array<float, GPU_MAX_COUNT*2 +1>> GPUTemperature;
    std::condition_variable cv;
public:
    GPU();
    void retrieveModelName();
    //kernel getters
    void getTemperature(const int &property);
    void getAllTemperatureValues();
    std::vector<std::string>& getModelName();
};


#endif //CPUSTATS_GPU_DEVICE_H
