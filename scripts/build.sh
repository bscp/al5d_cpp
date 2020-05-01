#!/bin/bash

# Determine build type
BUILD_TYPE="Release"
if [ $# -gt 0 ]; then  # if any argument specified
    BUILD_TYPE=$1
fi

# Make sure the build directory exists and it is the workspace
mkdir build -p && cd build

# Generate the build files
cmake -DCMAKE_BUILD_TYPE=$BUILD_TYPE ..

# Build the program using the build files
make -j 8  # with 8 cpu threads
