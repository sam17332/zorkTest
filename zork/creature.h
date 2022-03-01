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

	void ReceiveAttack(int damage);

public:
	bool dead;
	int life;
};

#endif //_Creature