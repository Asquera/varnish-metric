#include <stdlib.h>
#include <stdio.h>

#include <metric/socket.h>

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
    dec_counter(socketfd, "test");
    dec_counter(socketfd, "test");
    dec_counter(socketfd, "test");
    dec_counter_by_value(socketfd, "test", 8);

    socket_close(socketfd);

    return 0;
}
