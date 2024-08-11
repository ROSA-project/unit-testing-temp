#include <iostream>
#include "sphereIntersection.h"

using namespace std;

int main() {
    Point c1 {0, 0, 0};
    Point c2 {4, 0, 0};
    double r1 = 2.0;
    double r2 = 2.1;
    double thresholdFraction = 0.015;
    // 0 == no intersection
    // other value == intersection
    double V = sphereIntersection(c1, c2, r1, r2 , thresholdFraction);
    cout << "Intersection Volume: " << V << "\n";

    return 0;
}