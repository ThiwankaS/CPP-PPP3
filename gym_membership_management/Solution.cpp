#include "Solution.hpp"
#include <bits/chrono.h>
#include <chrono>
#include <cmath>
#include <string>
#include <iostream>

Member::Member(int id, std::string first, std::string last) 
    : member_id(id), first_name(first), last_name(last) {
    
        auto now = std::chrono::system_clock::now();
        auto local_time = std::chrono::current_zone()->to_local(now);
        created_date = std::chrono::year_month_day{ std::chrono::floor<std::chrono::days>(local_time) };
        valid_untill = created_date + std::chrono::months(6);

        if(!valid_untill.ok()) {
            valid_untill = valid_untill.year() / valid_untill.month() / std::chrono::last;
        }
}

int Member::get_validity(void) {
    int start_month = int(created_date.year()) * 12 + static_cast<unsigned>(created_date.month());
    int valid_month = int(valid_untill.year()) * 12 + static_cast<unsigned>(valid_untill.month());

    return valid_month - start_month;
}

void Member::extended_validity(int months) {
    auto now = std::chrono::system_clock::now();
    auto local_time = std::chrono::current_zone()->to_local(now);
    auto current_date = std::chrono::year_month_day { std::chrono::floor<std::chrono::days>(local_time) };

    valid_untill = current_date + std::chrono::months(months);

    if(!valid_untill.ok()) {
        valid_untill = valid_untill.year() / valid_untill.month() / std::chrono::last;
    }
}

void Member::cancel_subscription(void) {
    auto now = std::chrono::system_clock::now();
    auto local_time = std::chrono::current_zone()->to_local(now);
    auto current_date = std::chrono::year_month_day { std::chrono::floor<std::chrono::days>(local_time)};
    valid_untill = current_date.year() / current_date.month() / std::chrono::last;
}

void Member::print_status(void) {
    std::cout << "Member : " << member_id
        << " : " << first_name << " " << last_name
        << " subscription valid until " << valid_untill
        << " | " << get_validity() << " months\n";
}
