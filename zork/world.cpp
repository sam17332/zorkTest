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

    rooms.push_back(mainLab);
    rooms.push_back(lab);
    rooms.push_back(computing);
    rooms.push_back(experiments);
    rooms.push_back(secret);
    rooms.push_back(storage);
    rooms.push_back(street);

    // Create items
    Item *key = new Item("Key", "Storage key", computing, KEY);
    Item *keyCard = new Item("KeyCard", "Secrete key", mainLab, KEY);
    Item *knife = new Item("Knife", "Sharp knife", lab, WEAPON);
    Item *battery = new Item("Battery", "Charged battery", storage, BATTERY);
    Item *pickaxe = new Item("Pickaxe", "Big pickaxe", experiments, BATTERY);

    items.push_back(key);
    items.push_back(keyCard);
    items.push_back(knife);
    items.push_back(battery);
    items.push_back(pickaxe);

    // Create doors
    Door *labStorage = new Door("Door1", "This door is between the lab room and the storage room", lab, storage, key, true);
    Door *secretExperiments = new Door("Doo2", "This door is between the experimients room and the secrete room", experiments, secret, keyCard, true);

    doors.push_back(labStorage);
    doors.push_back(secretExperiments);

    // Create machine
    Machine *machine = new Machine("Machine", "I could send you to another dimension.", secret, battery, false);

    machines.push_back(machine);

    // Create player
    player = new Player("Subject 34", "Subject shows big compatibilities with our travel test", mainLab);
    player->isTied = true;
    player->inPresent = true;

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
    string actualRoomName = player->GetRoomsName();
    Room *actualRoom = player->room;

    if (player->inPresent)
    {
        // If player is no longer tied
        if (!player->isTied)
        {
            // Since the take/drop actions can be used in any room,
            // we need the conditions for them outside of the conditions for each room.
            if (input == "take key card")
            {
                player->TakeItem(items[1], actualRoomName);
                player->hasKeyCard = true;
                return true;
            }
            else if (input == "drop key card")
            {
                player->hasKeyCard = true;
                player->DropItem(items[1], actualRoom);
                return true;
            }

            if (input == "take knife")
            {
                player->TakeItem(items[1], actualRoomName);
                player->hasKnife = true;
                return true;
            }
            else if (input == "drop knife")
            {
                player->hasKnife = true;
                player->DropItem(items[1], actualRoom);
                return true;
            }
        }

        if (input == "show inventory" || input == "inventory")
        {
            player->ShowInventory();
            return true;
        }

        if (actualRoomName == "MainLab")
        {
            // If player is no longer tied
            if (player->isTied)
            {
                if (input == "untie")
                {
                    player->Untie();
                    return true;
                }
                else
                {
                    cout << "You are still tied."
                         << "\n";
                    return true;
                }
            }
            else
            {
                if (input == "go lab")
                {
                    player->ChangeRoom(rooms[1]);
                }
                else
                {
                    valid = false;
                }
            }
        }
        if (actualRoomName == "Lab")
        {
            if (input == "go main lab")
            {
                player->ChangeRoom(rooms[0]);
            }
            else if (input == "go computing")
            {
                player->ChangeRoom(rooms[2]);
            }
            else if (input == "go storage")
            {
                if (false)
                {
                    player->ChangeRoom(rooms[6]);
                }
            }
            else
            {
                valid = false;
            }
        }
    }
    else
    {
        cout << "You are no longer in your present. You are on another dimension."
             << "\n";
    }

    return valid;
}