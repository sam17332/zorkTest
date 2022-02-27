#ifndef _Door
#define _Door

#include "entity.h"

using namespace std;

class Door : public Entity
{
public:
    Door(const char *name, const char *description, Room *room1, Room *room2, Item *opensWith, bool locked = true);
    ~Door();

public:
};

#endif //_Door