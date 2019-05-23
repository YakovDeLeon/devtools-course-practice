// Copyright 2019 Kurakin Mikhail
#define _USE_MATH_DEFINES
#include <cmath>
#include "include/shapes_area.h"

double ShapesArea::SphereArea(double radius) {
    return 4.0 * M_PI * pow(radius, 2.0);
}

double ShapesArea::CylinderArea(double radius, double height) {
    return 2.0 * M_PI * radius * (height + radius);
}

double ShapesArea::CubeArea(double a) {
    return 6.0 * pow(a, 2.0);
}

double ShapesArea::ParallelepipedArea(double a, double b, double c) {
    return 2.0 * (a * b + b * c + a * c);
}

double ShapesArea::ConeArea(double radius, double generator) {
    return M_PI * radius * (radius + generator);
}

double ShapesArea::TetrahedronArea(double a) {
    return sqrt(3.0) * pow(a, 2.0);
}

