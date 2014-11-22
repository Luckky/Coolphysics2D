#ifndef VECTOR_H
#define VECTOR_H

#include <math.h>
#include <string>
#include <sstream>

using namespace std;

class Vector
{
public:
	//Constructors
	Vector();
	Vector(float x,float y);
	Vector(const Vector& v);
	const Vector& operator =(const Vector& v);
	Vector(const Vector& v1,const Vector& v2);
    
    //Data memeber accessors
    float x()const;
    float y()const;

    //Properties
	Vector unitVector()const;
	float modulus()const;
	float radian()const;

	//Arithmetics
	Vector operator+(const Vector& v)const;
	Vector operator*(float number)const;
	Vector operator/(float number)const;
	void operator+=(const Vector& v);
	float dotProductWith(const Vector& v)const;
	float crossProductWith(const Vector& v)const;
    float radianWith(const Vector& v)const;

    //Transformation
    void symmetrizeAbout(const Vector& axis);
    void rotateBy(float radian);
    
	string description()const;

private:
	float _x;
	float _y;
};

#endif