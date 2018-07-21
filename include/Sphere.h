#ifndef SPHERE_H
#define SPHERE_H

#include "GeometricObject.h"
// #include "Point3D.h"
// #include "ShaderRec.h"
class Sphere : public GeometricObject {

    public:
        Sphere();
        Sphere(const Point3D &c,float r,const RGBcolor &rgbcolor = RGBcolor(1,1,1));
        Sphere(const Sphere &sphere);
        ~Sphere();

       void set_color(const RGBcolor &rgbcolor);
       void set_color(float a,float b,float c);
       void set_center(const Point3D &p);
       void set_center(float a,float b,float c);
       void set_radius(float r);
       float get_radiue();
       Point3D get_center();
       RGBcolor get_color();

       bool hit(const Ray &ray,double &tmin, ShaderRec &sr) const override;

    private:
        Point3D center;
        float radius;
};

inline void Sphere::set_color(const RGBcolor &rgbcolor) {
    color = rgbcolor;
}

inline void Sphere::set_color(float a,float b,float c) {
    color.r = a; color.g = b; color.b = c;
}

inline RGBcolor Sphere::get_color() {
    return color;
}

inline void Sphere::set_center(const Point3D &p) {
    center = p;
}

inline void Sphere::set_center(float a,float b,float c = 0) {
    center.x = a; center.y = b; center.z = c;
}

inline Point3D Sphere::get_center() {
    return center;
}

inline void Sphere::set_radius(float r) {
    radius = r;
}

inline float Sphere::get_radiue() {
    return radius;
}
 #endif // SPHERE_H
