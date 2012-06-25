#ifndef __SOCKET_H
#define __SOCKET_H

int socket_connect_client(const char* host, int port);
void socket_close(int socketfd);
int socket_write_string(const char* text, int socketfd);

#endif
