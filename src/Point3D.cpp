#include "Point3D.h"

// definition of constructor
Point3D::Point3D():x(0.0),y(0.0),z(0.0){}
Point3D::Point3D(float a):x(a),y(a),z(a){}
Point3D::Point3D(float a,float b,float c):x(a),y(b),z(c){}
Point3D::Point3D(const Point3D &p):x(p.x),y(p.y),z(p.z){}

// assignment constructor
Point3D& Point3D::operator= (const Point3D &v){
    if(this == &v) return *this;
    x = v.x, y = v.y, z = v.z;
    return *this;
}

Point3D::~Point3D() {}

 // as friend function ,it can't be defined as member function for the number of argument issue
std::ostream& operator<<(std::ostream &out, const Point3D &v){
    out<<"p(" << v.x << ", " << v.y << ", " << v.z << ")";
    return out;
}

