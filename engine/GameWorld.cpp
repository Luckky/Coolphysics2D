#include "GameWorld.h"

GameWorld::GameWorld(Frame frame,Vector gravity,float damping):_frame(frame),_gravity(gravity),_damping(damping){}
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

void GameWorld::update(float timeInterval)
{
//	for(std::vector<Entity>::iterator it=_entities.begin();it!=_entities.end();it++)
//	{
//		it->update(timeInterval);
//		//bounce(*it);
//	}
    for (int i=0; i<_entities.size(); i++) {
        _entities[i]->update(timeInterval,_gravity,_damping);
        bounce(_entities[i]);
    }
}

void GameWorld::bounce(Entity* entity)const
{
	float x=entity->position().x();
	float y=entity->position().y();
    float vx=entity->velocity().x();
    float vy=entity->velocity().y();
	if ((x>_frame.right&&vx>0)||(x<_frame.left&&vx<0)){
		entity->reflectAbout(Vector(0,1));
	}else if((y<_frame.top&&vy<0)||(y>_frame.bottom&&vy>0)){
		entity->reflectAbout(Vector(1,0));
	}
}