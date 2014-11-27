#ifndef COOLPHYSICS2D_GAMEWORLD_H
#define COOLPHYSICS2D_GAMEWORLD_H

#include "config.h"
#include "Vector.h"
#include "Particle.h"
#include "Field.h"
#include "Rectangle.h"

#include <vector>

BEGIN_NAMESPACE_COOLPHYSICS2D

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

END_NAMESPACE_COOLPHYSICS2D

#endif
