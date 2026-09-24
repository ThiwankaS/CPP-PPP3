#include <iostream>
#include <string>
#include <string_view>
#include <ranges>
#include <regex>
#include <algorithm>
#include <exception>

static const std::regex ipv4(R"(^(?:(?:25[0-5]|2[0-4][0-9]|1[0-9][0-9]|[1-9][0-9]|[0-9])\.){3}(?:25[0-5]|2[0-4][0-9]|1[0-9][0-9]|[1-9][0-9]|[0-9])$)");

bool is_valid_ip(const std::string& ip){
    std::cout << "using regex\n";
    return (std::regex_match(ip, ipv4));
}

bool is_valid_ip(std::string_view ip){
    const char delimeter = '.';

    auto valid_octate = [](int value){
        return (value >=0 && value <= 255);
    };

    auto splitted = ip | std::views::split(delimeter);

    int count = 0;

    for(auto part : splitted){
        ++count;
        std::string s(part.begin(), part.end());
        if(s.empty()) {
            return (false);
        }
        if(!std::all_of(s.begin(), s.end(), ::isdigit)){
            return (false);
        }
        try {
            int value = std::stoi(s);
            if(!valid_octate(value)) {
                return (false);
            }
        } catch (const std::exception& e) {
            return (false);
        }
    }
    return (count == 4);
}

int main(int argc, char *argv[]) {
    if(argc != 2){
        std::cerr << "Mal-using program\n";
        return (EXIT_FAILURE);
    }
    std::string str (argv[1]);
    if(is_valid_ip(str)){
        std::cout << "valid !\n";
    } else {
        std::cout << "invalid !\n";
    }

    return (EXIT_SUCCESS);
}
