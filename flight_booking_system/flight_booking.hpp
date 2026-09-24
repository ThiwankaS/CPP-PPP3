#pragma once

class FlightBooking {
    public:
        FlightBooking(int _id, int _capacity, int _reserved);
        void printStatus();
        void addReservations(int amount);
        void cancelReservations(int amount);
    private:
        int id;
        int capacity;
        int reserved;
};

