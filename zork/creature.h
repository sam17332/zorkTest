#ifndef __Creature__
#define __Creature__

#include <string>
#include "entity.h"

class Room;
class Item;

using namespace std;

class Creature : public Entity
{
public:
	Creature(const char *name, const char *description, Room *room);
	~Creature();

public:
};

#endif //__Creature__