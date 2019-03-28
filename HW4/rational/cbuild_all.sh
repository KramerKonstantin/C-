#!/usr/bin/env bash
set -e
mkdir build 
cd build
FLAGS="-DBUILD_SHARED_LIBS=OFF"
cmake -D CMAKE_INSTALL_PREFIX=$PWD/../install $FLAGS ..
make -j4
cmake -D COMPONENT=developer -P cmake_install.cmake

