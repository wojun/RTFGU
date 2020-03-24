#include "ViewPlane.h"

ViewPlane::ViewPlane():hres(800),vres(600),s(1.0),num_samples(1),gamma(1.0),inv_gamma(1.0),show_out_of_gamut(false),
                       sampler_ptr(nullptr){}
ViewPlane::ViewPlane(const ViewPlane &viewplane):hres(viewplane.hres),vres(viewplane.vres),s(viewplane.s),
                                                 num_samples(viewplane.num_samples),gamma(viewplane.gamma),
                                                 inv_gamma(viewplane.inv_gamma),
                                                 show_out_of_gamut(viewplane.show_out_of_gamut),sampler_ptr(viewplane.sampler_ptr){}
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
	sampler_ptr         = viewplane.sampler_ptr;

	return (*this);
}

ViewPlane::~ViewPlane() {}

void ViewPlane::set_sampler(Sampler *sp) {
    if(sampler_ptr) {
        delete sampler_ptr;
        sampler_ptr = nullptr;
    }

    num_samples = sp->get_num_samples();
    sampler_ptr = sp;
}

void ViewPlane::set_samples(const int n) {
    num_samples = n;

    if(sampler_ptr) {
        delete sampler_ptr;
        sampler_ptr = nullptr;
    }

    if(num_samples > 1)
        sampler_ptr = new Regular(num_samples); // default sampler_ptr
    else
        sampler_ptr = new Regular(1);// 单一采样时默认均匀采样,只产生锯齿而不是粗糙的效果
}
