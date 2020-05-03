FROM ubuntu:20.04


# Avoid warnings by switching to noninteractive
ENV DEBIAN_FRONTEND=noninteractive


# Install C++ development tools
RUN apt-get update > /dev/null 2>&1 \
    && apt-get -y install \
    #
    # GCC compiler
    build-essential \
    #
    # CMake for build file generation
    cmake \
    #
    # CPPCheck to detect code quality issues
    cppcheck \
    #
    # Valgrind to detect memory leaks
    valgrind \
    #
    # Git with nano as its text editor
    git nano \
    #
    # Dont output anything but errors
    > /dev/null 2>&1 \
    #
    # Clean up apt-get install files
    && apt-get autoremove -y > /dev/null 2>&1 \
    && apt-get clean -y > /dev/null 2>&1 \
    && rm -rf /var/lib/apt/lists/* > /dev/null 2>&1 \
    #
    # Install the Google test framework
    && git clone -q https://github.com/google/googletest.git /googletest > /dev/null 2>&1 \
    && mkdir -p /googletest/build > /dev/null 2>&1 \
    && (cd /googletest/build && cmake .. && make && make install > /dev/null 2>&1) \
    #
    # Clean up Google test framework install files
    && rm -rf /googletest > /dev/null 2>&1


# Install C++ libraries
RUN apt-get update > /dev/null 2>&1 \
    && apt-get -y install \
    #
    # Boost for serial library
    libboost-all-dev \
    #
    # Dont output anything but errors
    > /dev/null 2>&1 \
    #
    # Clean up apt-get install files
    && apt-get autoremove -y > /dev/null 2>&1 \
    && apt-get clean -y > /dev/null 2>&1 \
    && rm -rf /var/lib/apt/lists/*> /dev/null 2>&1


# Install other development tools
RUN apt-get update > /dev/null 2>&1 \
    && apt-get -y install \
    #
    # PlantUML for UML modelling
    plantuml \
    #
    # Markdown for documents
    markdown \
    #
    # Dont output anything but errors
    > /dev/null 2>&1 \
    #
    # Clean up apt-get install files
    && apt-get autoremove -y > /dev/null 2>&1 \
    && apt-get clean -y > /dev/null 2>&1 \
    && rm -rf /var/lib/apt/lists/* > /dev/null 2>&1


# Switch back to dialog for any ad-hoc use of apt-get
ENV DEBIAN_FRONTEND=dialog
