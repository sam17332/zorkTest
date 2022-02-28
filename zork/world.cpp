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

    rooms.push_back(mainLab); // 0
    rooms.push_back(lab); // 1
    rooms.push_back(computing); // 2
    rooms.push_back(experiments); // 3
    rooms.push_back(secret); // 4
    rooms.push_back(storage); // 5
    rooms.push_back(street); // 6

    // Create items
    Item *key = new Item("Key", "Storage key", computing, KEY);
    Item *keyCard = new Item("KeyCard", "Secrete key", mainLab, KEYCARD);
    Item *knife = new Item("Knife", "Sharp knife", lab, WEAPON);
    Item *battery = new Item("Battery", "Charged battery", storage, BATTERY);
    Item *pickaxe = new Item("Pickaxe", "Big pickaxe", experiments, BATTERY);

    items.push_back(key); // 0
    items.push_back(keyCard); // 1
    items.push_back(knife); // 2
    items.push_back(battery); // 3
    items.push_back(pickaxe); // 4

    // Create doors
    Door *labStorage = new Door("Door1", "This door is between the lab room and the storage room", lab, storage, key, true);
    Door *secretExperiments = new Door("Doo2", "This door is between the experimients room and the secrete room", experiments, secret, keyCard, true);

    doors.push_back(labStorage); // 0
    doors.push_back(secretExperiments); // 1

    // Create machine
    Machine *machine = new Machine("Machine", "I could send you to another dimension.", secret, battery, false);

    machines.push_back(machine); // 0

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
            if (input == "take key")
            {
                player->TakeItem(items[0], actualRoomName);
                player->hasKey = true;

                return true;
            }
            else if (input == "drop key")
            {
                player->DropItem(items[0], actualRoom);
                player->hasKey = true;

                return true;
            }
            else if (input == "take key card")
            {
                player->TakeItem(items[1], actualRoomName);
                player->hasKeyCard = true;

                return true;
            }
            else if (input == "drop key card")
            {
                player->DropItem(items[1], actualRoom);
                player->hasKeyCard = true;

                return true;
            }
            else if (input == "take knife")
            {
                player->TakeItem(items[2], actualRoomName);
                player->hasKnife = true;

                return true;
            }
            else if (input == "drop knife")
            {
                player->DropItem(items[2], actualRoom);
                player->hasKnife = true;

                return true;
            }
            else if (input == "take battery")
            {
                player->TakeItem(items[3], actualRoomName);
                player->hasBattery = true;

                return true;
            }
            else if (input == "drop battery")
            {
                player->DropItem(items[3], actualRoom);
                player->hasBattery = true;

                return true;
            }
            else if (input == "take pickaxe")
            {
                player->TakeItem(items[3], actualRoomName);
                player->hasPickaxe = true;

                return true;
            }
            else if (input == "drop pickaxe")
            {
                player->DropItem(items[3], actualRoom);
                player->hasPickaxe = true;

                return true;
            }
        }

        if (input == "show inventory" || input == "inventory")
        {
            player->ShowInventory();

            return true;
        }

        if (input == "show room" || input == "room")
        {
            player->ShowRoom();

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

                    return true;
                }
                else
                {
                    valid = false;
                }
            }
        }
        else if (actualRoomName == "Lab")
        {
            // Obtain the door between lab and storage rooms.
            Door *door = doors[0];

            if (input == "go main lab")
            {
                player->ChangeRoom(rooms[0]);

                valid = true;
            }
            else if (input == "go computing")
            {
                player->ChangeRoom(rooms[2]);

                valid = true;
            }
            else if (input == "go storage")
            {
                if (!door->locked)
                {
                    player->ChangeRoom(rooms[5]);

                    valid = true;
                }
                else
                {
                    cout << "The door is locked, you need the key to open it."
                         << "\n";

                    valid = true;
                }
            }
            else if (input == "open door" || input == "use key")
            {
                if (!door->locked)
                {
                    cout << "The door is opened."
                         << "\n";

                    valid = true;
                }
                else if (player->hasKey)
                {
                    door->locked = false;
                    cout << "Door to storage opened!"
                         << "\n";

                    valid = true;
                }
                else
                {
                    cout << "You need the key to open the door."
                         << "\n";

                    valid = true;
                }
            }
            else
            {
                valid = false;
            }
        }
        else if (actualRoomName == "Computing")
        {
            if (input == "go lab")
            {
                player->ChangeRoom(rooms[1]);

                valid = true;
            }
            if (input == "go experiments")
            {
                player->ChangeRoom(rooms[3]);

                valid = true;
            }
            else
            {
                valid = false;
            }
        }
        else if (actualRoomName == "Experiments")
        {
            // Obtain the door between experiments and secrete rooms.
            Door *door = doors[1];

            if (input == "go computing")
            {
                player->ChangeRoom(rooms[2]);

                valid = true;
            }
            else if (input == "go secrete")
            {
                if (!door->locked)
                {
                    player->ChangeRoom(rooms[4]);

                    valid = true;
                }
                else
                {
                    cout << "The door is locked, you need the key card to open it."
                         << "\n";

                    valid = true;
                }
            }
            else if (input == "open door" || input == "use key card")
            {
                if (!door->locked)
                {
                    cout << "The door is opened."
                         << "\n";

                    valid = true;
                }
                else if (player->hasKeyCard)
                {
                    player->UseItem(KEYCARD);
                    door->locked = false;
                    cout << "Door to secrete opened!"
                         << "\n";

                    valid = true;
                }
                else
                {
                    cout << "You need the key card to open the door."
                         << "\n";

                    valid = true;
                }
            }
            else
            {
                valid = false;
            }
        }
        else if (actualRoomName == "Secrete")
        {
            Machine *machine = machines[0];
            if (input == "go experiments")
            {
                player->ChangeRoom(rooms[3]);

                return true;
            }
            if (input == "use machine")
            {
                if (machine->charged)
                {
                    player->UseMachine(machine);
                }

                return true;
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