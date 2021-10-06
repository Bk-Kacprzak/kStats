#ifndef CPUSTATS_NETWORK_CONTROLLER_H
#define CPUSTATS_NETWORK_CONTROLLER_H

#include <ifaddrs.h>
#include <arpa/inet.h>
#include <net/if_dl.h>
#include "network_speed.h"
#include "../Generic/generic_class.h"
#include <condition_variable>


class NetworkController : public GenericClass {
    typedef char IPv4[INET_ADDRSTRLEN];
    typedef char IPv6[INET6_ADDRSTRLEN];
private:
    ValueContainer<IPv4> wifiIP;
    ValueContainer<IPv6> addressIPv6;
    ValueContainer<std::string> wifiMACAddress;
    ValueContainer<std::string> wifiSSID;
    ValueContainer<ConnectionStats> connectionSpeed;

    void retrieveWifiInformation();
    void testConnectionSpeed();
    void setConnectionStats();
    void retrieveSSID();
    mutable std::condition_variable cv;

public:
    NetworkController();
    const char* getWifiIP() const;
    const char* getAddressIPv6() const;
    const std::string& getWifiMacAddress() const;
    const std::string& getWifiSSID() const;
    ConnectionStats getConnectionSpeed() const;
};


#endif //CPUSTATS_NETWORK_CONTROLLER_H
