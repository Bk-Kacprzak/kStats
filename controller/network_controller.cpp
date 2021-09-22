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
    memset(addressIPv6.value, 0, sizeof(addressIPv6.value));
    memset(wifiIP.value, 0, sizeof(wifiIP.value));
    wifiMACAddress.value.clear();

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
                //lock!
                memmove(wifiIP.value, addressBuffer, INET_ADDRSTRLEN);
            }
        }
        //IPv6
        else if (currentAddr->ifa_addr->sa_family == AF_INET6) {
            //lock!
            if(strlen(addressIPv6.value) > 0)
                continue;

            tempAddrPtr = &((struct sockaddr_in6*)currentAddr->ifa_addr)->sin6_addr;
            inet_ntop(AF_INET6, tempAddrPtr, addressIPv6.value, INET6_ADDRSTRLEN);
            std::string temp_addr = addressIPv6.value;
            int contains_ipv6_address = temp_addr.find("fd88:");
            if(contains_ipv6_address==std::string::npos)
                memset(addressIPv6.value, 0, sizeof(addressIPv6.value));
        }

        //Link layer interface
        else if (currentAddr->ifa_addr->sa_family == AF_LINK) {
            std::lock_guard<std::mutex> lock(controller_mutex);
            if(!wifiMACAddress.value.empty())
                continue;
            wifiMACAddress.value = link_ntoa((struct sockaddr_dl*)currentAddr->ifa_addr);
            int contains_mac_address = wifiMACAddress.value.find("en0:");

            if(contains_mac_address==std::string::npos)
                wifiMACAddress.value.clear();
            else {
                wifiMACAddress.value.erase(wifiMACAddress.value.begin(), wifiMACAddress.value.begin() + 4);
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

    while(!feof(pipe.get())) {
        if(fgets(buffer,128, pipe.get())) {
            std::lock_guard<std::mutex> lock(controller_mutex);
            wifiSSID.value = buffer;
            break; //to check
        }
    }
    if(wifiSSID.value.empty())
        std::cout<<"Wifi connection not found. \n";
    else {
        std::lock_guard<std::mutex> lock(controller_mutex);
        wifiSSID.value = wifiSSID.value.replace(0, wifiSSID.value.find(":") + 2, "");
    }
}

const char *NetworkController::getAddressIPv6() const {
    std::unique_lock<std::mutex> lock(controller_mutex);
    cv.wait(lock,[this] {
        return strlen(addressIPv6.value) > 0;
    });
    return addressIPv6.value;
}

std::string NetworkController::getWifiMacAddress() const {
    std::unique_lock<std::mutex> lock(controller_mutex);
    cv.wait(lock,[this] {
        return !wifiMACAddress.value.empty();
    });
    return wifiMACAddress.value;
}

std::string NetworkController::getWifiSSID() const {
    std::unique_lock<std::mutex> lock(controller_mutex);
    cv.wait(lock,[this] {
        return !wifiSSID.value.empty();
    });
    return wifiSSID.value;
}

ConnectionStats NetworkController::getConnectionSpeed() const {
    std::unique_lock<std::mutex> lock(controller_mutex);
    cv.wait(lock,[this] {
        return connectionSpeed.value.latency != -1;
    });
    return connectionSpeed.value;
}

const char *NetworkController::getWifiIP() const {
    std::unique_lock<std::mutex> lock(controller_mutex);
    cv.wait(lock,[this] {
        return strlen(wifiIP.value) > 0;
    });
    return wifiIP.value;
}


