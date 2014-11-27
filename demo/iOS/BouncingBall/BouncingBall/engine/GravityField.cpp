#include "GravityField.h"

GravityField::GravityField(const Rectangle& range,const Vector& gravity):Field(range),_gravity(gravity){}

GravityField::~GravityField(){}

void GravityField::actOn(Particle& particle)const
{
    if (_range.overlap(particle.range())) {
        particle._acceleration+=_gravity;
    }
}

const Vector& GravityField::gravity()const
{
    return _gravity;
}