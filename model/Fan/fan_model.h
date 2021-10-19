#ifndef CPUSTATS_FAN_CONTROLLER_H
#define CPUSTATS_FAN_CONTROLLER_H

#include "../Generic/generic_device.h"

class FanModel : public GenericDevice{
private:
#define MIN_SPEED 2500
#define MAX_SPEED 5500

    static constexpr size_t fanNum = 2;
    static constexpr size_t fanAttributeSize = 3;

    //4 keys to each fan
        static constexpr keyContainer<fanNum * fanAttributeSize> fanSpeed= {
                SMC_KEY_FAN0_CURRENT_SPEED,
                SMC_KEY_FAN0_MINIMUM_SPEED,
                SMC_KEY_FAN0_MAXIMUM_SPEED,
                SMC_KEY_FAN1_CURRENT_SPEED,
                SMC_KEY_FAN1_MINIMUM_SPEED,
                SMC_KEY_FAN1_MAXIMUM_SPEED,
        };

        static constexpr std::array<const char*, fanAttributeSize> speedTypes= {
            "Current speed: ",
            "Minimum speed: ",
            "Maximum speed: "
        };

        std::mutex fan_mutex;
        ValueContainer<std::array<float, 3>> fanLeft;
        ValueContainer<std::array<float, 3>> fanRight;
public:
    enum KEYTYPE {
        CURRENT_SPEED = 0,
        MINIMUM_SPEED = 1,
        MAXIMUM_SPEED = 2,
        ALL = 3
    };

    enum FANTYPE {
        LEFT = 0,
        RIGHT = 1
    };

    //getters
    void getFanSpeedRPM(const FANTYPE fan,const KEYTYPE speedType = KEYTYPE::ALL);
    void getEachFanSpeedRPM(const KEYTYPE speedType = KEYTYPE::ALL);
    void retrieveEachFanSpeedRPM();
    //setters
    void setFanSpeed(const FANTYPE fan, const float speed);
    const std::array<float, 3>& FanLeft();
    const std::array<float, 3>& FanRight();

};


#endif //CPUSTATS_FAN_CONTROLLER_H
