#ifndef COOLPHYSICS2D_PARTICLEEMITTER_H
#define COOLPHYSICS2D_PARTICLEEMITTER_H

#include "config.h"
#include "Vector.h"

BEGIN_NAMESPACE_COOLPHYSICS2D

class GameWorld;

class ParticleEmitter
{
public:
    //Constructor
    ParticleEmitter(GameWorld& gameWorld,const Vector& position,double frequency,double minRadius,double maxRadius,double minMass,double maxMass,double minElasticity,double maxElasticity,double minSpeed,double maxSpeed,double minRadian,double maxRadian);
    
    //Destructor
    ~ParticleEmitter();
    
    //Behavior
    void emit(double interval);
private:
    GameWorld& _gameWorld;
    Vector _position;
    double _frequency;
    
    double _minLifeTime;
    double _maxLifeTime;
    double _minRadius;
    double _maxRadius;
    double _minMass;
    double _maxMass;
    double _minElasticity;
    double _maxElasticity;
    double _minSpeed;
    double _maxSpeed;
    double _minRadian;
    double _maxRadian;
    
    
    double _time;
    int _particleCount;
};

END_NAMESPACE_COOLPHYSICS2D

#endif