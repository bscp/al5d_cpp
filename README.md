# al5d_cpp

This repository provides a installable library which allows you to execute low level functionality on the Lynxmotion AL5D robot arm.

The following code snippet provides a minimal example. To discover the many capabilities of this library, take a look at the examples in the <code>/examples</code> directory.

```cpp
#include <al5d_cpp/AL5D.hpp>

int main()
{
    al5d_cpp::AL5D al5d;

    auto joint = al5d_cpp::JOINT_BASE;
    auto angle = Angle::from_degree(90);

    al5d.move_to_angle({joint, angle});
}
```

## Installation
1. First make sure you have a local copy of this repository on your workstation.
1. Then <code>cd</code> into the root of this repository.
1. Now run <code>sudo scripts/install.sh</code> to build and install the repository.

## Usage

1. Place <code>find_package(al5d_cpp REQUIRED)</code> into the CMakeLists.txt file of your own project.
1. Now you can include headers like <code>#include <al5d_cpp/AL5D.hpp></code>.
1. Take a look at the example code in the <code>examples</code> to get started quickly.

## Future improvements
* Add support for the AL5D model without wrist rotation.
* Throw more detailed exception messages in <code>exceptions.hpp</code>
* Make some configurations optional
* Build a specific config based on the given keys in the json file.
* Add more static code checkers like Clang-tidy to <code>scripts/assess.sh</code> file.
* A command line tool to manipulate the al5d would be nice for testing new poses.
