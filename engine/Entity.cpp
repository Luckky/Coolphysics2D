#include "Entity.h"

Entity::Entity(float mass,Vector position,Vector velocity,Vector acceleration):_mass(mass),
_position(position),_velocity(velocity),_acceleration(acceleration){}

void Entity::update(float timeInterval,const Vector& gravity,float damping)
{
	_position+=_velocity*timeInterval;
	Vector velocity=_velocity;
	_velocity+=_acceleration*timeInterval;
	_acceleration=gravity+(velocity*damping/_mass);
}

void Entity::reflectAbout(const Vector& axis)
{
	_velocity.symmetrizeAbout(axis);
}

std::string Entity::description()const
{
	std::stringstream ss;
	ss<<"position: "<<_position.description()<<"\n";
	ss<<"velocity: "<<_velocity.description()<<"\n";
	ss<<"acceleration: "<<_acceleration.description()<<"\n";
	ss<<"\n";
	return ss.str();
}

const Vector& Entity::position()const
{
	return _position;
}
const Vector& Entity::velocity()const
{
	return _velocity;
}
const Vector& Entity::acceleration()const
{
	return _acceleration;
}