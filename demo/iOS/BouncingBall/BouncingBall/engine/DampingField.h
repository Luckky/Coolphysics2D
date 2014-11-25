#ifndef DAMPINGYFIELD_H
#define DAMPINGYFIELD_H

#include "Field.h"

class DampingField:public Field
{
public:
    DampingField(const Rectangle& range,double damping);
    virtual ~DampingField();
    virtual void actOn(Particle& particle)const;
private:
    double _damping;
};

#endif