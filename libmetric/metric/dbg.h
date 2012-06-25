#ifndef __DBG_H
#define __DBG_H

#include <stdio.h>
#include <errno.h> 
#include <string.h>


#define clean_errno() (errno == 0 ? "None" : strerror(errno))

#define log_error(M, ...) fprintf(stderr, "[ERROR] (%s:%d: errno: %s) " M "\n", __FILE__, __LINE__, clean_errno(), ##__VA_ARGS__)

#define check(C, M, ...) if (!(C)) { log_error(M, ##__VA_ARGS__); errno=0; goto error; }

#endif