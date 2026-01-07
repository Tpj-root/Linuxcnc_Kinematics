#include <iostream>
#include <rl/math/Vector.h>

int main()
{
    rl::math::Vector v(3);
    v << 1.0, 2.0, 3.0;

    std::cout << "Vector: " << v.transpose() << std::endl;
    return 0;
}
