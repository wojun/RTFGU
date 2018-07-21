#ifndef VECTOR3D_H
#define VECTOR3D_H

#include <math.h>
#include <iostream>

class Vector3D
{
    public:
        // constructor
        Vector3D ();
        Vector3D (float a);
        Vector3D (float _a,float _b,float _c);
        Vector3D (const Vector3D &vec);          // copy constructor

        Vector3D& operator= (const Vector3D &v); // assignment constructor,must be defined as member function

        ~Vector3D();
        // method
        // for overloading  operator,its use variable type of function signature according to the overloading type :
        // as friend,as normal function or as member function.
        Vector3D operator+ (const Vector3D &v) ;
        Vector3D operator- (const Vector3D &v) ;
        Vector3D operator- () ;
        Vector3D operator* (float a) ;
        Vector3D operator/ (float a) ;
        float    operator* (const Vector3D &v) ;    // vector dot product
        // Vector3D operator^ (const Vector3D &v); // vector cross product

        void normalize() ;
        float length() ;
        float len_square() ;

         // out function
        friend std::ostream& operator<< (std::ostream &out, const Vector3D &v);

    public:
        float x,y,z;
};

inline Vector3D Vector3D::operator+ (const Vector3D &v){
    return Vector3D(x + v.x, y + v.y, z + v.z);
}

inline Vector3D Vector3D::operator- (const Vector3D &v){
    return Vector3D(x - v.x, y - v.y, z - v.z);
}

inline Vector3D Vector3D::operator-(){
    return Vector3D(-x,-y,-z);
}

// 常数右乘
inline Vector3D Vector3D::operator* (float a){
    return Vector3D(a*x,a*y,a*z);
}

inline Vector3D Vector3D::operator/ (float a){
    return Vector3D(x/a,y/a,z/a);
}

inline float Vector3D::operator* (const Vector3D &v){
    return x * v.x + y * v.y + z * v.z;
}

inline float Vector3D::len_square(){
    return x * x + y * y + z * z;
}

inline float Vector3D::length(){
    return sqrt((*this).len_square());
}

// non member function
 // 常数左乘
inline Vector3D operator* (float a,const Vector3D &v){
    return Vector3D(a * v.x, a * v.y, a * v.z);
}
#endif // VECTOR3D_H
