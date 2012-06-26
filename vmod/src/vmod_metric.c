#include <stdlib.h>
#include <stdio.h>

#include "../../libmetric/metric/statsd_client.h"

#include "vrt.h"
#include "bin/varnishd/cache.h"
#include "vcc_if.h"

char* host;
int socketfd = -1;
int port;

static int socket_connect() {
    if (socketfd < 0) {
        socketfd = socket_connect_client(host, port);
    }
    return socketfd;
}

int init_function(struct vmod_priv* priv, const struct VCL_conf* conf)
{
    // get values from vcl config
    host = "localhost";
    port = 8125;
    return socket_connect();
}

void vmod_inc_counter(struct sess* sp, const char* name) {
    socket_connect();
    inc_counter(socketfd, name);
}

void vmod_inc_counter_by_value(struct sess* sp, const char* name, int value) {
    socket_connect();
    inc_counter_by_value(socketfd, name, value);
}

void vmod_dec_counter(struct sess* sp, const char* name) {
    socket_connect();
    dec_counter(socketfd, name);
}

void vmod_dec_counter_by_value(struct sess* sp, const char* name, int value) {
    socket_connect();
    dec_counter_by_value(socketfd, name, value);
}

