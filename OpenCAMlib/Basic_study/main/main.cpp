#include <iostream>
#include "point.hpp"

int main() {
    ocl::Point p1(3.0, 4.0, 0.0);
    ocl::Point p2(0.0, 0.0, 5.0);

    std::cout << "p1.norm() = " << p1.norm() << std::endl;

    ocl::Point cross = p1.cross(p2);
    std::cout << "p1 x p2 = (" << cross.x << ", " << cross.y << ", " << cross.z << ")" << std::endl;

    return 0;
}
