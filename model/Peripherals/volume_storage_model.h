#ifndef CPUSTATS_VOLUME_STORAGE_CONTROLLER_H
#define CPUSTATS_VOLUME_STORAGE_CONTROLLER_H

#include <string>
#include <mutex>
#include "iokit_libraries.h"


class VolumeStorage {
    std::string name;
    std::string formatDescription;
    float freeMemory;
    float totalMemory;
    mutable std::mutex mtx;

    void readVolumeStorageInformation();
public:
    VolumeStorage();
    ~VolumeStorage() = default;
    const std::string &Name() const;
    const std::string &FormatDescription() const;
    const float& FreeMemory() const;
    const float& TotalMemory() const;
};


#endif //CPUSTATS_VOLUME_STORAGE_CONTROLLER_H
