#ifndef FIELD_H
#define FIELD_H

#include "Particle.h"
#include "Structs.h"
#include "Rectangle.h"

class Field
{
public:
    Field(const Rectangle& range);
    virtual ~Field();
    virtual void actOn(Particle& particle)const=0;
protected:
     Rectangle _range;
};

#endif