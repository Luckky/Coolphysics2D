#ifndef VECTOR_H
#define VECTOR_H

#include <math.h>
#include <string>
#include <sstream>

using namespace std;

class Vector
{
public:
    //Debugging
    string description()const;
    
	//Constructors
	Vector();
	Vector(double x,double y);
	Vector(const Vector& v);
	const Vector& operator =(const Vector& v);
	Vector(const Vector& v1,const Vector& v2);
    
    //Data memeber accessors
    double x()const;
    double y()const;

    //Properties
	Vector unitVector()const;
	double modulus()const;
	double radian()const;

	//Arithmetics
	Vector operator+(const Vector& v)const;
    Vector operator-(const Vector& v)const;
	Vector operator*(double number)const;
	Vector operator/(double number)const;
	void operator+=(const Vector& v);
	double dotProductWith(const Vector& v)const;
	double crossProductWith(const Vector& v)const;
    double radianWith(const Vector& v)const;

    //Transformation
    void symmetrizeAbout(const Vector& axis);
    void rotateBy(double radian);
    
    //Relation
    double componentAlongAxis(const Vector& dir)const;
    

private:
	double _x;
	double _y;
};

#endif