// Copyright 2019 Tolstikov Maksim

#ifndef MODULES_VECTOR_3D_INCLUDE_VECTOR_3D_H_
#define MODULES_VECTOR_3D_INCLUDE_VECTOR_3D_H_

class Vector3d {
 public:
    Vector3d();
    Vector3d(const double x, const double y, const double z);
    Vector3d(const Vector3d& v);

    double getX() const;
    double getY() const;
    double getZ() const;
    void setX(const double x);
    void setY(const double y);
    void setZ(const double z);

    Vector3d& operator = (const Vector3d& v);
    Vector3d operator + (const Vector3d& v) const;
    Vector3d operator - (const Vector3d& v) const;
    Vector3d operator * (const double& d) const;
    Vector3d operator / (const double& d) const;
    double operator * (const Vector3d& v) const;
    bool operator == (const Vector3d& v) const;
    bool operator != (const Vector3d& v) const;

    Vector3d Cross(const Vector3d& v) const;
    double Norma() const;
    Vector3d Normalize() const;

 private:
    double x;
    double y;
    double z;
};

#endif  // MODULES_VECTOR_3D_INCLUDE_VECTOR_3D_H_

