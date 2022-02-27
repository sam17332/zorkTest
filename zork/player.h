#ifndef _Player
#define _Player

#include "creature.h"

using namespace std;

class Player : public Creature
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

#endif //_Player