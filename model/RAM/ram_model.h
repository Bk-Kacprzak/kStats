#ifndef KSTATS_VIEW_H_RAM_MODEL_H
#define KSTATS_VIEW_H_RAM_MODEL_H

#include "../Generic/generic_device.h"
#include <cmath>

class RamModel : GenericDevice {
    ValueContainer<long> ramSize;
    //todo: implement free, total, cache, app, compressed memories

public:
    RamModel();
    void readRamSize();
    const long& RamSize();
};

#endif //KSTATS_VIEW_H_RAM_MODEL_H
