#include <iostream> //to delete
#include "network_controller.h"

NetworkController::NetworkController() {
    memset(addressIPv6, 0, sizeof(addressIPv6));
    memset(wifiIP, 0, sizeof(wifiIP));

    retrieveWifiInformation();
    retrieveSSID();


    std::cout<<"Wifi SSID: " <<wifiSSID;
    std::cout<<"Wifi IP Address: " << wifiIP << std::endl;
    if(strlen(addressIPv6) == 0)
        std::cout<< "Unknown IPv6 address. \n";
    else
        std::cout<<"IPv6 Address: " <<addressIPv6<<std::endl;

    std::cout << "Wi-Fi MAC Address: " << wifiMACAddress << std::endl;
    setConnectionStats();

}

void NetworkController::retrieveWifiInformation() {

    ifaddrs * ifAddr = nullptr;
    ifaddrs * currentAddr = nullptr;
    void * tempAddrPtr = nullptr;
    getifaddrs(&ifAddr);

    for (currentAddr = ifAddr; currentAddr != nullptr; currentAddr = currentAddr->ifa_next) {
        //IPv4
        if (currentAddr->ifa_addr->sa_family == AF_INET) {
            tempAddrPtr=&((struct sockaddr_in *)currentAddr->ifa_addr)->sin_addr;
            IPv4 addressBuffer;
            inet_ntop(AF_INET, tempAddrPtr, addressBuffer, INET_ADDRSTRLEN);
            if(strncmp(addressBuffer,"127",3) != 0) {
                memmove(wifiIP, addressBuffer, INET_ADDRSTRLEN);
            }
        }
        //IPv6
        else if (currentAddr->ifa_addr->sa_family == AF_INET6) {
            if(strlen(addressIPv6) > 0)
                continue;

            tempAddrPtr = &((struct sockaddr_in6*)currentAddr->ifa_addr)->sin6_addr;
            inet_ntop(AF_INET6, tempAddrPtr, addressIPv6, INET6_ADDRSTRLEN);
            std::string temp_addr = addressIPv6;
            int contains_ipv6_address = temp_addr.find("fd88:");
            if(contains_ipv6_address==std::string::npos)
                memset(addressIPv6, 0, sizeof(addressIPv6));
        }

        //Link layer interface
        else if (currentAddr->ifa_addr->sa_family == AF_LINK) {
            if(!wifiMACAddress.empty())
                continue;
            wifiMACAddress = link_ntoa((struct sockaddr_dl*)currentAddr->ifa_addr);
            int contains_mac_address = wifiMACAddress.find("en0:");

            if(contains_mac_address==std::string::npos)
                wifiMACAddress.clear();
            else {
                wifiMACAddress.erase(wifiMACAddress.begin(), wifiMACAddress.begin() + 4);
            }

        }
    }

    if (ifAddr) {
        freeifaddrs(currentAddr);
        freeifaddrs(ifAddr);
        currentAddr, ifAddr, tempAddrPtr = nullptr;
    }
}

void NetworkController::setConnectionStats() {
    testConnectionSpeed();
//    threadPool.push([=] {});
}

void NetworkController::testConnectionSpeed() {
    knet::NetworkSpeed::initializeClient();
    knet::NetworkSpeed::initializeServer();
    connectionSpeed = knet::NetworkSpeed::retrieveData();
}
void NetworkController::retrieveSSID() {
    const char* wifi = "/System/Library/PrivateFrameworks/Apple80211.framework/Versions/Current/Resources/airport -I | grep -w SSID: ";
    char buffer[128];
    std::shared_ptr<FILE> pipe(popen(wifi, "r"), pclose);
    if(!pipe)
        throw std::runtime_error("popen() failed!\n");

    while(!feof(pipe.get())){
        if(fgets(buffer,128, pipe.get())) {
            wifiSSID = buffer;
            break; //to check
        }
    }
    if(wifiSSID.empty())
        std::cout<<"Wifi connection not found. \n";
    else
        wifiSSID = wifiSSID.replace(0, wifiSSID.find(":") + 2, "");
}
const char* NetworkController::getWifiIP() const {
    return wifiIP;
}

std::string NetworkController::getWifiMacAddress() const {
    return std::string();
}

std::string NetworkController::getWifiSSID() const {
    return std::string();
}

ConnectionStats NetworkController::getConnectionSpeed() {
    return ConnectionStats();
}

const char *NetworkController::getAddresIPv6() const {
    return addressIPv6;
}


