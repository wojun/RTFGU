#ifndef SINGLESPHERE_H
#define SINGLESPHERE_H

#include "Tracer.h"
class SingleSphere : public Tracer
{
    public:
        SingleSphere();
        SingleSphere(World *w_ptr);
        virtual ~SingleSphere();
        RGBcolor trace_ray(const Ray& ray) const override;
    protected:

};

#endif // SINGLESPHERE_H
