#ifndef COOLPHYSICS2D_EMITTER_H
#define COOLPHYSICS2D_EMITTER_H

class Emitter
{
public:
    void emit(double interval)const;
private:
    double _minInterval;
    double _maxInterval;
    double _minRadius;
    double _maxRadius;
    double _minSpeed;
    double _maxSpeed;
    double _minRadian;
    double _maxRadian;
};

#endif