#ifndef _World
#define _World

#include <string>
#include <vector>

using namespace std;

class Room;
class Item;
class Door;
class Machine;
class Player;
class Creature;

class World
{
public:
    World();
    ~World();

    bool ValidateInput(string input);
    void Move();

public:
    bool finished;
    int moves;

private:
    Player *player;
    Creature *creature;
    vector<Room *> rooms;
    vector<Item *> items;
    vector<Door *> doors;
    vector<Machine *> machines;
};

#endif //_World