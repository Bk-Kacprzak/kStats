#include "volume_storage_model.h"
#include <iostream>
#include <iomanip>
VolumeStorage::VolumeStorage() {
    readVolumeStorageInformation();
}

void VolumeStorage::readVolumeStorageInformation() {
    NSURL *fileURL = [[NSURL alloc] initFileURLWithPath:@"/System/Volumes/Data/"];
    NSError *error = nil;
    NSDictionary *results = [fileURL resourceValuesForKeys:@[
            NSURLVolumeAvailableCapacityKey,
            NSURLVolumeLocalizedNameKey,
            NSURLVolumeTotalCapacityKey,
            NSURLVolumeLocalizedFormatDescriptionKey,
    ] error:&error];
    NSArray<NSString *> *keys = results.allKeys;
    NSArray *values = results.allValues;

    if(keys.count != values.count)
        throw std::runtime_error("Unable to read all properties from Storage\n");

    std::lock_guard<std::mutex> lock(mtx);
    for(int i = 0; i < keys.count; i++) {
        if(keys[i] == NSURLVolumeLocalizedNameKey){
           name = static_cast<NSString*> (values[i]).UTF8String;
        }
        else if(keys[i] == NSURLVolumeLocalizedFormatDescriptionKey){
            formatDescription = static_cast<NSString*> (values[i]).UTF8String;
        }
        else if(keys[i] == NSURLVolumeTotalCapacityKey){
            totalMemory = static_cast<NSNumber*>(values[i]).floatValue/1000000000;
            totalMemory = (int)totalMemory;
        }
        else if(keys[i] == NSURLVolumeAvailableCapacityKey){
            freeMemory = static_cast<NSNumber*>(values[i]).floatValue/1000000000;
        }
    }
}

const std::string &VolumeStorage::Name() const {
    std::lock_guard<std::mutex> lock(mtx);
    return name;
}

const std::string &VolumeStorage::FormatDescription() const {
    std::lock_guard<std::mutex> lock(mtx);
    return formatDescription;
}

const float& VolumeStorage::FreeMemory() const {
    std::lock_guard<std::mutex> lock(mtx);
    return freeMemory;
}

const float& VolumeStorage::TotalMemory() const {
    std::lock_guard<std::mutex> lock(mtx);
    return totalMemory;
}
