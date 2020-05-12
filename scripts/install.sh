#!/bin/bash
# This script builds the project and then moves the result
# to a system directory. This moving is called installing

# Install dependencies first 
scripts/install_dependencies.sh

# Run a 'clean' 'release' build
scripts/build.sh -m clean_build -t release

# Install the build files
sudo cmake --build ./build --target install
