#!/bin/bash
VARNISH_DIR=~/dev/working/varnish
VMODS_DIR=/usr/local/lib/varnish/vmods/

if [ ! -d m4 ]; then
    mkdir m4
fi

sh autogen.sh
sh autogen.sh
./configure VARNISHSRC=$VARNISH_DIR VMODDIR=$VMODS_DIR

make clean
make
sudo make install