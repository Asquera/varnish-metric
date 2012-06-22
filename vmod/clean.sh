#!/bin/bash

#
# A clean script that removes all generated files and folders
#

# src folder
rm -r src/.deps/
rm -r src/.libs/
rm src/Makefile
rm src/Makefile.in
rm src/vcc_if.c
rm src/vcc_if.h
rm src/vcc_if.lo

rm -r autom4te.cache/
rm -r m4/

# files
rm *.m4
rm clean
rm config.*
rm configure
rm depcomp
rm install-sh
rm libtool
rm ltmain.sh
rm Makefile
rm Makefile.in
rm missing
rm stamp-h1