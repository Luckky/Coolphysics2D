#include "Vector.h"
#include <math.h>

Vector::Vector():_x(0),_y(0){}

Vector::Vector(float px,float py):_x(px),_y(py){}

Vector::Vector(const Vector& v):_x(v._x),_y(v._y){}

const Vector& Vector::operator =(const Vector& v)
{
	_x=v._x;
	_y=v._y;
	return *this;
}

Vector::Vector(const Vector& v1,const Vector& v2)
{
	Vector();
	_x=v2._x-v1._x;
	_y=v2._y-v1._y;
}

float Vector::x()const
{
    return _x;
}
float Vector::y()const
{
    return _y;
}

float Vector::modulus()const
{
	return sqrt(_x*_x+_y*_y);
}

Vector Vector::unitVector()const
{
	float mod=modulus();
	return Vector(_x/mod,_y/mod);
}

float Vector::radian()const
{
	float mod=modulus();
    if(_y>=0)
    {
        return acos(_x/mod);
    }
    else
    {
        return -acos(_x/mod);
    }
}

float Vector::dotProductWith(const Vector& v)const
{
	return _x*v._x+_y*v._y;
}

float Vector::crossProductWith(const Vector& v)const
{
	return _x*v._y-_y*v._x;
}



float Vector::radianWith(const Vector &v)const
{
    double result=acos(dotProductWith(v)/modulus()*v.modulus());
    if (this->crossProductWith(v)<0)
    {
    	result=-result;
    }
    return result;
}

Vector Vector::operator+(const Vector& v)const
{
	return Vector(_x+v._x,_y+v._y);
}
Vector Vector::operator*(float number)const
{
	return Vector(_x*number,_y*number);
}
Vector Vector::operator/(float number)const
{
	return Vector(_x/number,_y/number);
}
void Vector::operator+=(const Vector& v)
{
	_x+=v._x;
	_y+=v._y;
}

void Vector::symmetrizeAbout(const Vector& axis)
{
	double radian=this->radianWith(axis);
	rotateBy(radian*2);
}

void Vector::rotateBy(float rad)
{
	float r=radian();
	r+=rad;
	_x=modulus()*cos(r);
	_y=modulus()*sin(r);
}

string Vector::description()const
{
	stringstream ss;
	ss<<"("<<_x<<" "<<_y<<")";
	return ss.str();
}