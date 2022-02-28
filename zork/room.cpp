#include <iostream>
#include "item.h"
#include "room.h"

Room::Room(const char *title, const char *description) : Entity(title, description, NULL)
{
	type = ROOM;
}

Room::~Room()
{
}

/*
* Prints the information depending if the room was already visited or not.
*/
void Room::Visit()
{
	cout << name << "\n";

	if (!visited)
	{
		cout << description << "\n";
		visited = true;
	}
}

/*
* Specific function to print information when the player enters the
* storage from the other dimension.
*/
void Room::VisitStorageOtherDimension()
{
	cout << "It looks like a few years ago there was a hole on the wall, maybe you can open it with somethig" << "\n";
}