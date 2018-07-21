#include "Tracer.h"
#include "World.h"

Tracer::Tracer():world_ptr(nullptr) {}
Tracer::Tracer(World *w_ptr) : world_ptr(w_ptr) {}

Tracer::~Tracer() {}

RGBcolor Tracer::trace_ray(const Ray &ray) const {
    return (black);
};

