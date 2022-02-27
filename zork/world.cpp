#include "world.h"
#include "room.h"
#include "item.h"
#include "door.h"
#include "player.h"

World::World()
{
    // Create rooms
    Room *mainLab = new Room(1, "MainLab", "You are tied to a chair, they scientists were trying to do somethig to you. There's a key card on the desk behind you.");
    Room *lab = new Room(2, "Lab", "There's a knife by the computing door.");
    Room *computing = new Room(3, "Computing", "ooooh look, someone forgot a key. I wonder what door will open.");
    Room *experiments = new Room(4, "Experiments", "There's a pickaxe? Why is there a pickaxe here? maybe you can destroy something with it?");
    Room *secret = new Room(5, "Secret", "There's a wierd machine in here.");
    Room *storage = new Room(6, "Storage", "There's a pickaxe battery in here.");
    Room *street = new Room(7, "Street", "Finally!! you are outside!");

    // Create items
    Item *key = new Item("Key", "Storage key", computing, KEY);
    Item *keyCard = new Item("KeyCard", "Secrete key", mainLab, KEY);
    Item *knife = new Item("Knife", "Sharp knife", lab, WEAPON);
    Item *battery = new Item("Battery", "Charged battery", storage, BATTERY);
    Item *pickaxe = new Item("Pickaxe", "Big pickaxe", experiments, BATTERY);

    // Create doors
    Door *labStorage = new Door("door1", "This door is between the lab room and the storage room", lab, storage, key, true);
    Door *secretExperiments = new Door("doo2", "This door is between the experimients room and the secrete room", experiments, secret, keyCard, true);

    // Create machine

    // Create player
    Player *player = new Player("Subject 34", "Subject shows big compatibilities with our travel test", mainLab);
    player->isTied = true;
}

World::~World()
{
}
