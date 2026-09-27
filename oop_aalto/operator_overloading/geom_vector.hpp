#ifndef _GEOM_VECTOR_HPP_
#define _GEOM_VECTOR_HPP_

#include <ostream>

class GeomVector {
    public:
        GeomVector() : x_(0.0f), y_(0.0f), z_(0.0f) {}
        GeomVector(double x) : x_(x), y_(x), z_(x) {}
        GeomVector(double x, double y, double z) : x_(x), y_(y), z_(z) {}
        
        // member function
        GeomVector operator+(const GeomVector& gv);
        GeomVector operator-(const GeomVector& gv);
        GeomVector operator*(const GeomVector& gv);
        GeomVector operator/(const GeomVector& gv);

        // external but has access through friend
        friend GeomVector operator*(double a, const GeomVector& gv);
        friend GeomVector operator/(double a, const GeomVector& gv);
        friend std::ostream& operator<<(std::ostream& out, const GeomVector& gv);
        friend std::istream& operator>>(std::istream& in, GeomVector& gv);
    private:
        double x_,y_,z_;
};

#endif //! _GEOM_VECTOR_HPP_
