#ifndef _Creature
#define _Creature

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

#endif //_Creature