#!/bin/bash
# This script generates build files with cmake and then
# builds the executable. It supports a few flags they are
# descriped below. The accepted values are noted between []
# and separated with a |. The first one is the default.
# -m [rebuild|cleanbuild] stands for method or build_method
# -t [release|debug] stands for type or build_type
# The script only looks at the first letter of the -m flag value
# so you can write clean, cleanbuild, c, etc. It all works

# Set default values
BUILD_METHOD="REBUILD"
BUILD_TYPE="release"

# Parse specified flags
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
