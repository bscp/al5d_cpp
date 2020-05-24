#include <al5d_cpp/AL5D.hpp>

int main()
{
    al5d_cpp::ConsoleAL5D al5d;

    auto joint = al5d_cpp::JOINT_BASE;
    auto angle = al5d_cpp::Angle::from_degree(90);

    al5d.move_to_angles({{joint, angle}});
}
