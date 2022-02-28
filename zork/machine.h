#ifndef _Machine
#define _Machine

#include "entity.h"

using namespace std;

class Machine : public Entity
{
public:
    Machine(const char *name, const char *description, Entity *parent, Item *chargesWith, bool charged = false);
    ~Machine();

public:
    bool charged;
};

#endif //_Machine