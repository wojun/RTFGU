#ifndef SHADERREC_H
#define SHADERREC_H

//#include "Point3D.h"
#include "Normal.h"
// #include "World.h" // prevent loop include
#include "RGBcolor.h"
class World;

class ShaderRec // record information of ray-tracer
{
    public:
        ShaderRec(World &wr);
        ShaderRec(const ShaderRec &sr);
        virtual ~ShaderRec();

        ShaderRec& operator= (const ShaderRec &shaderrec);

    public:
        bool        hit_an_object;      // did the ray hit an object
        Point3D     local_hit_point;    // world coordinates pf hit point
        Point3D 	hit_point;			// world coordinates of intersection
        Normal      normal;             // normal at hit point
        RGBcolor    color;              //
        World       &w;                 // world reference for shading
        double      t;                  // ray parameter

};

#endif // SHADERREC_H
