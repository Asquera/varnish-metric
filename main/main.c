#include <stdlib.h>
#include <stdio.h>

#include <metric/statsd_send.h>
#include <metric/socket.h>

int main(int argc, char* argv[]) {
    
    const char* hostname = "localhost";
    int port = 3000;

    int socketfd = socket_connect_client(hostname, port);
    if (socketfd < 0) {
        printf("Could not connect client!");
        return -1;
    }
    
    int rc = socket_write_string("This is a test string and should appear somewhere!", socketfd);
    if (rc < 0) {
        printf("Failed to send string: %d", rc);
        return -1;
    }

    printf("Successfully sent a string");
    return 0;
}
