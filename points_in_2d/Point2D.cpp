#include "Point2D.hpp"
#include <cmath>
#include <string>

Point2D::Point2D(double _x, double _y)
    : x(_x), y(_y) {}

std::string Point2D::toString(void) {
    std::string result;

    result.push_back('(');
    result.append(std::to_string(this->x));
    result.push_back(',');
    result.append(std::to_string(this->y));
    result.push_back(')');
    
    return result;
}

double Point2D::distanceTo(const Point2D& that) {
    double value1 = (this->x - that.x) * (this->x - that.x);
    double value2 = (this->y - that.y) * (this->y - that.y);
    return std::sqrtf(value1 + value2);
}
