#include "RGBcolor.h"

// constructor definition of class RGBcolor
RGBcolor::RGBcolor():r(0.0),g(0.0),b(0.0){}
RGBcolor::RGBcolor(float a):r(a),g(a),b(a){}
RGBcolor::RGBcolor(const RGBcolor &rgbcolor):r(rgbcolor.r),g(rgbcolor.g),b(rgbcolor.b){}
RGBcolor::RGBcolor(float _a,float _b,float _c):r(_a),g(_b),b(_c){}

RGBcolor& RGBcolor::operator= (const RGBcolor &rgbcolor){
    if(this == &rgbcolor)
        return *this;
    r = rgbcolor.r; g = rgbcolor.g; b = rgbcolor.b;
    return *this;
}

RGBcolor::~RGBcolor() {}

std::ostream& operator<<(std::ostream &out,const RGBcolor &rgbcolor) {
    out<<"rgb(" << rgbcolor.r << ", " << rgbcolor.g << ", " << rgbcolor.b << ")";
    return out;
}
