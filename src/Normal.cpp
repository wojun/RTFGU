#include "Normal.h"

// definition of normal constructor
Normal::Normal():x(0.0),y(0.0),z(0.0){}
Normal::Normal(float a):x(a),y(a),z(a){}
Normal::Normal(float a,float b,float c):x(a),y(b),z(c){}
Normal::Normal(const Normal& n):x(n.x),y(n.y),z(n.z){}
Normal::Normal(const Vector3D &v):x(v.x),y(v.y),z(v.z){}

Normal::~Normal() {}

Normal& Normal::operator= (const Normal &n){
    if (this == &n)
		return (*this);
    x = n.x; y = n.y; z = n.z;
    return *this;
}

Normal& Normal::operator= (const Vector3D& v){
    x = v.x; y = v.y; z = v.z;
    return *this;
}

Normal& Normal::operator= (const Point3D &p){
    x = p.x; y = p.y; z = p.z;
    return *this;
}

void Normal::normalize(){
    double length = sqrt(x * x + y * y + z * z);
	x /= length; y /= length; z /= length;
}

std::ostream& operator<<(std::ostream &out, const Normal &v) {
    out<<"normal(" << v.x << ", " << v.y << ", " << v.z << ")";
    return out;
}
