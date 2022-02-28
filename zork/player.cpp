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
		cout << "The item " << itemParam->name << " you are trying to take is not in this room."
			 << "\n";
	}
	else
	{
		items.push_back(itemParam);
		Item *item = items[items.size()];
		cout << itemName << " taken"
			 << "\n";
	}
}

void Player::DropItem(Item *itemParam, Room *room)
{
	cout << "DropItem: " << itemParam->name;
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
			cout << items[i]->name << "\n";
		}
	}
}
