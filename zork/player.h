#ifndef _Player
#define _Player

#include <vector>
#include "creature.h"
#include "item.h"

using namespace std;

class Room;
class Item;

class Player : public Creature
{
private:
    int actualRoom;

public:
    Player(const char *name, const char *description, Room *room);
    ~Player();

    string GetRoomsName();
    void Untie();
    void ShowRoom();
    void ChangeRoom(Room *room);
    void TakeItem(Item *item, string roomName);
    void DropItem(Item *item, Room *room);
    void ShowInventory();
    void UseItem(ItemType type);
    void UseMachine();
    void UseKnife(Creature *creature, Item *item);
    Item *SearchItem(ItemType type, bool deleteParam);

public:
    bool hasKey;
    bool hasKeyCard;
    bool hasKnife;
    bool hasBattery;
    bool hasPickaxe;
    bool isTied;
    bool inPresent;
    bool returned;
    Room *room;
    vector<Item *> items;
};

#endif //_Player