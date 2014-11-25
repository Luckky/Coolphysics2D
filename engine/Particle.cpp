#include "Particle.h"

Particle::Particle(double radius,double mass,Vector position,Vector velocity,Vector acceleration,double elasticity):_radius(radius),_mass(mass),_position(position),_velocity(velocity),_acceleration(acceleration),_elasticity(elasticity){}

void Particle::update(double timeInterval)
{
    _lastAcceleration=_acceleration;
    _lastVelocity=_velocity;
    
    _position+=_lastVelocity*timeInterval;
	_velocity+=_lastAcceleration*timeInterval;
	
    _acceleration=Vector::zeroVector();
}

void Particle::reflectAbout(const Vector& axis)
{
    _velocity.symmetrizeAbout(axis);
    Vector n=axis.rotate(M_PI/2);
    double nComp=_velocity.componentAlongAxis(n);
    _velocity+=n*nComp*(_elasticity*_elasticity-1);
}

double Particle::distanceTo(const Particle &e)const
{
    const Vector& p0=this->position();
    const Vector& p1=e.position();
    Vector v=p1-p0;
    return v.modulus();
}

bool Particle::collideWith(const Particle& e)const
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

void Particle::handleCollision(Particle& Particle1,Particle& Particle2)
{
    double m1=Particle1._mass;
    double m2=Particle2._mass;
    Vector collisionAxis=(Particle2.position()-Particle1.position()).unitVector();
    double v1=Particle1.velocity().componentAlongAxis(collisionAxis);
    double v2=Particle2.velocity().componentAlongAxis(collisionAxis);
    double V1=Particle1._elasticity*((m1-m2)*v1+2*m2*v2)/(m1+m2);
    double V2=Particle2._elasticity*((m2-m1)*v2+2*m1*v1)/(m2+m1);
    double e=Particle1._elasticity*Particle2._elasticity;
    double v=v1-v2>=0?v1-v2:v2-v1;
    double dv=v*(1-e);
    double dv1=dv*m2/(m1+m2);
    double dv2=dv*m1/(m1+m2);
    V1+=dv1;
    V2+=dv2;
    Particle1._velocity+=collisionAxis*(V1-v1);
    Particle2._velocity+=collisionAxis*(V2-v2);
}

std::string Particle::description()const
{
	std::stringstream ss;
	ss<<"position: "<<_position.description()<<"\n";
	ss<<"velocity: "<<_velocity.description()<<"\n";
	ss<<"acceleration: "<<_acceleration.description()<<"\n";
	ss<<"\n";
	return ss.str();
}

double Particle::radius()const
{
    return _radius;
}
const Vector& Particle::position()const
{
	return _position;
}
const Vector& Particle::velocity()const
{
	return _velocity;
}
const Vector& Particle::acceleration()const
{
	return _acceleration;
}
