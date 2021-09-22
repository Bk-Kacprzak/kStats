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

class NetworkController : public GenericClass {
    typedef char IPv4[INET_ADDRSTRLEN];
    typedef char IPv6[INET6_ADDRSTRLEN];
private:
    IPv4 wifiIP;
    IPv6 addressIPv6;
    std::string wifiMACAddress;
    std::string wifiSSID;
    ConnectionStats connectionSpeed;
    void retrieveWifiInformation();
    void testConnectionSpeed();
    void setConnectionStats();
    void retrieveSSID();
public:
    NetworkController();
    const char* getWifiIP() const;
    const char* getAddresIPv6() const;
    std::string getWifiMacAddress() const;
    std::string getWifiSSID() const;
    ConnectionStats getConnectionSpeed();

};


#endif //CPUSTATS_NETWORK_CONTROLLER_H
