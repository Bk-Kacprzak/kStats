#ifndef CPUSTATS_GENERIC_CLASS_H
#define CPUSTATS_GENERIC_CLASS_H

#include "../Utils/threadPool.h"
#include <mutex>
template<typename T>
struct ValueContainer {
    mutable std::mutex mtx;
    T value;
    ValueContainer(){ }
    ValueContainer(T _value) : value(_value) {}
};

class GenericClass {
    protected:
       mutable std::mutex controller_mutex;
       static knet::threadPool threadPool;
public:
        GenericClass();
        virtual ~GenericClass() = default;
};



#endif //CPUSTATS_GENERIC_CLASS_H
