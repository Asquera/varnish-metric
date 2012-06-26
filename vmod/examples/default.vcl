backend default {
    .host = "127.0.0.1";
    .port = "3000";
}

import metric;

sub vcl_recv {
    metric.inc_counter_by_value("test", 10);
}