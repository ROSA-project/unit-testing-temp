#include <cmath>
#include <algorithm>
#include "sphereIntersection.h"

using namespace std;

double PI = 3.14159 ;
double square(const double x) {
    return x * x;
}

double sphericalCapV(const double radius,const double height) {
    return (PI / 3.0) * (square(height) * (3.0 * radius - height));
}

// struct type Point is passed by reference, built-in types passed by value (optimization)
double sphereIntersection(const Point& c1, const Point& c2, const double r1, const double r2 , const double thresholdFraction) {
    double d = sqrt(square(c2.x - c1.x) + square(c2.y - c1.y) + square(c2.z - c1.z));
  
    // volume of the given spheres
    double vS1 = (4.0 / 3.0) * PI * pow(r1, 3);
    double vS2 = (4.0 / 3.0) * PI * pow(r2, 3);

    // Check for no intersection
    if (r1 + r2 <= d) {
        return 0.0;
    }

    // Check if one sphere is completely inside the other
    if (d <= fabs(r1 - r2)) {
        double v_min = min(vS1, vS2);
        return v_min;
    }

    // Heights of spherical caps
    double h1 = fabs(r1 - fabs((square(r1) + square(d) - square(r2)) / (2.0 * d)));
    double h2 = fabs(r2 - fabs((square(r2) + square(d) - square(r1)) / (2.0 * d)));

    // Volumes of spherical caps
    double vCap1 = sphericalCapV(r1, h1);
    double vCap2 = sphericalCapV(r2, h2);

    // threshold is a small fraction of the smaller volume
    
    double threshold = thresholdFraction * min(vS1, vS2);

    // Check if the intersection volume is below the threshold
    if ((vCap1 + vCap2) < threshold) return 0.0;

    return (vCap1 + vCap2);
}