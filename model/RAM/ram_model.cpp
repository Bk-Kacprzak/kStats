//
// Created by Bartłomiej Kacprzak on 08/02/2022.
//

#include "ram_model.h"

RamModel::RamModel() {
    readRamSize();
}

const long& RamModel::RamSize() {
    return ramSize.value;
}

void RamModel::readRamSize()  {
    sysctlCall(ramSize, "hw.memsize", 64);
    ramSize.value /= pow(10, 9);
    if (ramSize.value > 16 && ramSize.value < 20)
        ramSize.value = 16;

}
