#ifndef CPUSTATS_GENERIC_DEVICE_H
#define CPUSTATS_GENERIC_DEVICE_H

#include <string>
#include <IOKit/IOKitLib.h>
#include "smc.h"
#include "Utils/utilsConverter.h"
#include "Utils/threadPool.h"

template <size_t size>
using keyContainer = std::array<const char [5], size>;

class GenericDevice {

public:
    GenericDevice();



    typedef union {
        float f;
        int i;
    } kernReturnValue;

    kernReturnValue readKey(std::mutex & mtx, const SMC_KEY key = nullptr);
    kernReturnValue readKey(const SMC_KEY key = nullptr);


        void writeKey(std::mutex &mtx, SMCVal_t *value);
        void writeKey(const SMC_KEY key, const SMCBytes_t value);
protected:

    std::string name;
    SMC_KEY currentKey{};
    kernReturnValue smcKeyValue{};
//    std::vector<std::thread> threads;
    knet::threadPool threadPool;
//    virtual void setCurrentKey(, const SMC_KEY key);

};


#endif //CPUSTATS_GENERIC_DEVICE_H
