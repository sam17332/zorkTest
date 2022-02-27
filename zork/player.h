#include <iostream>
#include <string>
using namespace std;

class Player
{
private:
    int actualRoom;

public:
    Player(const char *name, const char *description, Room *room);
    ~Player();

    bool hasKey;
    bool isTied;

public:
};