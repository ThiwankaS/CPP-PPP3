#include "Solution.hpp"
#include <cstdlib>
#include <exception>
#include <iostream>
#include <optional>
#include <sstream>
#include <string>
#include <vector>

std::optional<Fraction> get_fraction(std::string& str) {

    std::vector<std::string> tokens;
    std::string token;
    int numerator, denominator;
    std::stringstream ss(str);

    while(ss >> token) {
        tokens.push_back(token);
    }

    if(tokens.empty() || tokens.size() != 3 || tokens[1] != "/") {
        return std::nullopt;
    }

    try {
        denominator = std::stoi(tokens[2]);
        numerator = std::stoi(tokens[0]);
    } catch ( const std::exception& e) {
        return std::nullopt;
    }

    if(denominator == 0) { 
        return std::nullopt;
    }
    return Fraction (numerator, denominator);
}


int main(void) {

    std::string str1, str2;

    std::getline(std::cin, str1);
    std::getline(std::cin, str2);

    std::optional<Fraction>result1 = get_fraction(str1);
    std::optional<Fraction>result2 = get_fraction(str2);

    if(result1.has_value() && result2.has_value()) {
        Fraction f1 = result1.value();
        Fraction f2 = result2.value();

        std::cout << "\n list of operators and application on franction class : \n\n";

        Fraction f3 = f1 + f2;
        std::cout << f1.toString() << " + " << f2.toString() << "  = " << f3.toString() << "\n";
        
        Fraction f4 = f1 - f2;
        std::cout << f1.toString() << " - " << f2.toString() << "  = " << f4.toString() << "\n";
        
        Fraction f5 = f1 * f2;
        std::cout << f1.toString() << " * " << f2.toString() << "  = " << f5.toString() << "\n";
        
        Fraction f6 = f1 / f2;
        std::cout << f1.toString() << " / " << f2.toString() << "  = " << f6.toString() << "\n";

        std::cout << f1.toString() << " <  " << f2.toString() << " : " << ((f1 <  f2) ? "true" : "false") << "\n";
        std::cout << f1.toString() << " <= " << f2.toString() << " : " << ((f1 <= f2) ? "true" : "false") << "\n";
        std::cout << f1.toString() << " >  " << f2.toString() << " : " << ((f1 >  f2) ? "true" : "false") << "\n";
        std::cout << f1.toString() << " >= " << f2.toString() << " : " << ((f1 >= f2) ? "true" : "false") << "\n";
        std::cout << f1.toString() << " == " << f2.toString() << " : " << ((f1 == f2) ? "true" : "false") << "\n";
        std::cout << f1.toString() << " != " << f2.toString() << " : " << ((f1 != f2) ? "true" : "false") << "\n"; 
    } else {
        std::cout << "Invalid fractional values!\n";
    }

    return EXIT_SUCCESS;
}
