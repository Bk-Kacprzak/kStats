#ifndef CPUSTATS_NETWORK_CONTROLLER_H
#define CPUSTATS_NETWORK_CONTROLLER_H

#include <ifaddrs.h>
#include <arpa/inet.h>
#include <net/if_dl.h>
#include "network_speed.h"
#include "../Generic/generic_class.h"
#include <condition_variable>


class NetworkModel : public GenericClass {
    typedef char IPv4[INET_ADDRSTRLEN];
    typedef char IPv6[INET6_ADDRSTRLEN];
private:
    ValueContainer<IPv4> wifiIP;
    ValueContainer<IPv6> addressIPv6;
    ValueContainer<std::string> wifiMACAddress;
    ValueContainer<std::string> wifiSSID;
    ValueContainer<ConnectionStats> connectionSpeed;
    ValueContainer<bool> isTesting;

    void retrieveWifiInformation();
    void testConnectionSpeed();
    void retrieveSSID();
    mutable std::condition_variable cv;
public:
    NetworkModel();
    void setConnectionStats();
    const char* WifiIP() const;
    const char* AddressIPv6() const;
    const std::string& WifiMacAddress() const;
    const std::string& WifiSSID() const;
    ConnectionStats& ConnectionSpeed() ;
    bool IsTestingConnection();
    void lockConnectionSpeedTest();

    std::string getBestServer();
    float getDownloadSpeed();
    float getUploadSpeed();
    int getLatency();

    void closeConnectionSpeedTest();

};


#endif //CPUSTATS_NETWORK_CONTROLLER_H
