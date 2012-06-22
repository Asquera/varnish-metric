#ifndef __STATSD_SEND_H
#define __STATSD_SEND_H

/// Increments a counter with a given name by 1
void inc_counter(const char* name);
/// Increments a counter with a given name by value
void inc_counter_by_value(const char* name, int value);
/// Decrements a counter with a given name by 1
void dec_counter(const char* name);
/// Decrements a counter with a given name by value
void dec_counter_by_value(const char* name, int value);

#endif