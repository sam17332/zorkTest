#include <iostream>
#include <string>
#include "entity.h"

using namespace std;

enum ItemType
{
    KEY,
    BATTERY,
    TOOL,
    WEAPON
};

class Item : public Entity
{
public:
    Item(const char *name, const char *description, Entity *parent, ItemType item_type);

public:
    ItemType type;
    std::string name;
    std::string description;
    Entity *parent;
};