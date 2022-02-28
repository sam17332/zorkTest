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

class World
{
public:
    World();
    ~World();

    bool ValidateInput(string input);

public:
    bool finished;

private:
    Player *player;
    vector<Room *> rooms;
    vector<Item *> items;
    vector<Door *> doors;
    vector<Machine *> machines;
};

#endif //_World