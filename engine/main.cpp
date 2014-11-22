#include "Entity.h"
#include "GameWorld.h"
#include <iostream>

int main()
{
	Entity* entity=new Entity(1,Vector(0,0),Vector(0,0),Vector(0,1));
	
	Frame frame;
	frame.left=0;
	frame.top=0;
	frame.right=200;
	frame.bottom=200;
	GameWorld gameWorld(frame,Vector(0,10),-0.1);
	gameWorld.addEntity(entity);
	for (int i = 0; i < 100; ++i)
	{
		gameWorld.update(0.1);
		std::cout<<entity->description();
	}
	return 0;
}