#ifndef GRAVITYFIELD_H
#define GRAVITYFIELD_H

#include "Field.h"

class GravityField:public Field
{
public:
    GravityField(const Rectangle& range,const Vector& gravity);
    ~GravityField();
    virtual void actOn(Particle& particle)const;
    
    //Accessor
    const Vector& gravity()const;
private:
    Vector _gravity;
};

#endif