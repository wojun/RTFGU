#include "SingleSphere.h"
#include "World.h"
#include "ShaderRec.h"
SingleSphere::SingleSphere():Tracer() {}

SingleSphere::SingleSphere(World *w_ptr):Tracer(w_ptr) {}

SingleSphere::~SingleSphere() {}

RGBcolor SingleSphere::trace_ray(const Ray &ray) const {
    ShaderRec sr(*world_ptr); // not used
    double    t;

    if(world_ptr->sphere.hit(ray,t,sr))
        return  red;
    else
        return  black;
}


