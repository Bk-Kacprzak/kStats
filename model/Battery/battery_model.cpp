#include "battery_model.h"

void BatteryModel::readBatteryKey(KEYTYPE keytype, const int &index) {
    kernReturnValue result;
    switch(keytype) {
        case CELL_VOLTAGE: {
            result = readKey(batteryVoltageKeys[index]);
            std::lock_guard<std::mutex> lock(batteryVoltage.mtx);
            batteryVoltage.value[index] = (float) result.i / 1000;
            cv.notify_one();
            break;
        }
        case CELL_CAPACITY: {
            std::lock_guard<std::mutex> lock(batteryCapacity.mtx);
            result = readKey(batteryCapacityKeys[index]);
            batteryCapacity.value[index] = result.i;
            cv.notify_one();
            break;
        }
        case TOTAL_AMPERAGE: {
            result = readKey(totalAmperageKey);
            std::lock_guard<std::mutex> lock(totalAmperage.mtx);
            totalAmperage.value = result.i;
            cv.notify_one();
            break;
        }
        case TOTAL_VOLTAGE: {
            result = readKey(totalVoltageKey);
            std::lock_guard<std::mutex> lock(totalVoltage.mtx);
            totalVoltage.value = (float) result.i / 1000;
            cv.notify_one();
            break;
        }
        case CYCLE_COUNT: {
            std::lock_guard<std::mutex> lock(cycleCount.mtx);
            result = readKey(cycleCountKey);
            cycleCount.value = result.i;
            cv.notify_one();
            break;
        }
        default:
            throw std::invalid_argument("Unknown index/keytype\n.");
    }
}


void BatteryModel::readEachBatteryVoltage() {
    for(int i = 0; i<batteryNum; i++){
        threadPool.push([=] {
            readBatteryKey(KEYTYPE::CELL_VOLTAGE, i);
        });
    }
}

void BatteryModel::readEachBatteryCapacity() {
    for(int i = 0; i<batteryNum; i++){
            readBatteryKey(KEYTYPE::CELL_CAPACITY, i);
    }
}

void BatteryModel::readCycleCount() {
        readBatteryKey(KEYTYPE::CYCLE_COUNT);
}

void BatteryModel::readTotalVoltage() {
    threadPool.push([=] {
        readBatteryKey(KEYTYPE::TOTAL_VOLTAGE);
    });
}

void BatteryModel::readTotalAmperage() {
    readBatteryKey(KEYTYPE::TOTAL_AMPERAGE);
}

void BatteryModel::getAllInformation() {

}

const uint &BatteryModel::CycleCount() {
    std::unique_lock<std::mutex> lock(cycleCount.mtx);

    cv.wait(lock,[=] {
        return cycleCount.value!=0;
    });
    return cycleCount.value;
}

const float &BatteryModel::TotalAmperage() {
    std::unique_lock<std::mutex> lock(totalAmperage.mtx);

    cv.wait(lock,[=] {
        return totalAmperage.value!=0;
    });
    return totalAmperage.value;
}

const float &BatteryModel::TotalVoltage() {
    std::unique_lock<std::mutex> lock(totalVoltage.mtx);

    cv.wait(lock,[=] {
        return totalVoltage.value!=0;
    });
    return totalVoltage.value;
}

const std::array<int, batteryNum> &BatteryModel::BatteryCapacity() {
//Z

    std::unique_lock<std::mutex> lock(batteryCapacity.mtx);
    bool isFinished;
    cv.wait(lock,[&] {
        isFinished = true;
        for(const auto& value : batteryCapacity.value)
            if(value == 0) {
                isFinished = false;
                break;
            }
        return isFinished;
    });

    return batteryCapacity.value;
}

const std::array<float, batteryNum> &BatteryModel::BatteryVoltage() {
    std::unique_lock<std::mutex> lock(batteryVoltage.mtx);
    bool isFinished;

    cv.wait(lock,[&] {
        isFinished = true;
        for(const auto& value : batteryVoltage.value)
            if(value == 0) {
                isFinished = false;
                break;
            }
        return isFinished;
    });

    return batteryVoltage.value;
}


