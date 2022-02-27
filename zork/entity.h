#ifndef __Entity__
#define __Entity__

#include <string>
#include <list>

using namespace std;

enum EntityType
{
	PLAYER,
	ROOM,
	ITEM,
	EXIT,
	CREATURE,
};

class Entity
{
public:
	Entity(const char *name, const char *description, Entity *parent);
	~Entity();

public:
	EntityType type;
	std::string name;
	std::string description;

	Entity *parent;
	list<Entity *> container;
};

#endif //__Entity__