varnish-module
==============

This vmod is used to retrieve interesting stats / metrics from varnish and send them as statsd compatible output to a host.

### Prerequisites

Dependening on the system setup it might be necessary to install the following packages

* libtool
* libpcre

For example in Ubuntu:

    sudo apt-get install libpcre3-dev
    sudo apt-get install libtool autopoint


### Installation

Download the [varnish source](https://www.varnish-cache.org/releases). Unpack it to a folder and follow the instructions in the *INSTALL* file.
This should build varnish from source and install it on the system.


The following steps install the Metric vmod.

    export VARNISHSRC=path/to/varnish/src
    export VMODDIR=/usr/local/lib/varnish/vmods/ // path might differ
    cd vmod
    sh autogen.sh
    ./configure
    make
    make install

Running the *autogen.sh* script can result in an error message, stating the "required file *ltmain.sh* not found".
It is [suggested to re-run](http://developer.wz2100.net/ticket/349) the script a second time.


To clean everything, execute the *clean.sh* shell script in the *vmod* folder. This removes all generated
files and directories.


### Usage

TODO
