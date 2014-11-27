#ifndef BUOYANCYFIELD_H
#define BUOYANCYFIELD_H

#include "Field.h"
#include "GravityField.h"

class BuoyancyField:public Field
{
public:
    BuoyancyField(Rectangle range,const GravityField& gravityField,double density);
    virtual void actOn(Particle& particle)const;
private:
    Vector _gravity;
    double _density;
};

#endif