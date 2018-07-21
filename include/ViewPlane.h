#ifndef VIEWPLANE_H
#define VIEWPLANE_H


class ViewPlane
{
    public:
        // constructor
        ViewPlane();
        ViewPlane(const ViewPlane &viewplane);
        ViewPlane& operator= (const ViewPlane &viewplane);
        ~ViewPlane();

        // method
        void set_hres(const int h_res);
        void set_vres(const int v_res);
        void set_gamma(const float g);
        void set_samples(const int n);
        void set_pixel_size(const float sizes);
        void set_gamut_display(const bool show);

    public:
        int   hres;               // horizontal image resolution
        int   vres;               // vertical image resolution
        int   num_samples;        // number of samples per pixel
        float s;                  // pixel size
        float gamma;              // monitor gamma factor,default is 1.0
        float inv_gamma;          // 1 / gamma
        bool  show_out_of_gamut;  // display red if RGBcolor out of gamut
};

inline void ViewPlane::set_hres(const int h_res) { hres = h_res; }
inline void ViewPlane::set_vres(const int v_res) { vres = v_res; }
inline void ViewPlane::set_pixel_size(const float sizes) { s = sizes; }
inline void ViewPlane::set_samples(const int num) { num_samples = num; }
inline void ViewPlane::set_gamma(const float _gamma) { gamma = _gamma; inv_gamma = 1.0 / _gamma; }
inline void ViewPlane::set_gamut_display(const bool show) { show_out_of_gamut = show; }
#endif // VIEWPLANE_H
