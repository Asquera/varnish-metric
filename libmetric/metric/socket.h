#ifndef __SOCKET_H
#define __SOCKET_H

int socket_connect_client(const char* hostname, int port);
int socket_connect_server(const char* hostname, int port);
void socket_close();

#endif
