#include "Solution.hpp"
#include <cstdint>
#include <cstdlib>
#include <numeric>
#include <string>

Fraction::Fraction(int64_t num, int64_t den) {
    sign = (num < 0) ^ (den < 0);
    this->numerator = std::abs(num);
    this->denominator = std::abs(den);
    reduce();
}


std::string Fraction::toString(void) {
    std::string result;

    if(this->numerator == 0) {
        return "0";
    }

    int64_t whole = this->numerator / this->denominator;
    int64_t value = this->numerator - (whole * this->denominator);

    if(sign) {
        result.push_back('-');
    }

    if(whole != 0) {
        result.append(std::to_string(whole));
    }
    
    if(value != 0) {
        if(whole != 0) {
            result.push_back(' ');
        }
        result.append(std::to_string(value));    
        result.push_back('/');
        result.append(std::to_string(this->denominator));
    }

    return result;
}

double Fraction::toDouble(void) {
    double result = static_cast<double>(this->numerator) / static_cast<double>(this->denominator);
    if(sign) {
        return result * -1;
    }
    return result;
}

void Fraction::reduce() {
   if(numerator != 0 && denominator != 0) {
        int64_t common = std::gcd(numerator, denominator);
        this->numerator = this->numerator / common;
        this->denominator = this->denominator / common;
   } else {
        this->numerator = 0;
        this->denominator = 0;
   } 
}

Fraction Fraction::operator+(const Fraction& left) const {
    int64_t value1 = (this->sign) ? (-this->numerator) : this->numerator;
    int64_t value2 = (left.sign) ? (-left.numerator) : left.numerator;

    int64_t new_numerator = (value1 * left.denominator) + (value2 * this->denominator);
    int64_t new_denominator = left.denominator * this->denominator;

    return Fraction(new_numerator, new_denominator);
}

Fraction Fraction::operator-(const Fraction& left) const {
    int64_t value1 = (this->sign) ? (-this->numerator) : this->numerator;
    int value2 = (left.sign) ? (-left.numerator) : left.numerator;

    int64_t new_numerator = (value1 * left.denominator) - (value2 * this->denominator);
    int64_t new_denominator = left.denominator * this->denominator;

    return Fraction(new_numerator, new_denominator);
}

Fraction Fraction::operator*(const Fraction& left) const {
    int64_t value1 = (this->sign) ? (-this->numerator) : this->numerator;
    int64_t value2 = (left.sign) ? (-left.numerator) : left.numerator;

    int64_t new_numerator = value1 * value2;
    int64_t new_denominator = left.denominator * this->denominator;

    return Fraction(new_numerator, new_denominator);
}

Fraction Fraction::operator/(const Fraction& left) const {
    int64_t value1 = (this->sign) ? (-this->numerator) : this->numerator;
    int64_t value2 = (left.sign) ? (-left.numerator) : left.numerator;

    int64_t new_numerator = value1 * left.denominator;
    int64_t new_denominator = value2 * this->denominator;

    return Fraction(new_numerator, new_denominator);
}

bool Fraction::operator<(const Fraction& left) const {
    int64_t value1 = (this->sign) ? (-this->numerator) : this->numerator;
    int64_t value2 = (left.sign) ? (-left.numerator) : left.numerator;

    int64_t rhs = value1 * left.denominator;
    int64_t lhs = value2 * this->denominator;

    return rhs < lhs;
}

bool Fraction::operator<=(const Fraction& left) const {
    int64_t value1 = (this->sign) ? (-this->numerator) : this->numerator;
    int64_t value2 = (left.sign) ? (-left.numerator) : left.numerator;

    int64_t rhs = value1 * left.denominator;
    int64_t lhs = value2 * this->denominator;

    return rhs <= lhs;
}

bool Fraction::operator>(const Fraction& left) const {
    int64_t value1 = (this->sign) ? (-this->numerator) : this->numerator;
    int64_t value2 = (left.sign) ? (-left.numerator) : left.numerator;

    int64_t rhs = value1 * left.denominator;
    int64_t lhs = value2 * this->denominator;

    return rhs > lhs;
}

bool Fraction::operator>=(const Fraction& left) const {
    int64_t value1 = (this->sign) ? (-this->numerator) : this->numerator;
    int64_t value2 = (left.sign) ? (-left.numerator) : left.numerator;

    int64_t rhs = value1 * left.denominator;
    int64_t lhs = value2 * this->denominator;

    return rhs >= lhs;
}

bool Fraction::operator==(const Fraction& left) const {
    int64_t value1 = (this->sign) ? (-this->numerator) : this->numerator;
    int64_t value2 = (left.sign) ? (-left.numerator) : left.numerator;

    int64_t rhs = value1 * left.denominator;
    int64_t lhs = value2 * this->denominator;

    return rhs == lhs;
}

bool Fraction::operator!=(const Fraction& left) const {
    int64_t value1 = (this->sign) ? (-this->numerator) : this->numerator;
    int64_t value2 = (left.sign) ? (-left.numerator) : left.numerator;

    int64_t rhs = value1 * left.denominator;
    int64_t lhs = value2 * this->denominator;

    return rhs != lhs;
}
