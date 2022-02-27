#include <vector>
#include "world.h"
#include "room.h"
#include "item.h"
#include "door.h"
#include "player.h"
#include "machine.h"

World::World()
{
    // Create rooms
    Room *mainLab = new Room("MainLab", "You are tied to a chair, the scientists were testing somethig with you. There's a key card on the desk behind you.");
    Room *lab = new Room("Lab", "There's a knife by the computing door.");
    Room *computing = new Room("Computing", "ooooh look, someone forgot a key. I wonder what door will open.");
    Room *experiments = new Room("Experiments", "There's a pickaxe? Why is there a pickaxe here? maybe you can destroy something with it?");
    Room *secret = new Room("Secret", "There's a wierd machine in here.");
    Room *storage = new Room("Storage", "There's a pickaxe battery in here.");
    Room *street = new Room("Street", "Finally!! you are outside!");

    // Create items
    Item *key = new Item("Key", "Storage key", computing, KEY);
    Item *keyCard = new Item("KeyCard", "Secrete key", mainLab, KEY);
    Item *knife = new Item("Knife", "Sharp knife", lab, WEAPON);
    Item *battery = new Item("Battery", "Charged battery", storage, BATTERY);
    Item *pickaxe = new Item("Pickaxe", "Big pickaxe", experiments, BATTERY);

    // Create doors
    Door *labStorage = new Door("Door1", "This door is between the lab room and the storage room", lab, storage, key, true);
    Door *secretExperiments = new Door("Doo2", "This door is between the experimients room and the secrete room", experiments, secret, keyCard, true);

    // Create machine
    Machine *machine = new Machine("Machine", "I could send you to another dimension.", secret, battery, false);

    // Create player
    player = new Player("Subject 34", "Subject shows big compatibilities with our travel test", mainLab);
    player->isTied = true;

    cout << mainLab->name << "\n";
    cout << mainLab->description << "\n";
    cout << "\n";
}

World::~World()
{
}

bool World::ValidateInput(string input)
{
    bool valid = true;
    string actualRoom = player->GetRoom();

    if (actualRoom == "MainLab")
    {
        std::vector<string> options{"untie", "take key card", "drop key card", "go lab"};
        std::vector<string>::iterator iterator;
        iterator = std::find(options.begin(), options.end(), input);

        if (player->isTied)
        {
            if (input === "untie")
            {
                player->Untie(;
            }
            else
            {
                cout << "You are still tied."
                     << "\n";
            }

        }
        else
        {
        }
    }
}

return valid;
}