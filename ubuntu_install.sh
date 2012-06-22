#!/bin/bash
#VARNISH_DIR=~/dev/working/varnish
#VMODS_DIR=/usr/local/lib/varnish/vmods/

cd vmod
sh autogen.sh
sh autogen.sh
./configure VARNISHSRC=~/dev/working/varnish/ VMODDIR=/usr/local/lib/varnish/vmods/

make clean
make
sudo make install