#ifndef COOLPHYSICS2D_PARTICLE_H
#define COOLPHYSICS2D_PARTICLE_H

#include "config.h"
#include "Vector.h"
#include "Circle.h"

#include <string>
#include <sstream>

BEGIN_NAMESPACE_COOLPHYSICS2D

class Particle
{
    //Friend class
    friend class DampingField;
    friend class GravityField;
    friend class BuoyancyField;
    friend class CentripetalGravityField;
    
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
    void setPosition(const Vector& position);
    void setVelocity(const Vector& velocity);
    
    Circle range()const;
    
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

END_NAMESPACE_COOLPHYSICS2D

#endif
