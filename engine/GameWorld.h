#ifndef GAMEWORLD_H
#define GAMEWORLD_H

#include "Vector.h"
#include "Particle.h"
#include "Field.h"
#include "Rectangle.h"

#include <vector>


class GameWorld
{
public:
	//Constructor
	GameWorld(Rectangle range);
    //Destructor
    ~GameWorld();

	//Accessor
	const Rectangle& range()const;

	void addParticle(Particle* Particle);
    void addField(Field* field);

	void update(double timeInterval);

private:
	void bounce(Particle* Particle)const;
	Rectangle _range;
	std::vector<Particle*> _particles;
    std::vector<Field*> _fields;
};

#endif
