#include "socket.h"

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <netdb.h>
#include <fcntl.h>
#include <errno.h>

// global variables
int stats_udp_socketfd = 0;
struct hostent* stats_server = 0;
struct sockaddr_in server_address;

void cleanup();

/// exits the application with an error message
void exit_with_error(const char* message) {
    perror(message);
    cleanup();
}

int socket_connect_client(const char* hostname, int port) {
    stats_udp_socketfd = socket(AF_INET, SOCK_STREAM, 0);
    if (stats_udp_socketfd < 0) {
        exit_with_error("Could not open socket");
        return -1;
    }
    
    stats_server = gethostbyname(hostname);
    if (stats_server == 0) {
        exit_with_error("Coult not get host by name!");
        return -1;
    }
    
    // set up server address connection
    memset((char*) &server_address, 0, sizeof(server_address));
    server_address.sin_family = AF_INET;
    memcpy((char*) &stats_server->h_addr, (char*) &server_address.sin_addr.s_addr, stats_server->h_length);
    server_address.sin_port = htons(port);
    
    struct sockaddr* address = (struct sockaddr*)&server_address;
    int result = connect(stats_udp_socketfd, address, sizeof(server_address));
    if (result < 0) {
        exit_with_error("Could not connect to server address");
        return -1;
    }
}

/// opens a socket connection to hostname:port
int socket_connect_server(const char* hostname, int port) {
    stats_udp_socketfd = socket(AF_INET, SOCK_DGRAM, 0);
    if (stats_udp_socketfd < 0) {
        exit_with_error("Could not open socket");
        return -1;
    }
    
    // reuse socket
    int on = 1;
    if (setsockopt(stats_udp_socketfd, SOL_SOCKET, SO_REUSEADDR, &on, sizeof(on)) != 0) {
        exit_with_error("Could not socket option");
        return -1;
    }
    
    // use non-blocking sockets
    int flags = fcntl(stats_udp_socketfd, F_GETFL, 0);
    fcntl(stats_udp_socketfd, F_SETFL, flags | O_NONBLOCK);
    
    // bind socket to a specific port
    struct sockaddr_in sock_addr;
    memset ((char*) &sock_addr, 0, sizeof(sock_addr));
    sock_addr.sin_family = AF_INET;
    sock_addr.sin_port   = htons(port);
    sock_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    if (bind(stats_udp_socketfd, (struct sockaddr*) &sock_addr, sizeof(sock_addr)) == -1) {
        exit_with_error("Could not bind port");
        return -1;
    }
    
    stats_server = gethostbyname(hostname);
    if (stats_server == 0) {
        exit_with_error("Could not get host by name");
        return -1;
    }
}

/// Closes the existing socket connection
void socket_close() {
    if (stats_udp_socketfd != 0) {
        close(stats_udp_socketfd);
        stats_udp_socketfd = 0;
    }
}

void cleanup() {
    // TODO?
}


