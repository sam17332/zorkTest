#include <iostream>
#include <string>
#include "world.h"

using namespace std;

/*
 *   Prints the text to welcome the player and to introduce
 *   the story of the game.
 */
void initialText()
{
	cout << "\n";
	cout << "Welcome to Lab Zork!"
		 << "\n";
	cout << "\n";
	cout << "You are just waking up! You have been kidnapped."
		 << "\n";
	cout << "You are looking around and it seems you are inside a laboratory."
		 << "\n";
	cout << "What they were doing to you? Why is there no one here?"
		 << "\n";
	cout << "\n";
}

int main()
{
	initialText();

	World world;
	string input;

	bool exit = true;
	while (exit)
	{
		std::getline(std::cin, input);

		if(!world.ValidateInput(input))
		{
			cout << "Thats something I dont understand."
 				 << "\n"
 				 << "\n";
		}
	}

	return 0;
}