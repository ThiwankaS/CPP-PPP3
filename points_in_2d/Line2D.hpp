#pragma once

#include "Point2D.hpp"
#include <string>

class Line2D {
    public:
        Line2D(double _m, double _c);
        Line2D(const Point2D& pa,const Point2D& pb);
        std::string toString();
        bool contains(const Point2D& p);

    private:
        double m;
        double c;
};
