#include <stdlib.h>
#include <stdio.h>

#include <metric/statsd_send.h>
#include <metric/socket.h>

int main(int argc, char* argv[]) {
    
    const char* hostname = "localhost";
    int port = 3001;

    if (socket_connect_client(hostname, port) != 0) {
        return -1;
    }
    socket_close();
    
    return 0;
}
