#include <iostream>
#include <vector>
#include "Vector3D.h"
#include "Point3D.h"
#include "Normal.h"
#include "Ray.h"
#include "RGBcolor.h"
#include "ViewPlane.h"
#include "Sphere.h"
#include "World.h"
// Define the member function as const member function ensure that the const class object also can call the function
// Using the const reference as class parameter for passing to function as possible as you can
// For overloading  operator,its use variable type of function signature according to the overloading type :
// as friend,as normal function or as member function.
// When define a class, often should define the default constructor, copy constructor(passing by const reference with another
// class object),assignment operator in the same time.
// To make definition of member function,the format is return_type class_name::function_name (parameter list) {// function body}
// Friend function can't use the const and isn't member function,can't use ::
// Overloading operator << can't use const parameter ostream for output will change the state of out stream,and only use reference
// Self-defined operator << and >> must be defined as non-member function,or it's left side object will be a instance of our class
// Keyword friend only appear inside the class
// When define a function in inheritance class to override the virtual or pure virtual function in its base class,use
// the keyword override after the parameter list in declaration of function
// Notice that use default parameter in default constructor declaration
// When initialing a derived class by constructor, the member variables in base class should use format Base_Constructor(parameter_list)
// to initial.
// If a method is inline,it must be defined in class body (no need to use inline keyword) or head file (need to use inline keyword)
// whenever define a assignment constructor, check if it is self-assignment first
// if use new operator in constructor,use delete in destructor carefully
// If two classes was included each other,one or two of these should declare as pointer for fear that infinite loop a.b.a.b...
// and for correct compile,in head file of class A,it can use #include "B.h",but in head file of class B,it must use the declare
// class A instead of #include "A.h",in the same time,the file B.cpp use #include "A.h" to call the member function of A
// Defining function with const keyword as possible as you can,or when using the const parameter in parameter list,it will
// raise a const correctness error
using namespace std;

int main()
{
    World w;
    w.build();
    w.render_perspective();
    return 0;
}
