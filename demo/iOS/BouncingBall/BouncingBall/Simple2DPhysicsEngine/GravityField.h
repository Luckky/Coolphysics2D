#ifndef GRAVITYFIELD_H
#define GRAVITYFIELD_H

#include "Field.h"

class GravityField:public Field
{
public:
    GravityField(const Rectangle& range,const Vector& gravity);
    ~GravityField();
    virtual void actOn(Particle& particle)const;
private:
    Vector _gravity;
};

#endif