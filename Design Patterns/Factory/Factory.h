#pragma once

#include "../../common.h"

namespace Factory
{
    enum class PointType
    {
        cartesian,
        polar
    };

//    struct PointFactory;

    class Point {
    private:
//        friend class PointFacory;

        Point(float x, float y) : x(x), y(y) {}

        float x, y;

        struct PointFactory
        {
            static Point NewCartesian(float x, float y)
            {
                return {x, y};
            }

            static Point NewPolar(float r, float theta) {
                return {r * cos(theta), r * sin(theta)};
            }
        };

    public:

        friend ostream&operator << (ostream &os, const Point & point) {
            os << "x: = " << point.x << ", y: =  " << point.y << endl;
            return os;
        }

        static PointFactory Factory;
    };
}

