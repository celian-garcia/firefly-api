#!/bin/bash
rm -rf build;
mkdir build;
cd build;
cmake -DPostgreSQL_TYPE_INCLUDE_DIR=/usr/include/postgresql ..;
make -j4;