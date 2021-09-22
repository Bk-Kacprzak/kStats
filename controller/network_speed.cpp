//
// Created by Bartłomiej Kacprzak on 18/09/2021.
//

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

