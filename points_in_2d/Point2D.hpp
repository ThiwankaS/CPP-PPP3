#pragma once

#include <string>

class Point2D {
    public:
        Point2D(double _x, double _y);
        std::string toString();
        double distanceTo(const Point2D& that);
        double getX() const {
            return this->x;
        }
        double getY()  const {
            return this->y;
        }

    private:
        double x;
        double y;
};
