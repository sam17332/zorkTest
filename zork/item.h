#ifndef _Item
#define _Item

#include <iostream>
#include <string>
#include "entity.h"

using namespace std;

enum ItemType
{
    KEY,
    KEYCARD,
    BATTERY,
    TOOL,
    WEAPON
};

class Item : public Entity
{
public:
    Item(const char *name, const char *description, Entity *parent, ItemType itemType);
    ~Item();

    Item *ChangeParent(Entity *newParent);

public:
    ItemType itemType;
    string name;
    string description;
    Entity *parent;
    int damage;
};

#endif //_Item