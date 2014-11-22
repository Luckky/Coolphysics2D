#ifndef ENTITY_H
#define ENTITY_H

#include "Vector.h"
#include <string>
#include <sstream>

class Entity
{
public:
	Entity(float mass,Vector position,Vector velocity,Vector acceleration);

	std::string description()const;

	void update(float timeInterval,const Vector& gravity,float damping);

	void reflectAbout(const Vector& axis);

	//Accessors
	const Vector& position()const;
	const Vector& velocity()const;
	const Vector& acceleration()const;

private:
	float _mass;
	Vector _position;
	Vector _velocity;
	Vector _acceleration;
};

#endif