// Copyright 2019 Kurakin Mikhail
#ifndef MODULES_SHAPES_AREA_INCLUDE_SHAPES_AREA_H_
#define MODULES_SHAPES_AREA_INCLUDE_SHAPES_AREA_H_

class ShapesArea {
 public:
    static double SphereArea(double radius);
    static double CylinderArea(double radius, double height);
    static double CubeArea(double a);
    static double ParallelepipedArea(double a, double b, double c);
    static double ConeArea(double radius, double generator);
    static double TetrahedronArea(double a);
};

#endif  // MODULES_SHAPES_AREA_INCLUDE_SHAPES_AREA_H_




