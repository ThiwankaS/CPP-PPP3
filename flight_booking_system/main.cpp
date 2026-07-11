#include "flight_booking.hpp"
#include <cstdlib>
#include <iostream>
#include <sstream>
#include <string>
#include <unordered_map>

int main(void) {
    
    int value, id, token_count = 0;
    std::string str, command = " ", id_str, value_str, extra_token;
    std::unordered_map<int, FlightBooking> flights;

    while(command != "quit") {

        command.clear();

        std::getline(std::cin, str);
        std::stringstream ss(str);

        if(ss >> command) {
           token_count++;
           
           if(command == "quit") {
                break;
           }

           if(ss >> id_str) {
                
               id = std::stoi(id_str);
               token_count++;
                    
               if(ss >> value_str) {
                    value = std::stoi(value_str);
                    token_count++;

                    if(ss >> extra_token) {
                        str.clear();
                        command.clear();
                        std::cout << "Can not perform this opertion : too much tokens ["<< token_count << "]\n";
                        continue;
                    }
                }
           }
        }

        if(command == "create") {
            auto [it, success] = flights.emplace(id, FlightBooking(id, value, 0));
            if(success) {
                it->second.printStatus();
            } else {
                std::cout << "Can not perform this operation : flight id already exits [" << id << "]\n";
            }
        }

        if(command == "add") {
            auto it = flights.find(id);
            if(it != flights.end()) {
                it->second.addReservations(value);
                it->second.printStatus();
            } else {                            
                std::cout << "Can not perform this operation : flight not exits [" << id << "]\n";
            }
        }

        if(command == "cancel") {
            auto it = flights.find(id);
            if(it != flights.end()) {
                it->second.cancelReservations(value);
                it->second.printStatus();
            } else {                            
                std::cout << "Can not perform this operation : flight not exits [" << id << "]\n";
            }
        }

        if(command == "delete") {
            size_t it = flights.erase(id);
            if(it > 0) {
                std::cout << "Flight [" << id << "] sucessfully removed!\n";
            } else {                            
                std::cout << "Can not perform this operation : flight not exits [" << id << "]\n";
            }
        }


    }

    return  EXIT_SUCCESS;
}
