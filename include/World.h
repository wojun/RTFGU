#ifndef WORLD_H
#define WORLD_H

#include <vector>
#include "ViewPlane.h"
#include "RGBcolor.h"
#include "Tracer.h"
#include "GeometricObject.h"
#include "Sphere.h" //also include the ShaderRec.h,forming loop included
#include "Ray.h"
#include "SingleSphere.h"

using namespace std;
class World
{
    public:
        World();
        virtual ~World();

        void build();
        void render_scene() const;
        void add_object(GeometricObject *object_ptr);
        ShaderRec hit_bare_bones_objects(const Ray &ray);
        // void open_window(const int hres,const int vres);
        // void display_pixel(const RGBcolor &pixel_color) const;
        ShaderRec hit_objects(const Ray& ray);



    public:
        ViewPlane   vp;
        RGBcolor    background_color;
        // Sphere      sphere;
        Tracer      *tracer_ptr;
        vector<GeometricObject*> objects;

};

inline void World::add_object(GeometricObject *object_ptr) { objects.push_back(object_ptr); }
#endif // WORLD_H
