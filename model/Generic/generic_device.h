#ifndef CPUSTATS_GENERIC_DEVICE_H
#define CPUSTATS_GENERIC_DEVICE_H

#include <string>
#include <memory>
#include "generic_class.h"
#include "../Utils/keys.h"
#include "../Utils/utilsConverter.h"
#include "../Utils/threadPool.h"
#include <sys/sysctl.h>

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

    template<typename T>
    void sysctlCall(ValueContainer<T> &, const char*, size_t max_byte_size);
protected:

    SMC_KEY currentKey;
    kernReturnValue smcKeyValue;
};


template<typename T>
void GenericDevice::sysctlCall(ValueContainer<T> &_value, const char *command, size_t max_byte_size) {
    std::lock_guard<std::mutex> lock(_value.mtx);

    if (max_byte_size==0) {
        sysctlbyname(command, nullptr, &max_byte_size, nullptr, 0);
        if(!max_byte_size)
            throw std::runtime_error("property read failed in GenericDevice::sysctlCall(...)");
    }
    sysctlbyname(command, &_value.value, &max_byte_size, nullptr, 0);
}

#endif //CPUSTATS_GENERIC_DEVICE_H
