// Copyright 2019 Shkerin Igor

#ifndef MODULES_TRIANGLES_INCLUDE_TRIANGLES_H_
#define MODULES_TRIANGLES_INCLUDE_TRIANGLES_H_

#include <vector>

// The structure of the point contains the x and y coordinates.
struct Point {
    double x, y;  // Accordingly, the x and y coordinates of the point.

    // Constructor class point.
    explicit Point(double _x = 0, double _y = 0) : x(_x), y(_y) {}

    // Assignment operator.
    Point& operator=(const Point& point) = default;

    // Comparison operator.
    bool operator==(const Point& point) const {
        if ((this->x == point.x) &&
            (this->y == point.y)) {
            return true;
        } else {
            return false;
        }
    }
};

// The class of a triangle, which is given by its coordinates on the plane.
class Triangle {
 public:
    // Various triangle constructors
    Triangle();
    Triangle(double x1, double y1, double x2, double y2, double x3, double y3);
    Triangle(Point _a, Point _b, Point _c);
    explicit Triangle(std::vector<double> array);

    // Check whether the basic triangle inequality holds.
    bool IsTriangleExist();

    // Get the point of the triangle.
    Point get_point_a() const;
    Point get_point_b() const;
    Point get_point_c() const;

    // Set the point of the triangle.
    void set_point_a(Point _a);
    void set_point_b(Point _b);
    void set_point_c(Point _c);

    // Find the length of the side of the triangle by two points.
    double SideLength(Point _a, Point _b);

    // The perimeter of the triangle.
    double Perimeter();

    // Area of a triangle.
    double Square();

    // Get the angle of a triangle at a point in degrees.
    double get_angle_a();
    double get_angle_b();
    double get_angle_c();

    // Convert radians to degrees.
    double ConvertToDegrees(double radian);

    // Convert degrees to radians.
    double ConvertToRadian(double degrees);

 private:
    Point a, b, c;  // triangle points
    double ab = 0, bc = 0, ac = 0;  // sides of a triangle
};

#endif  // MODULES_TRIANGLES_INCLUDE_TRIANGLES_H_
