#include "volume_storage_controller.h"
#include <iostream>
#include <iomanip>
VolumeStorage::VolumeStorage() {
    retrieveVolumeInformation();
}

void VolumeStorage::retrieveVolumeInformation() {
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
        }
        else if(keys[i] == NSURLVolumeAvailableCapacityKey){
            freeMemory = static_cast<NSNumber*>(values[i]).floatValue/1000000000;
        }
    }

    std::cout<<name<<"\t"<<formatDescription<<"\t"<<std::setprecision(4)<<freeMemory<<"\t"<<std::setprecision(5)<<totalMemory<<"\n";
}

const std::string &VolumeStorage::getName() const {
    std::lock_guard<std::mutex> lock(mtx);
    return name;
}

const std::string &VolumeStorage::getFormatDescription() const {
    std::lock_guard<std::mutex> lock(mtx);
    return formatDescription;
}

float VolumeStorage::getFreeMemory() const {
    std::lock_guard<std::mutex> lock(mtx);
    return freeMemory;
}

float VolumeStorage::getTotalMemory() const {
    std::lock_guard<std::mutex> lock(mtx);
    return totalMemory;
}
