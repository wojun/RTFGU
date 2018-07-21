#ifndef RAY_H
#define RAY_H

#include "Point3D.h"
#include "Vector3D.h"

class Ray
{
    public:
        // constructor
        Ray();
        Ray(const Point3D &origin,const Vector3D &direction);
        Ray(const Ray &ray); // copy constructor
        Ray& operator= (const Ray &ray); // assignment constructor
        virtual ~Ray();

    public:
        Point3D  o; // origin
        Vector3D d; // direction
};

#endif // RAY_H
