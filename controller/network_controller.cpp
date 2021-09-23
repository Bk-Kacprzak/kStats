#include <iostream> //to delete
#include "network_controller.h"

NetworkController::NetworkController() {
    memset(addressIPv6.value, 0, sizeof(addressIPv6.value));
    memset(wifiIP.value, 0, sizeof(wifiIP.value));
    wifiMACAddress.value.clear();
    wifiSSID.value.clear();


    threadPool.push([this] {
        retrieveSSID();
        retrieveWifiInformation();
    });
    retrieveWifiInformation();
    retrieveSSID();


    std::cout<<"Wifi SSID: " <<wifiSSID.value;
    std::cout<<"Wifi IP Address: " << wifiIP.value << std::endl;
    if(strlen(addressIPv6.value) == 0)
        std::cout<< "Unknown IPv6 address. \n";
    else
        std::cout<<"IPv6 Address: " <<addressIPv6.value<<std::endl;

    std::cout << "Wi-Fi MAC Address: " << wifiMACAddress.value << std::endl;
    setConnectionStats();

}

void NetworkController::retrieveWifiInformation() {
    std::lock(wifiIP.mtx,addressIPv6.mtx,wifiMACAddress.mtx);
    memset(wifiIP.value, 0, sizeof(wifiIP.value));
    wifiIP.mtx.unlock();
    memset(addressIPv6.value, 0, sizeof(addressIPv6.value));
    addressIPv6.mtx.unlock();
    wifiMACAddress.value.clear();
    wifiMACAddress.mtx.unlock();

    ifaddrs * ifAddr = nullptr;
    ifaddrs * currentAddr = nullptr;
    void * tempAddrPtr = nullptr;
    getifaddrs(&ifAddr);

    IPv4 inet_addr;
    IPv6 inet6_addr;
    std::string mac_addr;

    for (currentAddr = ifAddr; currentAddr != nullptr; currentAddr = currentAddr->ifa_next) {
        //IPv4
        if (currentAddr->ifa_addr->sa_family == AF_INET) {
            tempAddrPtr=&((struct sockaddr_in *)currentAddr->ifa_addr)->sin_addr;
            inet_ntop(AF_INET, tempAddrPtr, inet_addr, INET_ADDRSTRLEN);
            if(strncmp(inet_addr,"127",3) != 0) {
                std::lock_guard<std::mutex> lock(wifiIP.mtx);
                memmove(wifiIP.value, inet_addr, INET_ADDRSTRLEN);
            }
        }
        //IPv6
        else if (currentAddr->ifa_addr->sa_family == AF_INET6) {
            if(strlen(inet6_addr) > 0)
                continue;

            tempAddrPtr = &((struct sockaddr_in6*)currentAddr->ifa_addr)->sin6_addr;

            inet_ntop(AF_INET6, tempAddrPtr, inet6_addr, INET6_ADDRSTRLEN);
            std::string temp_addr = inet6_addr;
            int contains_ipv6_address = temp_addr.find("fd88:");
            if(contains_ipv6_address!=std::string::npos) {
                std::lock_guard<std::mutex> lock(addressIPv6.mtx);
                memmove(addressIPv6.value, inet6_addr, INET6_ADDRSTRLEN);
            }
            else
                memset(inet6_addr, 0, sizeof(inet6_addr));
        }

        //Link layer interface
        else if (currentAddr->ifa_addr->sa_family == AF_LINK) {
            if(!mac_addr.empty())
                continue;
            mac_addr = link_ntoa((struct sockaddr_dl*)currentAddr->ifa_addr);
            int contains_mac_address = mac_addr.find("en0:");

            if(contains_mac_address==std::string::npos)
                mac_addr.clear();
            else {
                mac_addr.erase(mac_addr.begin(), mac_addr.begin() + 4);
                std::lock_guard<std::mutex> lock(wifiMACAddress.mtx);
                wifiMACAddress.value = std::move(mac_addr);
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
    connectionSpeed.value = std::move(knet::NetworkSpeed::retrieveData());
}
void NetworkController::retrieveSSID() {
    const char* wifi = "/System/Library/PrivateFrameworks/Apple80211.framework/Versions/Current/Resources/airport -I | grep -w SSID: ";
    char buffer[128];
    std::shared_ptr<FILE> pipe(popen(wifi, "r"), pclose);
    if(!pipe)
        throw std::runtime_error("popen() failed!\n");

    std::string ssid;
    while(!feof(pipe.get())) {
        if(fgets(buffer,128, pipe.get())) {
//            std::lock_guard<std::mutex> lock(wifiSSID.mtx);
            ssid = buffer;
            break; //to check
        }
    }
    if(ssid.empty())
        std::cout<<"Wifi connection not found. \n";
    else {
        ssid = ssid.replace(0, ssid.find(":") + 2, "");
        std::lock_guard<std::mutex> lock(wifiSSID.mtx);
        wifiSSID.value = std::move(ssid);
    }
}

const char *NetworkController::getAddressIPv6() const {
    std::unique_lock<std::mutex> lock(addressIPv6.mtx);
    cv.wait(lock,[this] {
        return strlen(addressIPv6.value) > 0;
    });
    return addressIPv6.value;
}

std::string NetworkController::getWifiMacAddress() const {
    std::unique_lock<std::mutex> lock(wifiMACAddress.mtx);
    cv.wait(lock,[this] {
        return !wifiMACAddress.value.empty();
    });
    return wifiMACAddress.value;
}

std::string NetworkController::getWifiSSID() const {
    std::unique_lock<std::mutex> lock(wifiSSID.mtx);
    cv.wait(lock,[this] {
        return !wifiSSID.value.empty();
    });
    return wifiSSID.value;
}

ConnectionStats NetworkController::getConnectionSpeed() const {
    std::unique_lock<std::mutex> lock(connectionSpeed.mtx);
    cv.wait(lock,[this] {
        return connectionSpeed.value.latency != -1;
    });
    return connectionSpeed.value;
}

const char *NetworkController::getWifiIP() const {
    std::unique_lock<std::mutex> lock(wifiIP.mtx);
    cv.wait(lock,[this] {
        return strlen(wifiIP.value) > 0;
    });
    return wifiIP.value;
}
