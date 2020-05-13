#!/bin/bash
# This script builds the project and then moves the result
# to a system directory. This moving is called installing

# Set default values
INSTALL_DEPENDENCIES=false

# Parse specified flags
while getopts d option; do
    case "${option}" in
        d) INSTALL_DEPENDENCIES=true;
    esac
done

# Install dependencies first 
if [ "$INSTALL_DEPENDENCIES" = true ] ; then
    scripts/install_dependencies.sh
fi

# Run a build with method='clean' type='release'
scripts/build.sh -m clean_build -t release

# Install the build files
cmake --build ./build --target install
