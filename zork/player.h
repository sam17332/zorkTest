#ifndef _Player
#define _Player

#include <vector>
#include "creature.h"

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
    void ChangeRoom(Room *room);
    void TakeItem(Item *item, string roomName);
    void DropItem(Item *item, Room *room);
    void ShowInventory();

public:
    bool hasKey;
    bool hasKeyCard;
    bool hasKnife;
    bool hasbattery;
    bool hasPickaxe;
    bool isTied;
    bool inPresent;
    Room *room;
    vector<Item *> items;
};

#endif //_Player