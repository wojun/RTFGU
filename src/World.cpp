#include <fstream>
#include <iostream>
#include "World.h"
#include "Constants.h"
#include "Vector3D.h"
#include "Point3D.h"
#include "Normal.h"
#include "Ray.h"
#include "MultipleObjects.h"
#include "Plane.h"
World::World() : vp(),background_color(black),tracer_ptr(nullptr) {}

World::~World()
{
    if(tracer_ptr) {
        delete tracer_ptr;
        tracer_ptr = nullptr;
    }
}

void World::render_scene() const {
    RGBcolor    pixel_color;
    Ray         ray;
    double      zw = 100;
    double      x,y;

    ray.d = Vector3D(0,0,-1);

    std::ofstream outfile ("myrender.txt",std::ios_base::out);
    outfile <<"P3\n"<<vp.vres<<" "<<vp.hres<<"\n255\n";

    for(int c = vp.vres; c !=0 ; --c) {
        fprintf(stderr,"\rRendering  %5.2f%%",100.*(vp.vres-c)/(vp.vres-1));
        for(int r = 0; r < vp.hres; ++r) {
            // emit a ray from each pixel's center
            x = vp.s * (r - 0.5 * (vp.hres - 1.0));
            y = vp.s * (c - 0.5 * (vp.vres - 1.0));
            ray.o = Point3D(x , y , zw);

            // for each pixel,calculate the color by calling the tracer_ray
            pixel_color = tracer_ptr->trace_ray(ray);
            //display_pixel(pixel_color);
            int ir = int(255.99*pixel_color.r);
            int ig = int(255.99*pixel_color.g);
            int ib = int(255.99*pixel_color.b);
            outfile<<ir<<" "<<ig<<" "<<ib<<"\n";
        }
    }
}

