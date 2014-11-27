#include "GameWorld.h"

GameWorld::GameWorld(Rectangle range):_range(range){}
GameWorld::~GameWorld()
{
    for (int i=0; i<_particles.size(); i++) {
        delete _particles[i];
    }
    for (int i=0; i<_fields.size(); i++) {
        delete _fields[i];
    }
}

const Rectangle& GameWorld::range()const
{
	return _range;
}

void GameWorld::addParticle(Particle* Particle)
{
	_particles.push_back(Particle);
}
void GameWorld::addField(Field *field)
{
    _fields.push_back(field);
}

void GameWorld::update(double timeInterval)
{
    for (int i=0; i<_particles.size(); i++) {
        Particle* pi=_particles[i];
        bounce(pi);
        pi->update(timeInterval);
        for (int j=i+1; j<_particles.size(); j++) {
            Particle* pj=_particles[j];
            if (_particles[i]->collideWith(*_particles[j])) {
                Particle::handleCollision(*pi,*pj);
            }
        }
        
        for (int j=0; j<_fields.size(); j++) {
            _fields[j]->actOn(*_particles[i]);
        }
    }
}

void GameWorld::bounce(Particle* Particle)const
{
	double x=Particle->position().x();
	double y=Particle->position().y();
    double vx=Particle->velocity().x();
    double vy=Particle->velocity().y();
    double r=Particle->radius();
	if ((x+r>_range.width()&&vx>0)||(x-r<_range.x()&&vx<0)){
		Particle->reflectAbout(Vector(0,1));
	}else if((y-r<_range.y()&&vy<0)||(y+r>_range.height()&&vy>0)){
		Particle->reflectAbout(Vector(1,0));
	}
}
