#ifndef PLANE_H
#define PLANE_H

#include "GeometricObject.h"


class Plane : public  GeometricObject
{
    public:
        Plane(void);   												// default constructor
		Plane(const Point3D& point, const Normal& normal);			// constructor
		Plane(const Plane& plane); 									// copy constructor
		virtual Plane* clone(void) const;							// virtual copy constructor
		Plane& operator= (const Plane& rhs);						// assignment operator
		virtual	~Plane(void);										// destructor
        void set_color(const RGBcolor &rgbcolor);
        void set_color(float r,float g,float b);
        RGBcolor get_color();

		virtual bool hit(const Ray& ray, double& tmin, ShaderRec& sr) const override;

    private:
        Point3D 	a;   				// point through which plane passes
		Normal 		n;					// normal to the plane
		static const double kEpsilon;   // for shadows and secondary rays

};

inline void Plane::set_color(const RGBcolor &rgbcolor) { color = rgbcolor;}

inline void Plane::set_color(float r,float g,float b) { color = RGBcolor(r,g,b);}

inline RGBcolor Plane::get_color() {return color;}
#endif // PLANE_H