void World::build() {
    vp.set_hres(400);
    vp.set_vres(400);
    vp.set_pixel_size(0.5);
    vp.set_gamma(1.0);

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

	Sphere*	sphere_ptr1 = new Sphere(Point3D(5, 3, 0), 30);
	sphere_ptr1->set_color(yellow);	   								// yellow
	add_object(sphere_ptr1);

	Sphere*	sphere_ptr2 = new Sphere(Point3D(45, -7, -60), 20);
	sphere_ptr2->set_color(brown);									// brown
	add_object(sphere_ptr2);

	Sphere*	sphere_ptr3 = new Sphere(Point3D(40, 43, -100), 17);
	sphere_ptr3->set_color(dark_green);								// dark green
	add_object(sphere_ptr3);

	Sphere*	sphere_ptr4 = new Sphere(Point3D(-20, 28, -15), 20);
	sphere_ptr4->set_color(orange);									// orange
	add_object(sphere_ptr4);

	Sphere*	sphere_ptr5 = new Sphere(Point3D(-25, -7, -35), 27);
	sphere_ptr5->set_color(green);									// green
	add_object(sphere_ptr5);

	Sphere*	sphere_ptr6 = new Sphere(Point3D(20, -27, -35), 25);
	sphere_ptr6->set_color(light_green);							// light green
	add_object(sphere_ptr6);

	Sphere*	sphere_ptr7 = new Sphere(Point3D(35, 18, -35), 22);
	sphere_ptr7->set_color(green);   								// green
	add_object(sphere_ptr7);

	Sphere*	sphere_ptr8 = new Sphere(Point3D(-57, -17, -50), 15);
	sphere_ptr8->set_color(brown);									// brown
	add_object(sphere_ptr8);

	Sphere*	sphere_ptr9 = new Sphere(Point3D(-47, 16, -80), 23);
	sphere_ptr9->set_color(light_green);							// light green
	add_object(sphere_ptr9);

	Sphere*	sphere_ptr10 = new Sphere(Point3D(-15, -32, -60), 22);
	sphere_ptr10->set_color(dark_green);     						// dark green
	add_object(sphere_ptr10);

	Sphere*	sphere_ptr11 = new Sphere(Point3D(-35, -37, -80), 22);
	sphere_ptr11->set_color(dark_yellow);							// dark yellow
	add_object(sphere_ptr11);

	Sphere*	sphere_ptr12 = new Sphere(Point3D(10, 43, -80), 22);
	sphere_ptr12->set_color(dark_yellow);							// dark yellow
	add_object(sphere_ptr12);

	Sphere*	sphere_ptr13 = new Sphere(Point3D(30, -7, -80), 10);
	sphere_ptr13->set_color(dark_yellow);
	add_object(sphere_ptr13);										// dark yellow (hidden)

	Sphere*	sphere_ptr14 = new Sphere(Point3D(-40, 48, -110), 18);
	sphere_ptr14->set_color(dark_green); 							// dark green
	add_object(sphere_ptr14);

	Sphere*	sphere_ptr15 = new Sphere(Point3D(-10, 53, -120), 18);
	sphere_ptr15->set_color(brown); 								// brown
	add_object(sphere_ptr15);

	Sphere*	sphere_ptr16 = new Sphere(Point3D(-55, -52, -100), 10);
	sphere_ptr16->set_color(light_purple);							// light purple
	add_object(sphere_ptr16);

	Sphere*	sphere_ptr17 = new Sphere(Point3D(5, -52, -100), 15);
	sphere_ptr17->set_color(brown);									// browm
	add_object(sphere_ptr17);

	Sphere*	sphere_ptr18 = new Sphere(Point3D(-20, -57, -120), 15);
	sphere_ptr18->set_color(dark_purple);							// dark purple
	add_object(sphere_ptr18);

	Sphere*	sphere_ptr19 = new Sphere(Point3D(55, -27, -100), 17);
	sphere_ptr19->set_color(dark_green);							// dark green
	add_object(sphere_ptr19);

	Sphere*	sphere_ptr20 = new Sphere(Point3D(50, -47, -120), 15);
	sphere_ptr20->set_color(brown);									// browm
	add_object(sphere_ptr20);

	Sphere*	sphere_ptr21 = new Sphere(Point3D(70, -42, -150), 10);
	sphere_ptr21->set_color(light_purple);							// light purple
	add_object(sphere_ptr21);

	Sphere*	sphere_ptr22 = new Sphere(Point3D(5, 73, -130), 12);
	sphere_ptr22->set_color(light_purple);							// light purple
	add_object(sphere_ptr22);

	Sphere*	sphere_ptr23 = new Sphere(Point3D(66, 21, -130), 13);
	sphere_ptr23->set_color(dark_purple);							// dark purple
	add_object(sphere_ptr23);

	Sphere*	sphere_ptr24 = new Sphere(Point3D(72, -12, -140), 12);
	sphere_ptr24->set_color(light_purple);							// light purple
	add_object(sphere_ptr24);

	Sphere*	sphere_ptr25 = new Sphere(Point3D(64, 5, -160), 11);
	sphere_ptr25->set_color(green);					 				// green
	add_object(sphere_ptr25);

	Sphere*	sphere_ptr26 = new Sphere(Point3D(55, 38, -160), 12);
	sphere_ptr26->set_color(light_purple);							// light purple
	add_object(sphere_ptr26);

	Sphere*	sphere_ptr27 = new Sphere(Point3D(-73, -2, -160), 12);
	sphere_ptr27->set_color(light_purple);							// light purple
	add_object(sphere_ptr27);

	Sphere*	sphere_ptr28 = new Sphere(Point3D(30, -62, -140), 15);
	sphere_ptr28->set_color(dark_purple); 							// dark purple
	add_object(sphere_ptr28);

	Sphere*	sphere_ptr29 = new Sphere(Point3D(25, 63, -140), 15);
	sphere_ptr29->set_color(dark_purple);							// dark purple
	add_object(sphere_ptr29);

	Sphere*	sphere_ptr30 = new Sphere(Point3D(-60, 46, -140), 15);
	sphere_ptr30->set_color(dark_purple); 							// dark purple
	add_object(sphere_ptr30);

	Sphere*	sphere_ptr31 = new Sphere(Point3D(-30, 68, -130), 12);
	sphere_ptr31->set_color(light_purple); 							// light purple
	add_object(sphere_ptr31);

	Sphere*	sphere_ptr32 = new Sphere(Point3D(58, 56, -180), 11);
	sphere_ptr32->set_color(green);									//  green
	add_object(sphere_ptr32);

	Sphere*	sphere_ptr33 = new Sphere(Point3D(-63, -39, -180), 11);
	sphere_ptr33->set_color(green);									// green
	add_object(sphere_ptr33);

	Sphere*	sphere_ptr34 = new Sphere(Point3D(46, 68, -200), 10);
	sphere_ptr34->set_color(light_purple);							// light purple
	add_object(sphere_ptr34);

	Sphere*	sphere_ptr35 = new Sphere(Point3D(-3, -72, -130), 12);
	sphere_ptr35->set_color(light_purple);							// light purple
	add_object(sphere_ptr35);

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


