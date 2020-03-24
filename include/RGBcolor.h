#ifndef RGBCOLOR_H
#define RGBCOLOR_H

#include <iostream>

class RGBcolor
{
    public:
        // constructor
        RGBcolor();
        RGBcolor(float a);
        RGBcolor(const RGBcolor &rgbcolor);
        RGBcolor& operator= (const RGBcolor &rgbcolor);
        RGBcolor(float _a,float _b,float _c);
        ~RGBcolor();

        // method
        RGBcolor& operator+= (const RGBcolor &rgbcolor);
        RGBcolor  operator+ (const RGBcolor &rgbcolor);
        RGBcolor  operator- (const RGBcolor &rgbcolor);
        RGBcolor  operator* (float a);
        RGBcolor  operator/ (float a) const;
        RGBcolor  operator/=(float a) ;
        bool operator== (const RGBcolor &rgbcolor);

        friend std::ostream& operator<<(std::ostream &out,const RGBcolor &rgbcolor);
    public:
        float r,g,b;
};

inline RGBcolor& RGBcolor::operator+= (const RGBcolor &rgbcolor) {
    r += rgbcolor.r; g += rgbcolor.g; b += rgbcolor.b;
    return *this;
}

inline RGBcolor RGBcolor::operator+ (const RGBcolor &rgbcolor) {
    return RGBcolor(r + rgbcolor.r, g + rgbcolor.g, b + rgbcolor.b);
}

inline RGBcolor RGBcolor::operator- (const RGBcolor &rgbcolor) {
    return RGBcolor(r - rgbcolor.r, g - rgbcolor.g, b - rgbcolor.b);
}

inline RGBcolor RGBcolor::operator* (float a) {
    return RGBcolor(r * a, g * a, b *a);
}

inline RGBcolor RGBcolor::operator/ (float a) const {
    return RGBcolor(r / a, g / a, b / a);
}

inline RGBcolor RGBcolor::operator/= (float a) {
    return RGBcolor(r /= a, g /= a, b /= a);
}

inline bool RGBcolor::operator== (const RGBcolor &rgbcolor) {
    return (r==rgbcolor.r && g==rgbcolor.g && b==rgbcolor.b)? true : false;
}

inline RGBcolor operator* (const float a,const RGBcolor &rgbcolor) {
    return RGBcolor(a * rgbcolor.r, a * rgbcolor.g, a * rgbcolor.b);
}
#endif // RGBCOLOR_H
