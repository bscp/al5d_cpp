# al5d_cpp

This repository provides a library which allows you to execute low level functionality on the Lynxmotion AL5D robot arm.

To discover all capabilities of this library, take a look at the <code>examples</code> directory. An incomplete list of provided functionality is:
* Move specific joints to an pwm angle.
* Move specific joints to an angle in degree.
* Perform an emergency stop.

## Installation
1. First make sure you have a local copy of this repository on your workstation.
1. Then <code>cd</code> into the root of this repository.
1. Now run <code>sudo scripts/install.sh</code> to build and install the repository.

## Usage

1. Place <code>find_package(al5d_cpp REQUIRED)</code> into the CMakeLists.txt file of your own project.
1. Now you can include headers like <code>#include <al5d_cpp/AL5D.hpp></code>.
1. Take a look at the example code in the <code>examples</code> to get started quickly.

## Improvements
* Add support for the AL5D model without wrist rotation.
