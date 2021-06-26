#pragma once

#include "Vector2.h"
#include "Polygon.h"


namespace appcore {
    class Triangle : public Polygon {
    public:
        Vector2 point1;
        Vector2 point2;
        Vector2 point3;

        Triangle() {};

        Triangle(const Vector2 &point1, const Vector2 &point2, const Vector2 &point3)
                : point1(point1), point2(point2), point3(point3) {}
    };
}
