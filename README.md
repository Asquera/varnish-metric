varnish-metric
==============

This [varnish](https://www.varnish-cache.org/) module can be used for
sending [statsd](https://github.com/etsy/statsd)
compatible metrics over a udp connection. It is for those situations where varnish stats
might not suffice or when the behavior under very specific conditions is of interest.

### Prerequisites

Dependening on the system setup it might be necessary to install the following packages

* [libtool](http://www.gnu.org/software/libtool/libtool.html)
* [libpcre](http://pcre.org/)

For example in Ubuntu:

    sudo apt-get install libpcre3-dev libtool


### Installation

Download the [varnish source](https://www.varnish-cache.org/releases).
Unpack it to a folder and follow the instructions in the `INSTALL` file.
This should build varnish from source and install it on the system.
In order to compile a varnish module successfully, path variables to the varnish source
and the vmods folder are necessary.
Either provide them by specifying environment variables.

    export VARNISHSRC=path/to/varnish_src
    export VMODDIR=/usr/local/lib/varnish/vmods/ # path might differ

or by providing these variables when calling the `configure` script.

    ./configure VARNISHSRC=path/to/varnish_src VMODDIR=/usr/local/lib/varnish/vmods/


The following steps install the metric vmod.

    cd vmod
    sh autogen.sh
    ./configure
    make
    make install

Running the `autogen` script can result in an error message, stating the "*required file `ltmain.sh` not found*".
It is [suggested to re-run](https://www.varnish-cache.org/trac/wiki/Installation) the script a second time.


To clean everything, execute the `clean` shell script in the **vmod** folder. This removes all generated
files and directories.


The metric module was tested against varnish 3.0.2 on Ubuntu Linux 11.10 (64 bit).


### Usage

To see which functions are available check the [documentation](https://github.com/Asquera/varnish-metric/wiki/Documentation).

After the metric module is installed in the vmods folder the metric module can be used in the VCL script.
For example to count the number of requested images:

    import metric;
    backend default {
        .host = "127.0.0.1";
        .port = "8080";
    }
    sub vcl_init {
        /* sets up udp connection */
        metric.init_client("localhost", 8125);
        return (ok);
    }
    sub vcl_recv {
        if (req.url ~ "\.(png|gif|jpg)$") {
            metric.inc_counter("requested_images");
        }
    }

**Note** It is advised to set up the socket connection in the function `vcl_init`. This method is called once at start up of the varnish module.