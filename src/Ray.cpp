#include "Ray.h"

// constructor
Ray::Ray():o(0.0),d(0.0,0.0,1.0){}
Ray::Ray(const Point3D &origin,const Vector3D &direction):o(origin),d(direction){}
Ray::Ray(const Ray &ray):o(ray.o),d(ray.d){}
 // assignment constructor definition
Ray& Ray::operator=(const Ray &ray) {
    if(this == &ray)
        return *this;
    o = ray.o;
    d = ray.d;
    return *this;
}
Ray::~Ray() {}

