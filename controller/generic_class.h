#ifndef CPUSTATS_GENERIC_CLASS_H
#define CPUSTATS_GENERIC_CLASS_H

#include "Utils/threadPool.h"

class GenericClass {
    protected:
//       std::mutex thread_mutex;
       static knet::threadPool threadPool;
    public:
        GenericClass();
        virtual ~GenericClass() = default;
};



#endif //CPUSTATS_GENERIC_CLASS_H
