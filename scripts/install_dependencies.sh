#!/bin/bash

# Install yaml-cpp dependency
git clone -q https://github.com/jbeder/yaml-cpp.git /yaml-cpp \
    && mkdir -p /yaml-cpp/build \
    && (cd /yaml-cpp/build && cmake .. -DYAML_BUILD_SHARED_LIBS=ON && make && make install) \
    && rm -rf /yaml-cpp
