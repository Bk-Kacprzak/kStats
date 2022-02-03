#include "battery_model.h"

void BatteryModel::readBatteryKey(KEYTYPE keytype, const int &index) {
    kernReturnValue result;
    switch(keytype) {
        case CELL_VOLTAGE: {
            result = readKey(batteryVoltageKeys[index]);
            std::lock_guard<std::mutex> lock(controller_mutex);
            std::cout << "Battery Cell " << index << " voltage: " << (float)result.i/1000 << "V \n";
            batteryVoltageValue[index] = (float)result.i/1000;
            break;
        }
        case CELL_CAPACITY: {
            result = readKey(batteryCapacityKeys[index]);
            std::cout<<"Battery Cell " << index << " capacity: "<<result.i<< " mAh \n";
            batteryCapacityValue[index] = result.i;
            break;
        }
        case TOTAL_AMPERAGE: {
            result = readKey(totalAmperageKey);
            std::cout<<"Battery total amperage: "<<result.f<< " mA\n";
            std::lock_guard<std::mutex> lock(controller_mutex);
            totalAmperageValue = result.f;
            break;
        }
        case TOTAL_VOLTAGE: {
            result = readKey(totalVoltageKey);
            std::cout<<"Battery total voltage: "<<(float)result.i/1000<< " V\n";
            std::lock_guard<std::mutex> lock(controller_mutex);
            totalVoltageValue = (float)result.i/1000;
            break;
        }
        case CYCLE_COUNT: {
            result = readKey(cycleCountKey);
            std::cout<<"Battery cycle count: "<<result.i<< " cycles\n";
            std::lock_guard<std::mutex> lock(controller_mutex);
            cycleCountValue = result.i;
            break;
        }
        default:
            throw std::invalid_argument("Unknown index or keytype\n.");
    }
}


void BatteryModel::retrieveEachBatteryVoltage() {
    for(int i = 0; i<batteryNum; i++){
        threadPool.push([=] {
            readBatteryKey(KEYTYPE::CELL_VOLTAGE, i);
        });
    }
}

void BatteryModel::retrieveEachBatteryCapacity() {
    for(int i = 0; i<batteryNum; i++){
        threadPool.push([=] {
            readBatteryKey(KEYTYPE::CELL_CAPACITY, i);
        });
    }
}

void BatteryModel::retrieveCycleCount() {
    threadPool.push([=] {
        readBatteryKey(KEYTYPE::CYCLE_COUNT);
    });
}

void BatteryModel::retrieveTotalVoltage() {
    threadPool.push([=] {
        readBatteryKey(KEYTYPE::TOTAL_VOLTAGE);
    });
}

void BatteryModel::retrieveTotalAmperage() {
    threadPool.push([=] {
        readBatteryKey(KEYTYPE::TOTAL_AMPERAGE);
    });
}


