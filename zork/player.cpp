#include <iostream>
#include <vector>
#include "player.h"
#include "creature.h"
#include "room.h"
#include "item.h"

Player::Player(const char *title, const char *description, Room *room) : Creature(title, description, room), room(room)
{
	type = PLAYER;
}

Player::~Player()
{
}

/*
* Function to get name of the room where the player is
*/
string Player::GetRoomsName()
{
	return room->name;
}

/*
* Function to untie the player
*/
void Player::Untie()
{
	if (isTied)
	{
		isTied = false;
	}
	cout << "You are no longer tied."
		 << "\n";
}

/*
* Function to change the actual room of the player
*/
void Player::ChangeRoom(Room *roomParam)
{
	room = roomParam;
	room->Visit();
}

/*
* Function to take an item
*/
void Player::TakeItem(Item *itemParam, string roomName)
{
	string parentName = itemParam->parent->name;
	string itemName = itemParam->name;

	if (roomName != parentName)
	{
		cout << "The item '" << itemParam->name << "' you are trying to take is not in this room."
			 << "\n";
	}
	else
	{
		Item *item = itemParam->ChangeParent(this);
		items.push_back(item);
		cout << item->name << " taken"
			 << "\n \n";

		ShowInventory();
	}
}

/*
* Function to drop an item
*/
void Player::DropItem(Item *itemParam, Room *room)
{
	int index;

	for (int i = 0; i < items.size(); i++)
	{
		if (items[i]->name == itemParam->name)
		{
			index = i;
			break;
		}
	}

	Item *item = itemParam->ChangeParent(room);
	items.erase(items.begin() + index);
	cout << item->name << " dropped"
		 << "\n \n";

	ShowInventory();
}

/*
* Function to show the players inventory
*/
void Player::ShowInventory()
{
	if (items.size() == 0)
	{
		cout << "Inventory empty"
			 << "\n";
	}
	else
	{
		cout << "Inventory: "
			 << "\n";

		for (int i = 0; i < items.size(); i++)
		{
			cout << "-" << items[i]->name << "\n";
		}
	}
}

/*
* Function to show the room where the player is
*/
void Player::ShowRoom()
{
	cout << "Actual room: " << GetRoomsName() << "\n";
}


/*
* Function to do needed the logic when an item is used
*/
void Player::UseItem(ItemType type)
{
	Item *item = SearchItem(type, true);
	cout << "A borrar: " << item->name << "\n";
	delete item;

	if (type == 0) //Key
	{
		hasKey = false;
	}
	else if (type == 1) //Key card
	{
		hasKeyCard = false;
	}
	else if (type == 2) //Battery
	{
		hasBattery = false;
	}
	else if (type == 3) //Tool
	{
		hasPickaxe = false;
	}
	else if (type == 4) //Weapon
	{
		hasKnife = false;
	}
}

/*
* Function to do needed the logic when the machine is used
*/
void Player::UseMachine(Machine *machine, bool inPresentParam)
{
	cout << "machine " << inPresentParam << "\n";
}

/*
* Function to search for an especific item
*/
Item* Player::SearchItem(ItemType type, bool deleteParam)
{
	int index;

	for (int i = 0; i < items.size(); i++)
	{
		if (items[i]->itemType == type)
		{
			index = i;
			break;
		}
	}

	Item *item = items[index];

	// Only if needed is deleted from dthe items of the player
	if (deleteParam)
	{
		items.erase(items.begin() + index);
	}

	return item;
}