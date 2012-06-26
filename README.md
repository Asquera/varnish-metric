varnish-metric
==============

This varnish module (vmod) is used for sending statsd-compatible metrics over a udp connection to specific host. It is for those situations where varnish stats might not suffice or when the behavior under very specific conditions is of interest.

### Prerequisites

Dependening on the system setup it might be necessary to install the following packages

* libtool
* libpcre

For example in Ubuntu:

    sudo apt-get install libpcre3-dev
    sudo apt-get install libtool autopoint


### Installation

Download the [varnish source](https://www.varnish-cache.org/releases).
Unpack it to a folder and follow the instructions in the `INSTALL` file.
This should build varnish from source and install it on the system.
In order to compile a varnish module successfully, path variables to the varnish source
and the vmods folder are necessary and must be made available.
Either by specifying environment variables.

    export VARNISHSRC=path/to/varnish_src
    export VMODDIR=/usr/local/lib/varnish/vmods/ // path might differ

or by providing these variables when calling the `configure` script.

    ./configure VARNISHSRC=path/to/varnish_src VMODDIR=/usr/local/lib/varnish/vmods/


The following steps install the metric vmod.

    cd vmod
    sh autogen.sh
    ./configure
    make
    make install

Running the `autogen` script can result in an error message, stating the "required file `ltmain.sh` not found".
It is [suggested to re-run](http://developer.wz2100.net/ticket/349) the script a second time.


To clean everything, execute the `clean` shell script in the **vmod** folder. This removes all generated
files and directories.



### Usage

After the metric module is installed in the vmods folder the metric module can be used in the VCL script.
For example to measure the metric of requested images:

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
        if (req.url ~ "\.(png|gif|jpg)$") {
            metric.inc_counter("requested_images");
        }
    }

**Note** the socket connection is established in the function `vcl_init`. This method is called once
when the varnish module is started.
