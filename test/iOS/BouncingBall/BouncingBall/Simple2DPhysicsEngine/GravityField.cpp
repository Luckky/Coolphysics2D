#include "GravityField.h"

GravityField::GravityField(const Rectangle& range,const Vector& gravity):Field(range),_gravity(gravity){}

GravityField::~GravityField(){}

void GravityField::actOn(Particle& particle)const
{
    particle._acceleration+=_gravity;
}