#ifndef KSTATS_VIEW_H_KSTATSCONTROLLER_H
#define KSTATS_VIEW_H_KSTATSCONTROLLER_H

#include "../model/kStats_model.h"
#include "../model/Generic/generic_class.h"
class kStatsController : public GenericClass{
public:
    kStatsController() = default;

    //MainDevice
    const char * getMainDeviceName();
    const char * getOsVersion();

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
    std::string getCPUArchitecture();

    //ram
    const long& getRamSize();

    //fans
    void setFanSpeed(const int& speed);
    const std::array<int, 2> && getFansCurrentSpeed();
    const std::array<int, 4> && getFansMinMaxSpeed();

        //left
    const std::array<int, 3>& getLeftFanSpeed();
//    const float& getCurrentLeftFanSpeed();
        //right
    const std::array<int, 3>& getRightFanSpeed();

    //gpu
    const std::vector<std::string>& getEachGPUModelName();
    const std::array<float, GPU_ALL_TEMP>& getEachGPUTemperature();

    //network
    const char * getWifiIP();
    const char * getAddressIPv6();
    const std::string& getWifiMacAddress();
    const std::string& getWifiSSID();
    void lockConnectionSpeedTest();
    ConnectionStats& getConnectionsStats();
    bool isTestingConnection();
    std::string getBestServer();
    float getDownloadSpeed();
    float getUploadSpeed();
    int getLatency();
    void closeConnectionSpeedTest();

    //peripherals
    const std::vector<GenericPeripheral> &getDevices();
    std::vector<std::string> getDeviceTypes();
    std::vector<std::string> getDeviceNames();

    //volume storage
    const std::string &getVolumeStorageName();
    const std::string &getVolumeStorageFormatDescription();
    const float &getVolumeStorageFreeMemory();
    const float &getVolumeStorageTotalMemory();
private:
    kStatsModel model;
};

#endif //KSTATS_VIEW_H_KSTATSCONTROLLER_H
