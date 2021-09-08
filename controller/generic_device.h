#ifndef CPUSTATS_GENERIC_DEVICE_H
#define CPUSTATS_GENERIC_DEVICE_H

#include <string>
#include <IOKit/IOKitLib.h>
#include "smc.h"
#include "Utils/utilsConverter.h"

class GenericDevice {
protected:
        std::string name;
        char currentKey[5];

    protected:

    public:

        typedef union {
            float f;
            int i;
        } kernReturnValue;

        kernReturnValue readKey();
        bool writeKey();
};


#endif //CPUSTATS_GENERIC_DEVICE_H
