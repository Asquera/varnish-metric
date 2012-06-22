#include <stdio.h>
#include "statsd_send.h"

void inc_counter(const char* name) {
    inc_counter_by_value(name, 1);
}

void inc_counter_by_value(const char* name, int value) {
    // TODO
}

void dec_counter(const char* name) {
    dec_counter_by_value(name, 1);
}

void dec_counter_by_value(const char* name, int value) {
    // TODO
}
