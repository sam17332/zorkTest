#include <iostream>
#include <string>
using namespace std;

class Player
{
private:
    int actualRoom;

public:
    Player(int roomId) : actualRoom(roomId) {};
    bool hasKey = false;
    bool isTied = true;
    int getActualRoom();
    void changeHasKey(bool value);
    void changeActualRoom(int id);
};