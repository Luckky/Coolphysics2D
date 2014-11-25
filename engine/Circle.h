#ifndef CIRCLE_H
#define CIRCLE_H

#include "Vector.h"

class Circle
{
public:
    //Constructor
    Circle(const Vector& center,double radius);
    
    //Accessor
    const Vector& center()const;
    double radius()const;
private:
    Vector _center;
    double _radius;
};

#endif