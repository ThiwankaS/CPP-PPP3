#include <cstdlib>
#include <iostream>
#include <string>


int main (void) {

    auto x = 34;
    auto y = 61;
    std::cout << ++y + x + x;

    return EXIT_SUCCESS;
}
