#ifndef CPUSTATS_BATTERY_CONTROLLER_H
#define CPUSTATS_BATTERY_CONTROLLER_H

#include "../Generic/generic_device.h"

static constexpr size_t batteryNum = 3;

class BatteryModel : public GenericDevice {
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

    ValueContainer<std::array<float, batteryNum>> batteryVoltage = {};
    ValueContainer<std::array<int, batteryNum>> batteryCapacity = {};
    static constexpr SMC_KEY totalAmperageKey = SMC_KEY_BATTERY_AMPERAGE;
    static constexpr SMC_KEY totalVoltageKey = SMC_KEY_BATTERY_VOLTAGE;
    static constexpr SMC_KEY cycleCountKey = SMC_KEY_BATTERY_CYCLECOUNT;
    ValueContainer<float> totalAmperage;
    ValueContainer<float> totalVoltage;
    ValueContainer<uint> cycleCount;
    std::condition_variable cv;
public:
    BatteryModel() = default;
    enum KEYTYPE {
        CELL_VOLTAGE = 0,
        CELL_CAPACITY = 1,
        TOTAL_AMPERAGE = 2,
        TOTAL_VOLTAGE = 3,
        CYCLE_COUNT = 4
    };




    //readers
    void readBatteryKey(BatteryModel::KEYTYPE keytype, const int &index = -1);
    void readEachBatteryVoltage();
    void readEachBatteryCapacity();
    void readCycleCount();
    void readTotalVoltage();
    void readTotalAmperage();
    void getAllInformation();

    const std::array<int, batteryNum>& BatteryCapacity();
    const std::array<float, batteryNum>& BatteryVoltage();
    const uint& CycleCount();
    const float& TotalAmperage();
    const float& TotalVoltage();
};


#endif //CPUSTATS_BATTERY_CONTROLLER_H
