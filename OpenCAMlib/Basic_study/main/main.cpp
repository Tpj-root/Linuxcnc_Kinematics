#include <iostream>
#include "point.hpp"

int main() {
    ocl::Point p1(3.0, 4.0, 0.0);
    ocl::Point p2(0.0, 0.0, 5.0);
    

    double dotProduct = p1.dot(p2);
    std::cout << "Dot product: " << dotProduct << std::endl;

    ocl::Point crossProduct = p1.cross(p2);
    std::cout << "Cross product: (" 
              << crossProduct.x << ", " 
              << crossProduct.y << ", " 
              << crossProduct.z << ")" << std::endl;

    std::cout << "Norm of p1: " << p1.norm() << std::endl;
    std::cout << "Norm of p2: " << p2.norm() << std::endl;
    return 0;
}
