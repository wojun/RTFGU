#include "ViewPlane.h"

ViewPlane::ViewPlane():hres(800),vres(600),s(1.0),num_samples(1),gamma(1.0),inv_gamma(1.0),show_out_of_gamut(false){}
ViewPlane::ViewPlane(const ViewPlane &viewplane):hres(viewplane.hres),vres(viewplane.vres),s(viewplane.s),
                                                 num_samples(viewplane.num_samples),gamma(viewplane.gamma),
                                                 inv_gamma(viewplane.inv_gamma),
                                                 show_out_of_gamut(viewplane.show_out_of_gamut){}
// assignment constructor
ViewPlane& ViewPlane::operator=(const ViewPlane &viewplane){
    if (this == &viewplane)
		return (*this);

	hres 				= viewplane.hres;
	vres 				= viewplane.vres;
	s					= viewplane.s;
	num_samples			= viewplane.num_samples;
	gamma				= viewplane.gamma;
	inv_gamma			= viewplane.inv_gamma;
	show_out_of_gamut	= viewplane.show_out_of_gamut;

	return (*this);
}

ViewPlane::~ViewPlane() {}
