#include <iostream>
#include "flight_booking.hpp"

FlightBooking::FlightBooking(int _id, int _capacity, int _reserved) { 
    this->id = _id;
    (_capacity <= 0) ? this->capacity = 0 : this->capacity = _capacity;
    (_reserved <= 0) ? this->reserved = 0 : 
        (_reserved > (this->capacity * 1.05) ? (this->reserved = this->capacity * 1.05) : this->reserved = _reserved);
}

void FlightBooking::printStatus() {
    std::cout << "Flight " 
        << id << " : " 
        << reserved << "/" << capacity 
        << "(" << (static_cast<double>(reserved)/ static_cast<double>(capacity)) * 100 << "%)" << " seats reserved\n";
}

void FlightBooking::addReservations(int amount) {
    if (amount > 0) {
        if (this->reserved + amount <= capacity * 1.05) {
            this->reserved += amount;
        } else {
            std::cout << "Can not perform this operation\n";
        }
    } else {
        this->reserved += 0; 
    }
}

void FlightBooking::cancelReservations(int amount) {
    if(amount > 0 && amount <= capacity * 1.05) {
        if(amount > reserved) {
            std::cout << "Can not perform this operation\n";            
        } else {
           this->reserved -= amount; 
        }
    } else {
        std::cout << "Can not perform this operation\n";            
    }
}
