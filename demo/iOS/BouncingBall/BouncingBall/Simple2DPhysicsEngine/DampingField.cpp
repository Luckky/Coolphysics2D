#include "DampingField.h"

DampingField::DampingField(const Rectangle& range,double damping):Field(range),_damping(damping){}

DampingField::~DampingField(){}

void DampingField::actOn(Particle& particle)const
{
    if (_range.overlap(Circle(particle.position(),particle.radius()))) {
        particle._acceleration+=particle._velocity*_damping/particle._mass;
    }
}