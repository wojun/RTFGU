#ifndef GEOMETRICOBJECT_H
#define GEOMETRICOBJECT_H

#include "RGBcolor.h"
#include "Ray.h"
#include "ShaderRec.h"

class GeometricObject
{
    public:
        GeometricObject();
        GeometricObject(const RGBcolor &rgbcolor);
        ~GeometricObject();
        virtual bool hit(const Ray &ray,double &tmin, ShaderRec &sr) const = 0;
        virtual RGBcolor get_color() = 0;

    protected:
        RGBcolor color;
};

#endif // GEOMETRICOBJECT_H
