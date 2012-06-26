#ifndef __SOCKET_H
#define __SOCKET_H

/// Opens a udp socket connection with given host and port
/// Returns a socket file descriptor if successful or -1 if the connection
/// could not be established
int socket_connect_client(const char* host, int port);

/// Closes an open socket connection associated with the given socket file descriptor
void socket_close(int socketfd);

/// Increments a counter with a given name by 1
int inc_counter(int socketfd, const char* name);

/// Increments a counter with a given name by value
int inc_counter_by_value(int socketfd, const char* name, int value);

/// Decrements a counter with a given name by 1
int dec_counter(int socketfd, const char* name);

/// Decrements a counter with a given name by value
int dec_counter_by_value(int socketfd, const char* name, int value);


#endif
