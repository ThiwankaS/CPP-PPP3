#include "Line2D.hpp"
#include "Point2D.hpp"
#include <string>

Line2D::Line2D(double _m, double _c)
    : m(_m), c(_c) {}

Line2D::Line2D(const Point2D& pa, const Point2D& pb) {
    this->m = (pb.getY() - pa.getY()) / (pb.getX() - pa.getX());
    this->c = pb.getY() - (this->m * pb.getX());
}

std::string Line2D::toString(void) {
    std::string result;

    result.append("y = ");
    result.append(std::to_string(this->m));
    result.append("x + ");
    result.append(std::to_string(this->c));

    return result;
}

bool Line2D::contains(const Point2D& p) {
    return (p.getY() == (this->m * p.getX() + this->c));
} 
