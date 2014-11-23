#include "Entity.h"

Entity::Entity(double radius,double mass,Vector position,Vector velocity,Vector acceleration,double elasticity):_radius(radius),_mass(mass),_position(position),_velocity(velocity),_acceleration(acceleration),_elasticity(elasticity){}

void Entity::update(double timeInterval,const Vector& gravity,double damping)
{
    Vector acceleration=_acceleration;
    Vector velocity=_velocity;
    
    _position+=velocity*timeInterval;
	_velocity+=acceleration*timeInterval;
	_acceleration=gravity+(velocity*damping/_mass);
}

void Entity::reflectAbout(const Vector& axis)
{
    _velocity.symmetrizeAbout(axis);
    Vector n=axis.rotate(M_PI/2);
    double nComp=_velocity.componentAlongAxis(n);
    _velocity+=n*nComp*(_elasticity*_elasticity-1);
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

void Entity::handleCollision(Entity& entity1,Entity& entity2)
{
    double m1=entity1._mass;
    double m2=entity2._mass;
    Vector collisionAxis=(entity2.position()-entity1.position()).unitVector();
    double v1=entity1.velocity().componentAlongAxis(collisionAxis);
    double v2=entity2.velocity().componentAlongAxis(collisionAxis);
    double V1=entity1._elasticity*((m1-m2)*v1+2*m2*v2)/(m1+m2);
    double V2=entity2._elasticity*((m2-m1)*v2+2*m1*v1)/(m2+m1);
    double e=entity1._elasticity*entity2._elasticity;
    double v=v1-v2>=0?v1-v2:v2-v1;
    double dv=v*(1-e);
    double dv1=dv*m2/(m1+m2);
    double dv2=dv*m1/(m1+m2);
    V1+=dv1;
    V2+=dv2;
    entity1._velocity+=collisionAxis*(V1-v1);
    entity2._velocity+=collisionAxis*(V2-v2);
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
