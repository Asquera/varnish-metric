import metric;
backend default {
    .host = "127.0.0.1";
    .port = "8080";
}

sub vcl_init {
    metric.init_client("localhost", 8125);
    return (ok);
}

sub vcl_recv {
    /* log the number of requested images */
    if (req.url ~ "\.(png|gif|jpg)$") {
        metric.inc_counter("requested_images");
    }
}
