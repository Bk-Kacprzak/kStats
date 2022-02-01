#ifndef CPUSTATS_GENERIC_CLASS_H
#define CPUSTATS_GENERIC_CLASS_H

#include "../Utils/threadPool.h"
#include <mutex>
static knet::threadPool threadPool;

template<typename T>
struct ValueContainer {
    mutable std::mutex mtx;
    T value;
    ValueContainer(){ }
    ValueContainer(T _value) : value(_value) {}
    ValueContainer(const ValueContainer &&) = delete;
    ValueContainer(const ValueContainer &) = delete;
};

class GenericClass {
    protected:
       mutable std::mutex controller_mutex;
public:
        GenericClass();
        virtual ~GenericClass() = default;
};



#endif //CPUSTATS_GENERIC_CLASS_H
