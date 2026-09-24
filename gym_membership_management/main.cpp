#include "Solution.hpp"
#include <cstddef>
#include <cstdlib>
#include <iostream>
#include <sstream>
#include <string>
#include <unordered_map>
#include <vector>

int main(void) {

    std::unordered_map<int, Member> members;
    
    std::vector<std::string> tokens;
    std::string str, token, command;


    while(command != "quit") {

        std::getline(std::cin, str);
        std::stringstream ss(str);

        while(ss >> token) {
            if(token.empty()) {
                continue;
            }
            tokens.push_back(token);
        }

        if(tokens.empty()) {
            command = "";
            std::cout << "Can not perform this operation.\n";            
            continue;

        }

        if(tokens.size() > 4) {
            tokens.clear();
            command = "";
            std::cout << "Can not perform this operation.\n";
            continue;
        }

        command = tokens[0];

        if(command == "quit") {
            break;
        }

        if(command == "create" && tokens.size() == 4) {
            int id = std::stoi(tokens[1]);
            auto [it, success ] = members.emplace(id, Member(id, tokens[2], tokens[3]));

            if(success) {
                it->second.print_status();
            } else {
                std::cout << "Member id : " << id << " already exists!\n";
            }
        }

        if(command == "extend" && tokens.size() == 3) {
            int id = std::stoi(tokens[1]);
            auto it = members.find(id);
            if(it != members.end()) {
                it->second.extended_validity(std::stoi(tokens[2]));
                it->second.print_status();
            } else {
                std::cout << "Member id : " << id << " not exists!\n";
            }
        }

        if(command == "cancel" && tokens.size() == 2) {
            int id = std::stoi(tokens[1]);
            auto it = members.find(id);
            if(it != members.end()) {
                it->second.cancel_subscription();
                it->second.print_status();
            } else {
                std::cout << "Member id : " << id << " not exists!\n";
            }
        }

        if(command == "delete" && tokens.size() == 2) {
            int id = std::stoi(tokens[1]);
            size_t it = members.erase(id);
            if(it > 0) {
                std::cout << "Member id : " << id << " successfully removed!\n";
            } else {
                std::cout << "Member id : " << id << " not exists!\n";
            }
        }
        tokens.clear();
    }

    return EXIT_SUCCESS;
}
