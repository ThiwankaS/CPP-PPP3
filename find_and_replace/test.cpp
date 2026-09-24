#include <cctype>
#include <cstddef>
#include <cstdlib>
#include <iostream>
#include <string>


int main(void) {

    std::string look, needle, haystack;
    
    std::getline(std::cin, look);
    std::getline(std::cin, needle);
    std::getline(std::cin, haystack);

    if(look.empty() || needle.empty() || haystack.empty()) {
        return  EXIT_FAILURE;
    }

    size_t start = 0, end;

    do {
        
        start = haystack.find(look, start);
        if(start == std::string::npos) {
            break;
        }

        end = start + look.size();
        if(end == std::string::npos) {
            end = haystack.size();
        }

        bool left   = ( start == 0 || haystack[start - 1] == ' ' || std::ispunct(static_cast<unsigned char>(haystack[start - 1])));
        bool right  = ( end == haystack.size() || haystack[end] == ' ' || std::ispunct(static_cast<unsigned char>(haystack[end])));

        if(left && right) {
            haystack.replace(start, look.size(), needle.c_str());
            start = start + needle.size();
        } else {
            start = start + look.size();
        }


    } while(start < haystack.size());

    std::cout << haystack << "\n";

    return EXIT_SUCCESS;
}
