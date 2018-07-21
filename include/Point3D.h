#ifndef POINT3D_H
#define POINT3D_H

#include "Vector3D.h"

class Point3D
{
    public:
        // construct
        Point3D();
        Point3D (float a);
        Point3D (float _a,float _b,float _c);
        Point3D (const Point3D &p);            // copy construction

        Point3D& operator= (const Point3D &p); // assignment constructor
        ~Point3D();

        // method
        // 对运算符的重载，根据采用作为友元，普通函数，成员函数的方式，采用不同的参数格式，这里作为成员函数重载
        Point3D operator+ (const Vector3D &v) const; // point translate with a vector
        Vector3D operator- (const Point3D &p) const; // construct vector with one point minus another
        Point3D operator- (const Vector3D &v);
        Point3D operator- ();
        Point3D operator* (float a);
        Point3D operator/ (float a);

        float distance ( const Point3D &p);
        float dis_square(const Point3D &p);
        // out function
        friend std::ostream& operator<< (std::ostream &out, const Point3D &v);

    public:
        float x,y,z;
};

inline Point3D Point3D::operator+ (const Vector3D &v) const {
    return Point3D(x + v.x, y + v.y, z + v.z);
}

inline Point3D Point3D::operator- (const Vector3D &v){
    return Point3D(x - v.x, y - v.y, z - v.z);
}

inline Point3D Point3D::operator-() {
    return Point3D(-x , -y , -z);
}

inline Vector3D Point3D::operator-(const Point3D &p) const {
    return Vector3D(x - p.x, y - p.y, z - p.z);
}

// 常数右乘
inline Point3D Point3D::operator* (float a){
    return Point3D(a * x, a * y, a * z);
}

inline Point3D Point3D::operator/ (float a){
    return Point3D(x / a, y / a, z / a);
}

inline float Point3D::distance(const Point3D &p) {
    return sqrt((x - p.x) * (x - p.x) + (y - p.y) * (y - p.y) + (z - p.z) * (z - p.z));
}

inline float Point3D::dis_square(const Point3D &p){
    return (x - p.x) * (x - p.x) + (y - p.y) * (y - p.y) + (z - p.z) * (z - p.z);
}

// non member function
 // 常数左乘
inline Point3D operator* (float a,const Point3D &v){
    return Point3D(a * v.x, a * v.y, a * v.z);
}
#endif // POINT3D_H
