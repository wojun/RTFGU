#include <math.h>
#include "Sphere.h"
#include "Constants.h"
Sphere::Sphere():center(),radius(1.0),GeometricObject(color) {}
Sphere::Sphere(const Point3D &c,float r,const RGBcolor &rgbcolor):GeometricObject(rgbcolor),center(c),radius(r) {}
Sphere::Sphere(const Sphere &sphere):center(sphere.center),radius(sphere.radius),GeometricObject(sphere.color) {}

Sphere::~Sphere() {}

bool Sphere::hit(const Ray &ray,double &tmin, ShaderRec &sr) const {
    double      t;

    // calculate the expression (o + td - c) * (o + td - c) - r^2 = 0
    Vector3D    temp = ray.o - center; // the ray origin
    double      a    = ray.d * ray.d;
    double      b    = 2.0 * temp * ray.d;
    double      c    = temp * temp - radius * radius;
    double      disc = b * b - 4.0 * a * c;

    if(disc < 0.0 ) return false ; // discriminant < 0, no intersection

    else {
        double e     = sqrt(disc);
        double denom = 2.0 * a;

        t = (-b - e) / denom; // smaller root,the bigger root also means farther hit point that would be hidden

        if( t > kEpsilon) { // hit in positive direction,kEpsilon is a very small number but bigger than zero such
                            // as 1e-6
            tmin = t; // determine the ray length
            sr.normal = (temp + t * ray.d) / radius; // its length == 1,start point is center of the sphere
            sr.local_hit_point = ray.o + t * ray.d; // the coordinate of hit point in world space

            return true;
        }

        t = (-b+e) / denom; // larger root

        if(t > kEpsilon) {
            tmin = t;
            sr.normal = (temp + t * ray.d) / radius;
            sr.local_hit_point = ray.o + t * ray.d;
            return true;
        }
    }
    return false;
}
