// Copyright 2019 Shkerin Igor

#include <cmath>
#include <vector>
#include <string>

#include "include/triangles.h"

Triangle::Triangle() : a(-3.0, 0.0), b(3.0, 0.0), c(0.0, 3.0) {
    ab = SideLength(a, b);
    bc = SideLength(b, c);
    ac = SideLength(a, c);
}

Triangle::Triangle(double x1, double y1, double x2,
                   double y2, double x3, double y3)
                   : a(x1, y1), b(x2, y2), c(x3, y3) {
    ab = SideLength(a, b);
    bc = SideLength(b, c);
    ac = SideLength(a, c);

    if (!IsTriangleExist()) {
        throw std::string("Such a triangle does not exist.");
    }
}

Triangle::Triangle(Point _a, Point _b, Point _c) : a(_a), b(_b), c(_c) {
    ab = SideLength(a, b);
    bc = SideLength(b, c);
    ac = SideLength(a, c);

    if (!IsTriangleExist()) {
        throw std::string("Such a triangle does not exist.");
    }
}

Triangle::Triangle(std::vector<double> array) {
    if (array.size() != 6) {
        throw std::string("Size can't be lower or higher than 6");
    } else {
        a.x = array[0];
        a.y = array[1];
        b.x = array[2];
        b.y = array[3];
        c.x = array[4];
        c.y = array[5];

        ab = SideLength(a, b);
        bc = SideLength(b, c);
        ac = SideLength(a, c);

        if (!IsTriangleExist()) {
            throw std::string("Such a triangle does not exist.");
        }
    }
}

Point Triangle::get_point_a() const {
    return a;
}

Point Triangle::get_point_b() const {
    return b;
}

Point Triangle::get_point_c() const {
    return c;
}

void Triangle::set_point_a(const Point _a) {
    a = _a;
    ab = SideLength(a, b);
    ac = SideLength(a, c);

    if (!IsTriangleExist()) {
        throw std::string("Such a triangle does not exist.");
    }
}

void Triangle::set_point_b(const Point _b) {
    b = _b;
    ab = SideLength(a, b);
    bc = SideLength(b, c);

    if (!IsTriangleExist()) {
        throw std::string("Such a triangle does not exist.");
    }
}

void Triangle::set_point_c(const Point _c) {
    c = _c;
    bc = SideLength(b, c);
    ac = SideLength(a, c);

    if (!IsTriangleExist()) {
        throw std::string("Such a triangle does not exist.");
    }
}

double Triangle::SideLength(Point _a, Point _b) {
    return sqrt(pow((_b.x - _a.x), 2) + pow((_b.y - _a.y), 2));
}

double Triangle::Perimeter() {
    return ab + bc + ac;
}

double Triangle::Square() {
    Triangle abc(a, b, c);
    double h_p = abc.Perimeter() / 2;  // half of perimeter
    return sqrt(h_p * (h_p - ab) * (h_p - ac) * (h_p - bc));
}

double Triangle::get_angle_a() {
    return ConvertToDegrees(acos((pow(ab, 2) + pow(ac, 2) - pow(bc, 2)) /
                           (2 * ab * ac)));
}

double Triangle::get_angle_b() {
    return ConvertToDegrees(acos((pow(ab, 2) + pow(bc, 2) - pow(ac, 2)) /
                           (2 * ab * bc)));
}

double Triangle::get_angle_c() {
    return ConvertToDegrees(acos((pow(bc, 2) + pow(ac, 2) - pow(ab, 2)) /
                           (2 * ac * bc)));
}

double Triangle::ConvertToDegrees(double radian) {
    return radian * 57.2958;
}

double Triangle::ConvertToRadian(double degrees) {
    return degrees / 57.2958;
}

// Check whether the basic triangle inequality holds.
bool Triangle::IsTriangleExist() {
    return (ab + bc > ac) && (ab + ac > bc) && (bc + ac > ab) ? true : false;
}
