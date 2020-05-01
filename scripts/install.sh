#!/bin/bash

# Installing basically means moving library files
# to a directory where the system is able to find it.

# Run the build script
scripts/build.sh Release

# Install the build files
sudo cmake --build ./build --target install
