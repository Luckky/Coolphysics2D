#ifndef GAMEWORLD_H
#define GAMEWORLD_H

#include "Vector.h"
#include "Entity.h"
#include <vector>

typedef struct tagFrame
{
	double left;
	double top;
	double right;
	double bottom;
}Frame;

class GameWorld
{
public:
	//Constructor
	GameWorld(Frame frame,Vector gravity,double damping);
    //Destructor
    ~GameWorld();

	//Accessor
	const Frame& frame()const;

	void addEntity(Entity* entity);

	void update(double timeInterval);

private:
	void bounce(Entity* entity)const;
	Frame _frame;
	Vector _gravity;
	double _damping;
	std::vector<Entity*> _entities;
};

#endif
