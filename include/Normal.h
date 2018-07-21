#ifndef NORMAL_H
#define NORMAL_H

//#include "Vector3D.h"
#include "Point3D.h"

class Normal
{
    public:
        // constructor
        Normal();
        Normal (float a);
        Normal (float a,float b,float c);
        Normal (const Normal& n);
        Normal (const Vector3D &v);
        // assignment constructor
        Normal& operator= (const Normal &n);
        Normal& operator= (const Point3D &p);
        Normal& operator= (const Vector3D &v);
        ~Normal();

        // method
        Normal operator- ();
        Normal operator+ (const Normal &n);
        Normal& operator+= (const Normal &n);
        float operator* (const Vector3D &v);
        Normal operator* (const float a);
        void normalize();

        // out function
        friend std::ostream& operator<< (std::ostream &out, const Normal &v);

    public:
        float x,y,z;
};

// definition of Normal method
inline Normal Normal::operator- () {
    return Normal(-x,-y,-z);
}

inline Normal Normal::operator+ (const Normal &n) {
    return Normal(x + n.x, y + n.y, z + n.z);
}

inline Normal& Normal::operator+= (const Normal &n) {
    x += n.x; y += n.y; z += n.z;
    return *this;
}

inline float Normal::operator*(const Vector3D &v) {
    return x * v.x + y * v.y + z * v.z;
}

inline Normal Normal::operator*(float a) {
    return Normal(x * a, y * a, z * z);
}

// non member function for Normal
inline Normal operator* (float a, const Normal &n) {
    return Normal(a * n.x, a * n.y, a * n.z);
}

inline Vector3D operator+ (const Vector3D &v, const Normal &n) {
	return (Vector3D(v.x + n.x, v.y + n.y, v.z + n.z));
}

inline Vector3D operator- (const Vector3D& v, const Normal& n) {
	return (Vector3D(v.x - n.x, v.y - n.y, v.z - n.z));
}

inline float operator* (const Vector3D& v, const Normal& n) {
	return (v.x * n.x + v.y * n.y + v.z * n.z);
}

#endif // NORMAL_H
