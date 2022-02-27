#ifndef __Room__
#define __Room__

#include <string>
#include "entity.h"

using namespace std;

class Room : public Entity
{
public:
    Room(const int id, const char *name, const char *description);
    ~Room();

public:
    bool visited;
};

#endif //__Room__