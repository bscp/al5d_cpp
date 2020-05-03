#!/bin/bash

# Set default values
BUILD_METHOD="REBUILD"
BUILD_TYPE="release"

# Parse specified flags
# -m stands for method or build_method
# -t stands for type or build_type
while getopts m:t: option; do
    case "${option}" in
        m) BUILD_METHOD=${OPTARG};;
        t) BUILD_TYPE=${OPTARG};;
    esac
done

# Format the BUILD_METHOD input
BUILD_METHOD=${BUILD_METHOD,,} # make all letters lowercase
BUILD_METHOD=${BUILD_METHOD:0:1} # take first letter

# Remove current build directory on clean build
if [ "$BUILD_METHOD" = "c" ] ; then
    rm -rf ./build
fi

# Make sure the build directory exists and it is the workspace
mkdir build -p

# Generate the build files and build with 8 threads
# The parenthesis mean the directory change is only for this command
(cd build && cmake -DCMAKE_BUILD_TYPE=$BUILD_TYPE .. && make -j 8)
