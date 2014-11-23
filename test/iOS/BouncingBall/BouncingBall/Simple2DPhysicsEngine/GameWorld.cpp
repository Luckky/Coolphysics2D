#include "GameWorld.h"

GameWorld::GameWorld(Frame frame,Vector gravity,double damping):_frame(frame),_gravity(gravity),_damping(damping){}
GameWorld::~GameWorld()
{
    for (int i=0; i<_entities.size(); i++) {
        delete _entities[i];
    }
}

const Frame& GameWorld::frame()const
{
	return _frame;
}

void GameWorld::addEntity(Entity* entity)
{
	_entities.push_back(entity);
}

void GameWorld::update(double timeInterval)
{
    for (int i=0; i<_entities.size(); i++) {
        Entity* ei=_entities[i];
        bounce(ei);
        ei->update(timeInterval,_gravity,_damping);
        for (int j=i+1; j<_entities.size(); j++) {
            Entity* ej=_entities[j];
            if (_entities[i]->collideWith(*_entities[j])) {
                Entity::handleCollision(*ei,*ej);
            }
        }
    }
}

void GameWorld::bounce(Entity* entity)const
{
	double x=entity->position().x();
	double y=entity->position().y();
    double vx=entity->velocity().x();
    double vy=entity->velocity().y();
    double r=entity->radius();
	if ((x+r>_frame.right&&vx>0)||(x-r<_frame.left&&vx<0)){
		entity->reflectAbout(Vector(0,1));
	}else if((y-r<_frame.top&&vy<0)||(y+r>_frame.bottom&&vy>0)){
		entity->reflectAbout(Vector(1,0));
	}
}
