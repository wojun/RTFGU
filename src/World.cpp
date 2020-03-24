#include <fstream>
#include <iostream>
#include "World.h"
#include "Constants.h"
#include "Vector3D.h"
#include "Point3D.h"
#include "Point2D.h"
#include "Normal.h"
#include "Ray.h"
#include "MultipleObjects.h"
#include "Plane.h"
World::World() : vp(),background_color(black),tracer_ptr(nullptr),eye(500),d(300) {}

World::~World()
{
    if(tracer_ptr) {
        delete tracer_ptr;
        tracer_ptr = nullptr;
    }
}

void World::build() {
    vp.set_hres(400);
    vp.set_vres(400);
    vp.set_pixel_size(1.0);
    vp.set_gamma(1.0);

    int num_samples = 8;
    vp.set_samples(num_samples);

    background_color = black;
    tracer_ptr = new MultipleObjects(this);

    /*Sphere *sphere_ptr = new Sphere;
    // use access function to set sphere center and radius
    sphere_ptr->set_center(0,-25,0);
    sphere_ptr->set_radius(80.0);
    sphere_ptr->set_color(1,0,0);
    add_object(sphere_ptr);
    // use constructor to set sphere center and radius
    //Sphere *sphere_ptr = new Sphere;
    sphere_ptr = new Sphere(Point3D(0,30,0),60);
    sphere_ptr->set_color(1,1,0);
    add_object(sphere_ptr);

    Plane *plane_ptr = new Plane(Point3D(0.0),Normal(0,1,1));
    plane_ptr->set_color(0.0,0.25,0.0);
    add_object(plane_ptr);
    //sphere.set_center(0,0);
    //sphere.set_radius(360.0);*/
    // colours

	RGBcolor yellow(1, 1, 0);										// yellow
	RGBcolor brown(0.71, 0.40, 0.16);								// brown
	RGBcolor dark_green(0.0, 0.41, 0.41);							// dark_green
	RGBcolor orange(1.0, 0.75, 0.0);								// orange
	RGBcolor green(0.0, 0.6, 0.3);									// green
	RGBcolor light_green(0.65, 1.0, 0.30);							// light green
	RGBcolor dark_yellow(0.61, 0.61, 0.0);							// dark yellow
	RGBcolor light_purple(0.65, 0.3, 1.0);							// light purple
	RGBcolor dark_purple(0.5, 0.0, 1.0);							// dark purple

	// spheres

	Sphere*	sphere_ptr1 = new Sphere(Point3D(0, 0, 0), 80);
	sphere_ptr1->set_color(orange);
	add_object(sphere_ptr1);

}

void World::render_scene() const {
    RGBcolor    pixel_color;
    Ray         ray;
    double      zw = 100;
    Point2D     pp; // sample point on a pixel
    Point2D     sp; // sample point in [0,1] x [0,1]
    int n = vp.num_samples;
    ray.d = Vector3D(0,0,-1);

    std::ofstream outfile ("myrender.txt",std::ios_base::out);
    outfile <<"P3\n"<<vp.vres<<" "<<vp.hres<<"\n255\n";

    for(int c = vp.vres; c !=0 ; --c) {
        fprintf(stderr,"\rRendering  %5.2f%%",100.*(vp.vres-c)/(vp.vres-1));
        for(int r = 0; r < vp.hres; ++r) {
            // emit a ray from each pixel's center
             //x = vp.s * (r - 0.5 * (vp.hres - 1.0));
             //y = vp.s * (c - 0.5 * (vp.vres - 1.0));
             //ray.o = Point3D(x , y , zw);

            // for each pixel,calculate the color by calling the tracer_ray
             //pixel_color = tracer_ptr->trace_ray(ray);
            //display_pixel(pixel_color);
            pixel_color = black;
            /*
              均匀采样
              for(int p = 0;p < n; ++p) {
                for(int q = 0;q < n;q++) {
                    pp.x = vp.s*(c-0.5*vp.hres+(q+0.5)/n);
                    pp.y = vp.s*(r-0.5*vp.vres+(p+0.5)/n);
                    ray.o = Point3D(pp.x,pp.y,zw);
                    pixel_color += tracer_ptr->trace_ray(ray); // n*n times sum
                }
              }
            */

            /*
             随机采样
             for(int p = 0; p < n; p++){
                 pp.x = vp.s*(c-0.5*vp.hres+(rand()%100)*0.01);
                 pp.y = vp.s*(r-0.5*vp.vres+(rand()%100)*0.01);
                 ray.o = Point3D(pp.x,pp.y,zw);
                 pixel_color += tracer_ptr->trace_ray(ray);

            }*/
            // 抖动采样
            for(int j = 0;j < vp.num_samples; ++j) {
                sp = vp.sampler_ptr->sample_unit_square();
                pp.x = vp.s*(c-0.5*vp.hres + sp.x);
                pp.y = vp.s*(r-0.5*vp.vres + sp.y);
                ray.o = Point3D(pp.x,pp.y,zw);
                pixel_color += tracer_ptr->trace_ray(ray);
            }
            pixel_color = pixel_color/(n*n);
            int ir = int(255.99*pixel_color.r);
            int ig = int(255.99*pixel_color.g);
            int ib = int(255.99*pixel_color.b);
            outfile<<ir<<" "<<ig<<" "<<ib<<"\n";
        }
    }
}

