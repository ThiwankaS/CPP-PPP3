#include "geom_vector.hpp"
#include <ios>
#include <iostream>
#include <istream>
#include <ostream>

GeomVector GeomVector::operator+(const GeomVector& gv) {
    return GeomVector(x_ + gv.x_, y_ + gv.y_, z_ + gv.z_);
}

GeomVector GeomVector::operator-(const GeomVector& gv) {
    return GeomVector(x_ - gv.x_, y_ - gv.y_, z_ - gv.z_);
}

GeomVector GeomVector::operator*(const GeomVector& gv) {
    return GeomVector(x_ * gv.x_, y_ * gv.y_, z_ * gv.z_);
} 

GeomVector GeomVector::operator/(const GeomVector& gv) {
    return GeomVector(x_ / gv.x_, y_ / gv.y_, z_ / gv.z_);
}

GeomVector operator*(double a, const GeomVector& gv) {
    return GeomVector(gv.x_ * a, gv.y_ * a, gv.z_ * a);
}

GeomVector operator/(double a, const GeomVector& gv) {
    return GeomVector(gv.x_ / a, gv.y_ / a, gv.z_ / a);
}

std::ostream& operator<<(std::ostream& out, const GeomVector& gv) {
    out << "(" << gv.x_ << ", " << gv.y_ << ", " << gv.z_ << ")";
    return out;
}

std::istream& operator>>(std::istream& in, GeomVector& gv) {
    double x, y, z;

    if(in >> x >> y >> z) {
       gv.x_ = x;
       gv.y_ = y;
       gv.z_ = z;
    } else {
        in.setstate(std::ios::failbit);
    }
    return in;
}
