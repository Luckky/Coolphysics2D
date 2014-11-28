#include "ParticleEmitter.h"
#include "Particle.h"
#include "GameWorld.h"

#include <math.h>

#define RAND(min,max)   min+(max-min)*((double)rand()/RAND_MAX);

BEGIN_NAMESPACE_COOLPHYSICS2D

ParticleEmitter::ParticleEmitter(GameWorld& gameWorld,const Vector& position,double frequency,double minRadius,double maxRadius,double minMass,double maxMass,double minElasticity,double maxElasticity,double minSpeed,double maxSpeed,double minRadian,double maxRadian):_gameWorld(gameWorld),_position(position),_frequency(frequency),_minRadius(minRadius),_maxRadius(maxRadius),_minMass(minMass),_maxMass(maxMass),_minElasticity(minElasticity),_maxElasticity(maxElasticity),_minSpeed(minSpeed),_maxSpeed(maxSpeed),_minRadian(minSpeed),_maxRadian(maxSpeed),_time(0),_particleCount(0){}

ParticleEmitter::~ParticleEmitter(){}

void ParticleEmitter::emit(double interval)
{
    _time+=interval;
    int stock=_particleCount;
    _particleCount=_time*_frequency;
    int inc=_particleCount-stock;
    for (int i=0; i<inc; i++) {
        double radius=RAND(_minRadius, _maxRadius);
        double mass=RAND(_minMass, _maxMass);
        double elasticity=RAND(_minElasticity, _maxElasticity);
        double speed=RAND(_minSpeed, _maxSpeed);
        double radian=RAND(_minRadian, _maxRadian);
        
        Particle* particle=new Particle(radius,mass,elasticity,_position,Vector::vectorMake(speed, radian),Vector::zeroVector());
        _gameWorld.addParticle(particle);
    }
}

END_NAMESPACE_COOLPHYSICS2D