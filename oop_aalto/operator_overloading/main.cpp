#include "geom_vector.hpp"
#include <cstdlib>
#include <iostream>

int main(void) {

    GeomVector gv1(1.0, 2.0, 3.0);
    GeomVector gv2(4.0, 5.0, 6.0);

    std::cout << "gv1 : " << gv1 << "\n";
    std::cout << "gv2 : " << gv2 << "\n";
    
    std::cout << "gv1 + gv2 : " << gv1 + gv2 << "\n";
    std::cout << "gv2 + gv1 : " << gv2 - gv1 << "\n";

    std::cout << "gv1 * 2.0 : " << 2.0f * gv1 << "\n";
    std::cout << "gv2 / 2.0 : " << 2.0f / gv2 << "\n";

    std::cout << "gv1 * gv2 : " << gv1 * gv2 << "\n";
    std::cout << "gv2 / gv2 : " << gv2 / gv1 << "\n";

    GeomVector gv3;
    std::cout << "Enter values to create a gemoetric vector : ";
    std::cin >> gv3; 

    std::cout << "gv3 : " << gv3 << "\n";

    return EXIT_SUCCESS;
}
