#include <iostream>
#include "opencamlib/ballcutter.hpp"
#include "opencamlib/point.hpp"

int main() {
    ocl::BallCutter cutter(2.0, 5.0); // diameter, length

    ocl::Point point(0.0, 0.0, 0.0);
    std::cout << "Cutter radius: " << cutter.getRadius() << std::endl;
    std::cout << "Test Point: " << point.x << ", " << point.y << ", " << point.z << std::endl;

    return 0;
}
