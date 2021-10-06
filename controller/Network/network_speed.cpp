#include "network_speed.h"
char knet::NetworkSpeed::server_url[];
char knet::NetworkSpeed::ext[];
server_info knet::NetworkSpeed::servers[];
client_info knet::NetworkSpeed::client;

double knet::NetworkSpeed::latency = 0;
double knet::NetworkSpeed::speed = 0;
double knet::NetworkSpeed::download_speed = 0;
double knet::NetworkSpeed::upload_speed = 0;

int knet::NetworkSpeed::depth = 0;
int knet::NetworkSpeed::sindex = -1;
int knet::NetworkSpeed::num_thread = 4;
int knet::NetworkSpeed::dsize = INIT_DOWNLOAD_FILE_RESOLUTION;

ConnectionStats::ConnectionStats(const ConnectionStats &obj) : latency(obj.latency), download_speed(obj.download_speed), upload_speed(obj.upload_speed) {

}

ConnectionStats::ConnectionStats(ConnectionStats &&obj) : latency(obj.latency), download_speed(obj.download_speed), upload_speed(obj.upload_speed)  {

}

ConnectionStats::ConnectionStats(const double &_latency, const double &_download_speed, const double &_upload_speed)
: latency(_latency), download_speed(_download_speed), upload_speed(_upload_speed) {

}

ConnectionStats &ConnectionStats::operator=(ConnectionStats &&data) noexcept {
    if(this != &data) {
        this->latency = std::move(data.latency);
        this->download_speed = std::move(data.download_speed);
        this->upload_speed = std::move(data.upload_speed);
    }
    return *this;
}