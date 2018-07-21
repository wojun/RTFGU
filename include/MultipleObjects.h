#ifndef MULTIPLEOBJECTS_H
#define MULTIPLEOBJECTS_H

#include "Tracer.h"


class MultipleObjects : public Tracer
{
    public:
        MultipleObjects(void);

		MultipleObjects(World* _world_ptr);

		virtual
		~MultipleObjects(void);

		virtual RGBcolor
		trace_ray(const Ray& ray) const;

};

#endif // MULTIPLEOBJECTS_H
