#include "Rectangle.h"

Rectangle::Rectangle(double x,double y,double width,double height):_x(x),_y(y),_width(width),_height(height){}

double Rectangle::x()const
{
    return _x;
}
double Rectangle::width()const
{
    return _width;
}
double Rectangle::y()const
{
    return _y;
}
double Rectangle::height()const
{
    return _height;
}

bool Rectangle::contain(const Vector& point)const
{
    double x=point.x();
    double y=point.y();
    if (x>_x&&x<_width&&y>_y&&y<_height) {
        return true;
    }
    return false;
}

bool Rectangle::overlap(const Circle &circle)const
{
    double x=circle.center().x();
    double y=circle.center().y();
    double r=circle.radius();
    if (x+r<_x||x-r>_width||y+r<_y||y-r>_height) {
        return false;
    }
    return true;
}