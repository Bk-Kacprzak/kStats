#include <iostream> //to delete
#include "network_model.h"
#include <iomanip>

#define CHAR_SIZE(_PTR)  (strlen(_PTR) + 1)

NetworkModel::NetworkModel() : isTesting(false) {
    memset(addressIPv6.value, 0, sizeof(addressIPv6.value));
    memset(wifiIP.value, 0, sizeof(wifiIP.value));
    wifiMACAddress.value.clear();
    wifiSSID.value.clear();
    threadPool.push([&] {
        retrieveWifiInformation();
        std::cout<<"Wifi IP Address: " <<WifiIP() << std::endl;
        std::cout<<"IPv6 Address: " << AddressIPv6()<<std::endl;
        std::cout << "Wi-Fi MAC Address: " << WifiMacAddress() << std::endl;
    });

    threadPool.push([&] {
        retrieveSSID();
        std::cout<<"Wifi SSID: " <<WifiSSID()<<std::endl;
    });
//    threadPool.push([&] {
//        setConnectionStats();
//    });
}

void NetworkModel::retrieveWifiInformation() {
    IPv4 inet_addr;
    IPv6 inet6_addr;
    std::string mac_addr;
    memset(inet_addr, 0, sizeof(inet_addr));
    memset(inet6_addr, 0, sizeof(inet6_addr));

    ifaddrs * ifAddr = nullptr;
    ifaddrs * currentAddr = nullptr;
    void * tempAddrPtr = nullptr;
    getifaddrs(&ifAddr);

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

    if(strlen(addressIPv6.value) == 0)  {
        const char *message = "Unknown IPv6 address";
        memmove(addressIPv6.value, message, CHAR_SIZE(message));
    }
    if(strlen(wifiIP.value) == 0)  {
        const char *message = "Unknown IP address";
        memmove(wifiIP.value, message, CHAR_SIZE(message));
    }
    if(wifiMACAddress.value.empty())  {
        const char* message = "Unknown MAC address";
        memmove(addressIPv6.value, message, CHAR_SIZE(message));
    }


    if (ifAddr) {
        freeifaddrs(currentAddr);
        freeifaddrs(ifAddr);
        currentAddr = nullptr;
        ifAddr = nullptr;
        tempAddrPtr = nullptr;
    }
}

void NetworkModel::setConnectionStats() {
        isTesting.mtx.lock();
        isTesting.mtx.lock();

        if(!isTesting.value) {
            isTesting.value = true;
            std::cout << "Setting connection speed\n";
            //removed for test
//            threadPool.push([&] {
                testConnectionSpeed();
//            });
        }

}

void NetworkModel::testConnectionSpeed() {

//    connectionSpeed.value = std::move(knet::NetworkSpeed::retrieveData());
}
void NetworkModel::retrieveSSID() {
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

const char* NetworkModel::AddressIPv6() const {
    //todo: prevent from std::__1::system_error: mutex lock failed: Invalid argument
    //
//    std::unique_lock<std::mutex> lock(addressIPv6.mtx);
//    cv.wait(lock,[this] {
//        return strlen(addressIPv6.value) > 0;
//    });
//    return addressIPv6.value;
return "";
}

const std::string& NetworkModel::WifiMacAddress() const {
    std::unique_lock<std::mutex> lock(wifiMACAddress.mtx);
    cv.wait(lock,[this] {
        return !wifiMACAddress.value.empty();
    });
    return wifiMACAddress.value;
}

const std::string& NetworkModel::WifiSSID() const {
    std::unique_lock<std::mutex> lock(wifiSSID.mtx);
    cv.wait(lock,[this] {
        return !wifiSSID.value.empty();
    });
    return wifiSSID.value;
}

ConnectionStats& NetworkModel::ConnectionSpeed()  {
    //if connection.value is not set -> wait for results
    std::unique_lock<std::mutex> lock(isTesting.mtx);
    std::cout<<"IM LOCKING! \n";

    cv.wait(lock, [=] {
        return !isTesting.value;
    });
    std::cout<<"Waiting here";
    return connectionSpeed.value;
}

const char *NetworkModel::WifiIP() const {
    std::unique_lock<std::mutex> lock(wifiIP.mtx);
    cv.wait(lock,[this] {
        return strlen(wifiIP.value) > 0;
    });
    return wifiIP.value;
}

bool NetworkModel::IsTestingConnection() {
    return isTesting.value;
}

void NetworkModel::lockConnectionSpeedTest() {
    isTesting.mtx.try_lock();
    if(!isTesting.value) {
        isTesting.value = true;
        isTesting.mtx.unlock();

        curl_global_init(CURL_GLOBAL_ALL); // good place for curl init ????
        std::cout << "Setting connection speed\n";
        testConnectionSpeed();
        knet::NetworkSpeed::initializeClient();

    } else {
        throw std::runtime_error("Connection speed test bug - NetworkModel::lockConnectionSpeedTest()\n");
    }
}


std::string NetworkModel::getBestServer() {
    std::lock_guard<std::mutex> lock(connectionSpeed.mtx);

    connectionSpeed.value.best_server = knet::NetworkSpeed::initializeServer();
    connectionSpeed.value.best_server.erase(connectionSpeed.value.best_server.end()-5, connectionSpeed.value.best_server.end());
    return connectionSpeed.value.best_server;
}

float NetworkModel::getDownloadSpeed() {
    std::lock_guard<std::mutex> lock(connectionSpeed.mtx);
    connectionSpeed.value.download_speed = knet::NetworkSpeed::retreiveDownloadSpeed();
    return connectionSpeed.value.download_speed;
}

float NetworkModel::getUploadSpeed() {
    std::lock_guard<std::mutex> lock(connectionSpeed.mtx);
    connectionSpeed.value.upload_speed = knet::NetworkSpeed::retreiveUploadSpeed();
    return connectionSpeed.value.upload_speed;

}

int NetworkModel::getLatency() {
    std::lock_guard<std::mutex> lock(connectionSpeed.mtx);
    connectionSpeed.value.latency = knet::NetworkSpeed::retrieveLatency();
    return connectionSpeed.value.latency;
}

void NetworkModel::closeConnectionSpeedTest() {
    std::lock_guard<std::mutex> lock(isTesting.mtx);
    isTesting.value = false;
}
