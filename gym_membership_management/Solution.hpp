#pragma once

#include <chrono>
#include <string>

class Member {
    public:
        Member(int id, std::string first, std::string last);
        void extended_validity(int months);
        void cancel_subscription(void);
        void print_status(void);

    private:
        int member_id;
        std::string first_name;
        std::string last_name;
        std::chrono::year_month_day created_date;
        std::chrono::year_month_day valid_untill;

        int get_validity(void);
};
