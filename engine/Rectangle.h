#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "Vector.h"
#include "Circle.h"

class Rectangle
{
public:
    //Constructor
    Rectangle(double x,double y,double width,double height);
    //Accessor
    double x()const;
    double y()const;
    double width()const;
    double height()const;
    
    //Judgement
    bool contain(const Vector& point)const;
    bool overlap(const Circle& circle)const;
    
private:
    double _x;
    double _y;
    double _width;
    double _height;
};

#endif