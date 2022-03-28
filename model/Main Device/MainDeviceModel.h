#ifndef KSTATS_VIEW_H_MAINDEVICEMODEL_H
#define KSTATS_VIEW_H_MAINDEVICEMODEL_H
#include "../Generic/generic_device.h"
#include <map>

class MainDeviceModel : public GenericDevice{
    std::map<const char *, const char*> currentOs = {
            {"Monterey 12.2.1", "21D62"},
            {"Monterey 12.2", "21D49"},
            {"Monterey 11.1", "21C52"},
            {"Big Sur 11.6.3" ,"20G415"},
            {"Big Sur 11.6.2" ,"20G314"},
            {"Big Sur 11.6.1" ,"20G224"},
            {"Big Sur 11.6" ,"20G165"},
            {"Big Sur 11.5.2", "20G95"},
            {"Big Sur 11.5.1", "20G80"},
            {"Big Sur 11.5", "20G71"},
            {"Big Sur 11.4", "20F71"},
            {"Big Sur 11.3.1" ,"20E241"},
            {"Big Sur 11.3" ,"20E232"},
            {"Big Sur 11.2.3", "20D91"},
            {"Big Sur 11.2.2", "20D80"},
            {"Big Sur 11.2.1", "20D74"},
            {"Big Sur 11.2", "20D64"},
            {"Big Sur 11.1", "20C69"},
            {"Big Sur 11.0.1", "20B50"},
            {"Big Sur 11.0.1", "20B29"},
            {"Catalina 10.15.15" ,"19A583"},
            {"Catalina 10.15.15" ,"19A602"},
            {"Catalina 10.15.15","19A603"},
            {"Catalina 10.15.1" ,"19B88"},
            {"Catalina 10.15.2" ,"19C57"},
            {"Catalina 10.15.2" ,"19C58"},
            {"Catalina 10.15.3" ,"19D76"},
            {"Catalina 10.15.4" ,"19E266"},
            {"Catalina 10.15.4" ,"19E287"},
            {"Catalina 10.15.5" ,"19F96"},
            {"Catalina 10.15.5" ,"19F101"},
            {"Catalina 10.15.6" ,"19G73"},
            {"Catalina 10.15.6" ,"19G2021"},
            {"Catalina 10.15.7" ,"19H2"},
            {"Catalina 10.15.7" ,"19H4"},
            {"Catalina 10.15.7" ,"19H15"},
            {"Catalina 10.15.7" ,"19H114"},
            {"Catalina 10.15.7" ,"19H512"},
            {"Catalina 10.15.7" ,"19H524"},
            {"Catalina 10.15.7" ,"19H1030"},
            {"Catalina 10.15.7" ,"19H1217"},
            {"Catalina 10.15.7" ,"19H1323"},
            {"Catalina 10.15.7" ,"19H1417"},
            {"Catalina 10.15.7", "19H1419"},
            {"Catalina 10.15.7", "19H1519"},
            {"Catalina 10.15.7", "19H1615"},
            {"Catalina 10.15.7", "19H1713"},
    };

    mutable std::condition_variable cv;
    ValueContainer<char[64]> deviceName;
    ValueContainer<char[64]> osVersion;

public:
    MainDeviceModel();
    void getDeviceInfo();
    const char* DeviceName() const;
    const char* OsVersion() const;
};


#endif //KSTATS_VIEW_H_MAINDEVICEMODEL_H
