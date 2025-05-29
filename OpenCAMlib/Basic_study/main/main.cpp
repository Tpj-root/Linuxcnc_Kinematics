#include <iostream>
#include "point.hpp"

int main() {
    ocl::Point p1(1, 0, 0);
    ocl::Point p2(-2, -2, -2);
    
    double dot = p1.dot(p2);

    std::cout << "Dot product: " << dot << std::endl;

    if (std::abs(dot) < 1e-6)
        std::cout << "→ Approximately Perpendicular (dot ≈ 0)" << std::endl;
    else if (dot > 0)
        std::cout << "→ Vectors point mostly in the SAME direction (dot > 0)" << std::endl;
    else
        std::cout << "→ Vectors point mostly in the OPPOSITE direction (dot < 0)" << std::endl;




    double dotProduct = p1.dot(p2);
    std::cout << "Dot product: " << dotProduct << std::endl;

    ocl::Point crossProduct = p1.cross(p2);
    std::cout << "Cross product: (" 
              << crossProduct.x << ", " 
              << crossProduct.y << ", " 
              << crossProduct.z << ")" << std::endl;

    std::cout << "Norm of p1: " << p1.norm() << std::endl;
    std::cout << "Norm of p2: " << p2.norm() << std::endl;


    std::cout << "Before Normalized p1: " << p1 << std::endl;
    p1.normalize();
    std::cout << "After Normalized p1: " << p1 << std::endl;



    ocl::Point p11(0, 0);         // Line start
    ocl::Point p21(5, 0);         // Line end
    ocl::Point test1(2, -1);     // Below line (should be right)
    ocl::Point test2(2, 1);      // Above line (should be left)

    std::cout << "test1 is right of line: " << std::boolalpha << test1.isRight(p11, p21) << std::endl;
    std::cout << "test2 is right of line: " << std::boolalpha << test2.isRight(p11, p21) << std::endl;


    return 0;
}
