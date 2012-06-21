#!/bin/bash

#
# A clean script that removes all generated files and folders
#

# folders
rm -r autom4te.cache/
rm -r m4/

# files
rm *.m4
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