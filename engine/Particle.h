#ifndef PARTICLE_H
#define PARTICLE_H

#include "Vector.h"
#include "Circle.h"

#include <string>
#include <sstream>

class Particle
{
    //Friend class
    friend class DampingField;
    friend class GravityField;
    
public:
    
    
	Particle(double radius,double mass,Vector position,Vector velocity,Vector acceleration,double elasticity);

	std::string description()const;

	void update(double timeInterval);

	void reflectAbout(const Vector& axis); //behavior when collides with the edge of the game world
    
    //Relation
    double distanceTo(const Particle& e)const;
    bool collideWith(const Particle&)const;
    
    //Action
    static void handleCollision(Particle& e1,Particle& e2);

	//Accessor
    double radius()const;
	const Vector& position()const;
	const Vector& velocity()const;
	const Vector& acceleration()const;
    
protected:
    

private:
    double _radius;
	double _mass;
    double _elasticity;
    double _friction;
    
	Vector _position;
	Vector _velocity;
	Vector _acceleration;
    
    Vector _lastPosition;
    Vector _lastVelocity;
    Vector _lastAcceleration;
    
};

#endif
