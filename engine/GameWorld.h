#ifndef GAMEWORLD_H
#define GAMEWORLD_H

#include "Vector.h"
#include "Entity.h"
#include <vector>

typedef struct tagFrame
{
	float left;
	float top;
	float right;
	float bottom;
}Frame;

class GameWorld
{
public:
	//Constructors
	GameWorld(Frame frame,Vector gravity,float damping);
    //Destructor
    ~GameWorld();

	//Accessors
	const Frame& frame()const;

	void addEntity(Entity* entity);

	void update(float timeInterval);

private:
	void bounce(Entity* entity)const;
	Frame _frame;
	Vector _gravity;
	float _damping;
	std::vector<Entity*> _entities;
};

#endif