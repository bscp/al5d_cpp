#!/bin/bash

# Installing basically means moving library files
# to a directory where the system is able to find it.

# Run a 'clean' 'release' build
scripts/build.sh -m clean_build -t release

# Install the build files
sudo cmake --build ./build --target install
