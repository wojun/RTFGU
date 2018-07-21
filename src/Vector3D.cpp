#include "Vector3D.h"
// definition of constructor
Vector3D::Vector3D():x(0.0),y(0.0),z(0.0){}
Vector3D::Vector3D(float a):x(a),y(a),z(a){}
Vector3D::Vector3D(float a,float b,float c):x(a),y(b),z(c){}
Vector3D::Vector3D(const Vector3D &vec):x(vec.x),y(vec.y),z(vec.z){}

 // assignment constructor definition
Vector3D& Vector3D::operator= (const Vector3D &v){
    if(this == &v) return *this;
    x = v.x, y = v.y, z = v.z;
    return *this;
}
// definition of method
void Vector3D::normalize() {
    float len = (*this).length();
    x/=len, y/=len, z/=len;
}

 // as friend function ,it can't be defined as member function for the number of argument issue
std::ostream& operator<<(std::ostream &out, const Vector3D &v){
    out<<"vec(" << v.x << ", " << v.y << ", " << v.z << ")";
    return out;
}

Vector3D::~Vector3D() {}
