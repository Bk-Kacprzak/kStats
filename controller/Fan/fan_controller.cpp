//
// Created by Bartłomiej Kacprzak on 10/09/2021.
//

#include "fan_controller.h"



void FanController::getFanSpeedRPM(const FanController::FANTYPE fan, const FanController::KEYTYPE speedType) {
    int i = 0;
    try {
        if(speedType == ALL){
            int it = 0;
            for(int j = fan * speedType; j < speedType*(fan+1); j++) {
                float return_value = readKey(fan_mutex, fanSpeed[j]).f;
                std::lock_guard<std::mutex> lock(fan_mutex);
                fanSpeedContainer[j] = return_value;
//                fan_mutex.unlock();
                std::cout<<speedTypes[it]<<"rFAN "<<fan<<": "<< return_value << " RPM"<<std::endl;
                it++;
            }

            return;
        } else {
            if (fan == LEFT)
                i = speedType;
            else if (fan == RIGHT)
                i = 3 + speedType;
            else
                throw std::invalid_argument("Invalid fan number.\n");

            float return_value = readKey(fan_mutex, fanSpeed[i]).f;
            std::lock_guard<std::mutex> lock(fan_mutex);
            fanSpeedContainer[i] = return_value;
//            fan_mutex.unlock();
            std::cout<<speedTypes[speedType]<<return_value << " RPM"<<std::endl;
        }

    } catch (...) {
//        knet::threadPool::exceptionPointer = std::current_exception();
    }
}

void FanController::getEachFanSpeedRPM(const FanController::KEYTYPE speedType) {
    threadPool.push([=] {
        getFanSpeedRPM(LEFT, speedType);
    });

    threadPool.push([=] {
        getFanSpeedRPM(RIGHT, speedType);
    });

}

void FanController::setFanSpeed(const FanController::FANTYPE fan, const float speed) {
    if (!(speed > MIN_SPEED && speed < MAX_SPEED))
        return;

    int index;
    if(fan == LEFT)
        index = 0;
    else if(fan == RIGHT)
        index = 3;

    SMCVal_t val;
    memcpy(val.dataType, DATATYPE_FLT, 5);
    memcpy(val.key, fanSpeed[index], 5);
    //-536870207

    val.dataSize = DATATYPE_FLT_DATASIZE;
    Converter::floatToFlt(speed,val.bytes);

    writeKey(&val);
    std::lock_guard<std::mutex> lock(fan_mutex);
    fanSpeedContainer[index] = speed;
}

