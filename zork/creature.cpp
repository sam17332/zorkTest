#include <iostream>
#include "room.h"
#include "creature.h"

Creature::Creature(const char *title, const char *description, Room *room) : Entity(title, description, (Entity *)room)
{
	type = CREATURE;
}

Creature::~Creature()
{
}

void Creature::ReceiveAttack(int damage)
{
	life = life - damage;

	if (life != 0)
	{
		cout << "He's still not dead, attack him again!" << "\n";
	}
	else
	{
		cout << "You kill him! Now open the hole to go out" << "\n";

		dead = true;
	}
}