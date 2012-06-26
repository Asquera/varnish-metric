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

void vmod_init_client(struct sess* sp, const char* hostname, int hostport) {
    host = hostname;
    port = hostport;
    socket_connect();
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

void vmod_gauge(struct sess* sp, const char* name, int value) {
    socket_connect();
    gauge(socketfd, name, value);
}

void vmod_timer(struct sess* sp, const char* name, int value) {
    socket_connect();
    timer(socketfd, name, value);
}
