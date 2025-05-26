#include <iostream>
#include "lib.hpp"
#include <iostream>

int main() {
    int a = 5, b = 7;
    std::cout << "add(" << a << ", " << b << ") = " << add(a, b) << "\n";
    std::cout << "multiply(" << a << ", " << b << ") = " << multiply(a, b) << "\n";
    return 0;
}
