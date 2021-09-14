//
// Created by Bartłomiej Kacprzak on 14/09/2021.
//

#include "battery_controller.h"

void BatteryController::readBatteryKey(KEYTYPE keytype, const int &index) {
    kernReturnValue result;
    switch(keytype) {
        case CELL_VOLTAGE: {
            result = readKey(batteryVoltageKeys[index]);
            std::cout << "Battery Cell " << index << " voltage: " << (float)result.i/1000 << "V \n";
            controller_mutex.lock();
            batteryVoltageValue[index] = (float)result.i/1000;
            controller_mutex.unlock();
            break;
        }
        case CELL_CAPACITY: {
            result = readKey(batteryCapacityKeys[index]);
            std::cout<<"Battery Cell " << index << " capacity: "<<result.i<< " mAh \n";
            controller_mutex.lock();
            batteryCapacityValue[index] = result.i;
            controller_mutex.unlock();
            break;
        }
        case TOTAL_AMPERAGE: {
            result = readKey(totalAmperageKey);
            std::cout<<"Battery total amperage: "<<result.f<< " mA\n";
            controller_mutex.lock();
            totalAmperageValue = result.f;
            controller_mutex.unlock();
            break;
        }
        case TOTAL_VOLTAGE: {
            result = readKey(totalVoltageKey);
            std::cout<<"Battery total voltage: "<<(float)result.i/1000<< " V\n";
            controller_mutex.lock();
            totalVoltageValue = (float)result.i/1000;
            controller_mutex.unlock();
            break;
        }
        case CYCLE_COUNT: {
            result = readKey(cycleCountKey);
            std::cout<<"Battery cycle count: "<<result.i<< " cycles\n";
            controller_mutex.lock();
            cycleCountValue = result.i;
            controller_mutex.unlock();
            break;
        }
        default:
            throw std::invalid_argument("Unknown index or keytype\n.");
    }
}


void BatteryController::getEachBatteryVoltage() {
    for(int i = 0; i<batteryNum; i++){
        threadPool.push([=] {
            readBatteryKey(KEYTYPE::CELL_VOLTAGE, i);
        });
    }
}

void BatteryController::getEachBatteryCapacity() {
    for(int i = 0; i<batteryNum; i++){
        threadPool.push([=] {
            readBatteryKey(KEYTYPE::CELL_CAPACITY, i);
        });
    }
}

void BatteryController::getCycleCount() {
    threadPool.push([=] {
       readBatteryKey(KEYTYPE::CYCLE_COUNT);
    });
}

void BatteryController::getTotalVoltage() {
    threadPool.push([=] {
       readBatteryKey(KEYTYPE::TOTAL_VOLTAGE);
    });
}

void BatteryController::getTotalAmperage() {
    threadPool.push([=] {
       readBatteryKey(KEYTYPE::TOTAL_AMPERAGE);
    });
}

void BatteryController::getAllInformation() {
    getEachBatteryVoltage();
    getEachBatteryCapacity();
    getCycleCount();
    getTotalVoltage();
    getTotalAmperage();
}
