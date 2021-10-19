#ifndef KSTATS_VIEW_H_KSTATSCONTROLLER_H
#define KSTATS_VIEW_H_KSTATSCONTROLLER_H

#include "../model/kStats_model.h"
#include "../model/Generic/generic_class.h"
class kStatsController : public GenericClass{
public:
    kStatsController() = default;
    //battery
    const std::array<float, batteryNum>& getEachBatteryVoltage();
    const std::array<int, batteryNum>& getEachBatteryCapacity();
    const uint& getCycleCount();
    const float& getBatteryAmperage();

    //cpu
    const std::array<float, 8>& getCPUTemperature();
    const char* getCPUProcessorModel();
    const ushort& getCPUPhysicalCoreCount();
    const ushort& getCPUCacheSize();
    const ushort& getCPUByteOrder();
    const ushort& getCPUArchitecture();

    //fans
    void setFanSpeed(const int& speed);
        //left
    const std::array<float, 3>& getLeftFanSpeed();
//    const float& getCurrentLeftFanSpeed();
        //right
    const std::array<float, 3>& getRightFanSpeed();

    //gpu
    const std::vector<std::string>& getEachGPUModelName();
    const std::array<float, GPU_ALL_TEMP>& getEachGPUTemperature();

    //network
    const std::string& getWifiIP();
    const std::string& getAddressIPv6();
    const std::string& getWifiMacAddress();
    const std::string& getWifiSSID();
    void testConnectionSpeed();
    const ConnectionStats& getConnectionsStats();
    bool isTestingConnection();

    //peripherals
    const std::vector<GenericPeripheral> &getDevices();

    //volume storage
    const std::string &getVolumeStorageName();
    const std::string &getVolumeStorageFormatDescription();
    const float &getVolumeStorageFreeMemory();
    const float &getVolumeStorageTotalMemory();
private:
    kStatsModel model;
};

#endif //KSTATS_VIEW_H_KSTATSCONTROLLER_H
