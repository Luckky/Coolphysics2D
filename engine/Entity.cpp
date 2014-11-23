#include "Entity.h"

Entity::Entity(double radius,double mass,Vector position,Vector velocity,Vector acceleration,double elasticity):_radius(radius),_mass(mass),_position(position),_velocity(velocity),_acceleration(acceleration),_elasticity(elasticity){}

void Entity::update(double timeInterval,const Vector& gravity,double damping)
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

double Entity::distanceTo(const Entity &e)const
{
    const Vector& p0=this->position();
    const Vector& p1=e.position();
    Vector v=p1-p0;
    return v.modulus();
}

bool Entity::collideWith(const Entity& e)const
{
    double distance=this->distanceTo(e);
    if (distance<this->_radius+e._radius) {
        Vector collisionAxis=e.position()-this->position();
        double v1=this->velocity().componentAlongAxis(collisionAxis);
        double v2=e.velocity().componentAlongAxis(collisionAxis);
        if ((v1-v2)>0) {
            return true;
        }
    }
    return false;
}

void Entity::handleCollision(Entity& e1,Entity& e2)
{
    double m1=e1._mass;
    double m2=e2._mass;
    Vector collisionAxis=(e2.position()-e1.position()).unitVector();
    double v1=e1.velocity().componentAlongAxis(collisionAxis);
    double v2=e2.velocity().componentAlongAxis(collisionAxis);
    double V1=e1._elasticity*((m1-m2)*v1+2*m2*v2)/(m1+m2);
    double V2=e2._elasticity*((m2-m1)*v2+2*m1*v1)/(m2+m1);
    e1._velocity+=collisionAxis*(V1-v1);
    e2._velocity+=collisionAxis*(V2-v2);
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

double Entity::radius()const
{
    return _radius;
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