void World::render_perspective() const {
    RGBcolor pixel_color;
    Ray ray;
    ray.o = Point3D(0,0,eye);
    std::ofstream outfile ("myrender.txt",std::ios_base::out);
    outfile <<"P3\n"<<vp.vres<<" "<<vp.hres<<"\n255\n";

    for(int c = vp.vres; c !=0 ; --c) {
        fprintf(stderr,"\rRendering  %5.2f%%",100.*(vp.vres-c)/(vp.vres-1));
        for(int r = 0; r < vp.hres; ++r) {
            ray.d = Vector3D(vp.s*(c-0.5*(vp.hres - 1.0)),vp.s*(r-0.5*(vp.vres-1.0)),-d);
            ray.d.normalize();
            pixel_color = tracer_ptr->trace_ray(ray);

            int ir = int(255.99*pixel_color.r);
            int ig = int(255.99*pixel_color.g);
            int ib = int(255.99*pixel_color.b);
            outfile<<ir<<" "<<ig<<" "<<ib<<"\n";
        }
    }
}



/*void World::display_pixel(const RGBcolor &pixel_color) const {
    std::ofstream outfile ("myrender.txt",std::ios_base::out);
    outfile <<"P3\n"<<200<<" "<<200<<"\n255\n";
    int ir = pixel_color.r;
    int ig = pixel_color.g;
    int ib = pixel_color.b;

    //std::cout<<"("<<i<<", "<<j<<") ";
    //std::cout<<ir<<" "<<ig<<" "<<ib<<"\n";
    outfile<<ir<<" "<<ig<<" "<<ib<<"\n";
}*/

ShaderRec World::hit_bare_bones_objects(const Ray &ray)  {
    ShaderRec sr(*this);
    double t;
    double tmin = kHugeValue;
    int num_objects = objects.size();
    for(int i = 0;i < num_objects; ++i) {
        if(objects[i]->hit(ray,t,sr) && (t < tmin)) {
            sr.hit_an_object = true;
            tmin = t;
            sr.color = objects[i]->get_color();
        }
    }
    return sr; // after progressing the all objects,return
}

ShaderRec World::hit_objects(const Ray& ray) {
	ShaderRec	sr(*this);
	double		t;
	Normal normal;
	Point3D local_hit_point;
	float		tmin 			= kHugeValue;
	int 		num_objects 	= objects.size();

	for (int j = 0; j < num_objects; j++)
		if (objects[j]->hit(ray, t, sr) && (t < tmin)) {
			sr.hit_an_object	= true;
			tmin 				= t;
			// sr.material_ptr     = objects[j]->get_material();
			sr.hit_point 		= ray.o + t * ray.d;
			normal 				= sr.normal;
			local_hit_point	 	= sr.local_hit_point;
		}

	if(sr.hit_an_object) {
		sr.t = tmin;
		sr.normal = normal;
		sr.local_hit_point = local_hit_point;
	}

	return(sr);
}


