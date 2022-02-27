#ifndef _World
#define _World

#include <string>
#include <list>
#include <time.h>

#define TICK_FREQUENCY 0.5f

using namespace std;

class Entity;
class Player;

class World
{
public:
    World();
    ~World();

private:
    Player *player;
    list<Entity *> entities;
};

#endif //_World