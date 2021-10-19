#ifndef CPUSTATS_GENERIC_DEVICE_H
#define CPUSTATS_GENERIC_DEVICE_H

#include <string>
#include <memory>
#include "generic_class.h"
#include "../Utils/keys.h"
#include "../Utils/utilsConverter.h"
#include "../Utils/threadPool.h"

template <size_t size>
using keyContainer = std::array<char [5], size>;

class GenericDevice : public GenericClass{
public:
    GenericDevice();
    virtual ~GenericDevice() = default;

//    ~GenericDevice() override; //???
    typedef union {
        float f;
        int i;
    } kernReturnValue;

    kernReturnValue readKey(std::mutex & mtx, const SMC_KEY key = nullptr);
    kernReturnValue readKey(const SMC_KEY key = nullptr);
    void writeKey(std::mutex &mtx, SMCVal_t *value);
    void writeKey(SMCVal_t *value);
    void writeKey(const SMC_KEY key, const SMCBytes_t value);

protected:
    SMC_KEY currentKey;
    kernReturnValue smcKeyValue;
};

#endif //CPUSTATS_GENERIC_DEVICE_H
