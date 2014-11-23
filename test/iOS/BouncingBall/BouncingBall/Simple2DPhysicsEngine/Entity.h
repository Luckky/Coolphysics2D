#ifndef ENTITY_H
#define ENTITY_H

#include "Vector.h"
#include <string>
#include <sstream>

class Entity
{
public:
	Entity(double radius,double mass,Vector position,Vector velocity,Vector acceleration,double elasticity);

	std::string description()const;

	void update(double timeInterval,const Vector& gravity,double damping);

	void reflectAbout(const Vector& axis); //behavior when collides with the edge of the game world
    
    //Relation
    double distanceTo(const Entity& e)const;
    bool collideWith(const Entity&)const;
    
    //Action
    static void handleCollision(Entity& e1,Entity& e2);

	//Accessor
    double radius()const;
	const Vector& position()const;
	const Vector& velocity()const;
	const Vector& acceleration()const;

private:
    double _radius;
	double _mass;
	Vector _position;
	Vector _velocity;
	Vector _acceleration;
    double _elasticity;
    double _friction;
};

#endif
