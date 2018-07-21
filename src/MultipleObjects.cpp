#include "MultipleObjects.h"
#include "World.h"
MultipleObjects::MultipleObjects():Tracer(){}

MultipleObjects::MultipleObjects(World *_worldptr):Tracer(_worldptr) {}

MultipleObjects::~MultipleObjects() {}

RGBcolor MultipleObjects::trace_ray(const Ray& ray) const {
	ShaderRec sr(world_ptr->hit_bare_bones_objects(ray)); // sr is copy constructed

	if (sr.hit_an_object)
		return (sr.color);
	else
		return (world_ptr->background_color);
}

