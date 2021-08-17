#!/bin/bash

MODE=Debug
if [ $# -gt 0 ]
then
    MODE = $1
fi

if [ -d build ]
then
    rm -r build
fi

mkdir build
cd build

cmake -DCMAKE_BUILD_TYPE=$MODE ..
make