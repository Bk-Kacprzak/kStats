#ifndef CPUSTATS_BATTERY_CONTROLLER_H
#define CPUSTATS_BATTERY_CONTROLLER_H

#include "../Generic/generic_device.h"

class BatteryController : public GenericDevice {
public:
    enum KEYTYPE {
        CELL_VOLTAGE = 0,
        CELL_CAPACITY = 1,
        TOTAL_AMPERAGE = 2,
        TOTAL_VOLTAGE = 3,
        CYCLE_COUNT = 4
    };
private:
    static constexpr size_t batteryNum = 3;
    static constexpr keyContainer<batteryNum> batteryVoltageKeys = {
            SMC_KEY_BATTERY_CELL1_VOLTAGE,
            SMC_KEY_BATTERY_CELL2_VOLTAGE,
            SMC_KEY_BATTERY_CELL3_VOLTAGE,
    };
    static constexpr keyContainer<batteryNum> batteryCapacityKeys = {
            SMC_KEY_BATTERY_CELL1_CAPACITY,
            SMC_KEY_BATTERY_CELL2_CAPACITY,
            SMC_KEY_BATTERY_CELL3_CAPACITY,
    };

    static constexpr SMC_KEY totalAmperageKey = SMC_KEY_BATTERY_AMPERAGE;
    static constexpr SMC_KEY totalVoltageKey = SMC_KEY_BATTERY_VOLTAGE;
    static constexpr SMC_KEY cycleCountKey = SMC_KEY_BATTERY_CYCLECOUNT;

    std::array<float, batteryNum> batteryVoltageValue = {};
    std::array<int, batteryNum> batteryCapacityValue = {};
    float totalAmperageValue;
    float totalVoltageValue;
    uint cycleCountValue;

    std::mutex battery_mutex;

    void readBatteryKey(BatteryController::KEYTYPE keytype, const int &index = -1);
public:
    //getters
    void getEachBatteryVoltage();
    void getEachBatteryCapacity();
    void getCycleCount();
    void getTotalVoltage();
    void getTotalAmperage();
    void getAllInformation();
};


#endif //CPUSTATS_BATTERY_CONTROLLER_H
