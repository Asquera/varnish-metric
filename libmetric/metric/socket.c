#include "socket.h"
#include "dbg.h"

#ifdef HAVE_SYS_SOCKET_H
#include <sys/socket.h>
#endif

#ifdef HAVE_SYS_TYPES_H
#include <sys/types.h>
#endif

#include <arpa/inet.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <netinet/in.h>
#include <netdb.h>
#include <fcntl.h>

static void* get_socket_address(struct sockaddr* addr) {
    if (addr->sa_family == AF_INET) {
        return &(((struct sockaddr_in*)addr)->sin_addr);
    }
    return &(((struct sockaddr_in6*)addr)->sin6_addr);
}

int nonblock(int socketfd) {
    int flags = fcntl(socketfd, F_GETFL, 0);
    check(flags >= 0, "Invalid flags in nonblock.");
    
    int rc = fcntl(socketfd, F_SETFL, flags | O_NONBLOCK);
    check(rc == 0, "Can't set non-blocking.");
    
    return 0;
error:
    return 1;
}

int socket_connect_client(const char* host, int port) {
    int rc = 0;
    int socketfd = 0;
    struct addrinfo hints;
    struct addrinfo* server_info = 0;
    
    memset(&hints, 0, sizeof(hints));
    hints.ai_family   = AF_UNSPEC;
    hints.ai_socktype = SOCK_STREAM;
    
    char port_string[10];
    sprintf(port_string, "%d", port);
    
    rc = getaddrinfo(host, port_string, &hints, &server_info);
    check(rc == 0, "Failed to get address info.");
    
    socketfd = socket(server_info->ai_family, server_info->ai_socktype, server_info->ai_protocol);
    check(socketfd > 0, "Could not open socket.");
    
//    int on = 1;
//    rc = setsockopt(socketfd, SOL_SOCKET, SO_REUSEADDR, &on, sizeof(on));
//    check(rc == 0, "Failed to set socket option.");
    
    rc = connect(socketfd, server_info->ai_addr, server_info->ai_addrlen);
    check(rc != -1, "Failed to connect to server.");
    
    char address[INET6_ADDRSTRLEN];
    inet_ntop(server_info->ai_family,
              get_socket_address(server_info->ai_addr),
              address,
              sizeof(address));
    
    freeaddrinfo(server_info);
    return socketfd;
error:
    if (socketfd != 0) {
        close(socketfd);
    }
    freeaddrinfo(server_info);
    return -1;
}

int socket_write_string(const char* text, int socketfd) {
    int rc = 0;
    
    int text_length = strlen(text);
    rc = send(socketfd, text, text_length, 0);
    check(rc == text_length, "Failed to write everything.");
    
    return rc;
error:
    return -1;
}

void socket_close(int socketfd) {
    close(socketfd);
}

