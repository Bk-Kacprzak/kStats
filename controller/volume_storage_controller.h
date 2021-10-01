#ifndef CPUSTATS_VOLUME_STORAGE_CONTROLLER_H
#define CPUSTATS_VOLUME_STORAGE_CONTROLLER_H
#include <string>
#include <Foundation/Foundation.h>
#include "generic_class.h"


class VolumeStorage {
    std::string name;
    std::string formatDescription;
    float freeMemory;
    float totalMemory;
    std::mutex mtx;

    void retrieveVolumeInformation();
public:
    VolumeStorage();
    ~VolumeStorage() = default;
    const std::string &getName() const;
    const std::string &getFormatDescription() const;
    float getFreeMemory() const;
    float getTotalMemory() const;
};


#endif //CPUSTATS_VOLUME_STORAGE_CONTROLLER_H
