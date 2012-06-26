backend default {
    .host = "127.0.0.1";
    .port = "3000";
}

import metric;

sub vcl_init {
    metric.init_client("localhost", 8125);
    return (ok);
}

sub vcl_recv {
    metric.inc_counter("test");
    metric.inc_counter_by_value("test", 10);
}