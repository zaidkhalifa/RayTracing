#ifndef RTUTIL_H
#define RTUTIL_H

#include <cmath>
#include <random>
#include <iostream>
#include <limits>
#include <memory>


// C++ Std Usings

using std::make_shared;
using std::shared_ptr;
using std::sqrt;
using std::cbrt;
using std::sin;
using std::cos;
using std::acos;

// Constants

const double infinity = std::numeric_limits<double>::infinity();
const double pi = 3.1415926535897932385;
const double twopi = pi*2.0;
const double halfpi = pi/2.0;
const double inv_pi = 1.0/pi;
const double sqrt_inv_pi = sqrt(inv_pi);

// Utility Functions

inline double degrees_to_radians(double degrees) {
    return degrees * pi / 180.0;
}

inline double random_double(double min = 0.0, double max = 1.0) {
    static std::uniform_real_distribution<double> distribution(min, max);
    static std::mt19937 generator;
    return distribution(generator);
}

// Common Headers

#include "color.h"
#include "interval.h"
#include "ray.h"
#include "vec3.h"

#endif