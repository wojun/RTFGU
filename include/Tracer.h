#ifndef TRACER_H
#define TRACER_H

// #include "World.h"  // its wrong for compile
#include "Constants.h"
#include "RGBcolor.h"
#include "Ray.h"
class World;

class Tracer
{
    public:
        Tracer();
        Tracer(World *w_ptr); // w_ptr is used to access the objects and background color of World scene
        virtual RGBcolor trace_ray(const Ray &ray) const;
        ~Tracer();

    protected:
        World *world_ptr;
};

#endif // TRACER_H
