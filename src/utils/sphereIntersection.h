#pragma once

#include <cmath>

struct Point {
    double x, y, z;
};

double square(double);

double sphericalCapV(double, double);

double sphereIntersection(const Point&, const Point&, double, double, double);