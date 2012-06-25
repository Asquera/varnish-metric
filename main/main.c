#include <stdlib.h>
#include <stdio.h>

#include <metric/statsd_send.h>
#include <metric/socket.h>

int main(int argc, char* argv[]) {
    
    const char* hostname = "localhost";
    int port = 3000;

    int socketfd = socket_connect_client(hostname, port);
    if (socketfd < 0) {
        return -1;
    }
    socket_write_string("This is a test string and should appear somewhere!", socketfd);
    
    return 0;
}
