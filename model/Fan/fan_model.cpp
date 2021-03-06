#include "fan_model.h"

FanModel::FanModel() {
    readEachFanSpeedRPM();
}

void FanModel::getFanSpeedRPM(const FanModel::FANTYPE fan, const FanModel::KEYTYPE speedType) {
    int i = 0;
    try {
            if (fan == LEFT)
                i = speedType;
            else if (fan == RIGHT)
                i = 3 + speedType;
            else
                throw std::invalid_argument("Invalid fan number.\n");

            float return_value = readKey(fanSpeed[i]).f;
            if(fan == LEFT) {
                std::lock_guard<std::mutex> lock(fanLeft.mtx);
                fanLeft.value[speedType] = (int)return_value;
            }
            else if(fan == RIGHT) {
                std::lock_guard<std::mutex> lock(fanRight.mtx);
                fanRight.value[speedType] = (int)return_value;
            }

    } catch (...) {
//        knet::threadPool::exceptionPointer = std::current_exception();
    }
}
void FanModel::readEachFanSpeedRPM() {
    getEachFanSpeedRPM(CURRENT_SPEED);
    getEachFanSpeedRPM(MAXIMUM_SPEED);
    getEachFanSpeedRPM(MINIMUM_SPEED);
}
void FanModel::getEachFanSpeedRPM(const FanModel::KEYTYPE speedType) {
    threadPool.push([=] {
        getFanSpeedRPM(LEFT, speedType);
    });

    threadPool.push([=] {
        getFanSpeedRPM(RIGHT, speedType);
    });
}

const std::array<int, 3> &FanModel::FanLeft() {
    std::lock_guard<std::mutex> lock(fanLeft.mtx);
    return fanLeft.value;
}

const std::array<int, 3> &FanModel::FanRight() {
    std::lock_guard<std::mutex> lock(fanRight.mtx);
    return fanRight.value;
}

const std::array<int, 2> &&FanModel::FansCurrentSpeed() {
    std::lock_guard<std::mutex> lockLeft(fanLeft.mtx);
    std::lock_guard<std::mutex> lockRight(fanRight.mtx);
    return std::array<int,2>{fanLeft.value[0], fanRight.value[0]};
}

const std::array<int, 4> FanModel::FansMinMaxSpeed() {
    std::lock_guard<std::mutex> lockLeft(fanLeft.mtx);
    std::lock_guard<std::mutex> lockRight(fanRight.mtx);
    return std::array<int,4>{fanLeft.value[1],fanLeft.value[2],fanRight.value[1], fanRight.value[2]};
}
void FanModel::setFanSpeed(const FanModel::FANTYPE fan, const float speed) {
//    if (!(speed > MIN_SPEED && speed < MAX_SPEED))
//        return;
//
//    int index;
//    if(fan == LEFT)
//        index = 0;
//    else if(fan == RIGHT)
//        index = 3;
//
//    SMCVal_t val;
//    memcpy(val.dataType, DATATYPE_FLT, 5);
//    memcpy(val.key, fanSpeed[index], 5);
//    //-536870207
//
//    val.dataSize = DATATYPE_FLT_DATASIZE;
//    Converter::floatToFlt(speed,val.bytes);
//
//    writeKey(&val);
//    std::lock_guard<std::mutex> lock(fan_mutex);
//    fanSpeed[index] = speed;
}
