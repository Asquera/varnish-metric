#include <stdlib.h>
#include <stdio.h>

#include <metric/statsd_client.h>

int main(int argc, char* argv[]) {
    
    const char* hostname = "localhost";
    int port = 8125;

    int socketfd = socket_connect_client(hostname, port);
    if (socketfd < 0) {
        printf("Could not connect client!");
        return -1;
    }

    inc_counter(socketfd, "test");
    inc_counter_by_value(socketfd, "test", 10);
    gauge(socketfd, "single_gauge", 22);
    timer(socketfd, "first_timer", 4000);

    socket_close(socketfd);

    return 0;
}
