#include "Point2D.hpp"
#include "Line2D.hpp"
#include <cstdlib>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

Point2D get_values(std::string& str) {
    std::stringstream ss(str);
    std::string token;
    std::vector<std::string> tokens;
    
    while (ss >> token) {
        tokens.push_back(token);
    }

    return Point2D(std::stod(tokens[0]), std::stod(tokens[1]));
}


int main(void) {

    std::string str;

    std::getline(std::cin, str);
    Point2D p1 = get_values(str);

    std::getline(std::cin, str);
    Point2D p2 = get_values(str);

    std::getline(std::cin, str);
    Point2D p3 = get_values(str);
    
    std::cout << p1.distanceTo(p2) << "\n";
    Line2D l(p1, p2);
    std::cout << l.toString() << "\n";

    if(l.contains(p3)) {
        std::cout << "colliner\n";
    } else {
        std::cout << "not colliner\n";
    }
    return EXIT_SUCCESS;
}
