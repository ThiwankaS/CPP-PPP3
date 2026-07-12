#pragma once

#include <cstdint>
#include <string>

class Fraction {
    public:
        Fraction(int64_t num, int64_t den);
        std::string toString();
        double toDouble();

        Fraction operator+(const Fraction& left) const;
        Fraction operator-(const Fraction& left) const;
        Fraction operator*(const Fraction& left) const;
        Fraction operator/(const Fraction& left) const;
        bool operator<(const Fraction& left) const;
        bool operator<=(const Fraction& left) const;
        bool operator>(const Fraction& left) const;
        bool operator>=(const Fraction& left) const;
        bool operator==(const Fraction& left) const;
        bool operator!=(const Fraction& left) const;

    private:
        int64_t numerator;
        int64_t denominator;
        bool sign;

        void reduce();
};
