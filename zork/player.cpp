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

string Player::GetRoomsName()
{
	return room->name;
}

void Player::Untie()
{
	if (isTied)
	{
		isTied = false;
	}
	cout << "You are no longer tied."
		 << "\n";
}

void Player::ChangeRoom(Room *roomParam)
{
	room = roomParam;

	cout << "\n";
	cout << room->name << "\n";
	cout << room->description << "\n";
}

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
	cout << item->name << " dropped"
		 << "\n \n";
	items.erase(items.begin() + index);

	ShowInventory();
}

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

void Player::ShowRoom()
{
	cout << "Actual room: " << GetRoomsName() << "\n";
}
