#ifndef _Entity
#define _Entity

#include <string>
#include <list>

using namespace std;

enum EntityType
{
	ENTITY,
	PLAYER,
	ROOM,
	ITEM,
	DOOR,
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

#endif //_Entity