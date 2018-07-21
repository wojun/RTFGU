#include "ShaderRec.h"
#include "Constants.h"
#include "World.h" // for use the method of class World
ShaderRec::ShaderRec(World &wr) : hit_an_object(false),local_hit_point(),normal(),color(black),w(wr) {}

ShaderRec::ShaderRec(const ShaderRec &sr) : hit_an_object(sr.hit_an_object),local_hit_point(sr.local_hit_point),
                                            normal(sr.normal),color(sr.color),w(sr.w) {}


ShaderRec& ShaderRec::operator=(const ShaderRec &shaderrec) {
    if(this == &shaderrec)
        return *this;

    hit_an_object = shaderrec.hit_an_object;
    local_hit_point = shaderrec.local_hit_point;
    normal = shaderrec.normal;
    color = shaderrec.color;
    w = shaderrec.w;

    return *this;
}

ShaderRec::~ShaderRec() {}
