#ifndef CPUSTATS_NETWORK_CONTROLLER_H
#define CPUSTATS_NETWORK_CONTROLLER_H

#include <sys/types.h>
#include <ifaddrs.h>
#include <arpa/inet.h>
#include <net/if_dl.h>
#include <sys/socket.h>
#include <netinet/in.h>
//#include <SystemConfiguration/SystemConfiguration.h>
//#include "Utils/transmitionspeed.h"
#include "network_speed.h"
#include "generic_class.h"
#include <condition_variable>

template<typename T>
struct ValueContainer {
    std::mutex mtx;
    T value;
};

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
    std::string getWifiMacAddress() const;
    std::string getWifiSSID() const;
    ConnectionStats getConnectionSpeed() const;

};


#endif //CPUSTATS_NETWORK_CONTROLLER_H
