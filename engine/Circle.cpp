#include "Circle.h"

Circle::Circle(const Vector& center,double radius):_center(center),_radius(radius){}

const Vector& Circle::center()const
{
    return _center;
}
double Circle::radius()const
{
    return _radius;
}