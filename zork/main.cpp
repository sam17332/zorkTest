#include <iostream>
#include <string>
#include <vector>
#include "player.h"

using namespace std;

/*
 *   Prints the text to welcome the player and to introduce
 *   the story of the game.
 */
void initialText()
{
	cout << "\n";
	cout << "\n";
	cout << "Welcome to Zork!"
		 << "\n";
	cout << "It seems that you have been kidnapped and you are just waking up."
		 << "\n";
	cout << "\n";
	cout << "\n";
}

/*
 *   Depending on the room the player is, are the words that the game understands.
 */
bool validateInput(string input, int roomId)
{
	bool valid = true;
	cout << input << "\n";

	if (roomId == 1)
	{
		std::vector<string> options{"untie", "take lamp", "drop lamp", "go garden"};
		std::vector<string>::iterator iterator;

		iterator = std::find(options.begin(), options.end(), input);

		if (iterator == options.end())
		{
			valid = false;
			cout << "Thats something I dont understand."
				 << "\n"
				 << "\n";
		}
	}

	return valid;
}

int main()
{
	initialText();

	Player player(1);
	string input;
	int roomId;

	// printf("room id %d\n", roomId);

	bool exit = true;
	while (exit)
	{
		std::getline(std::cin, input);
		roomId = player.getActualRoom();

		if (!validateInput(input, roomId))
		{
			continue;
		}

		cout << "Continua";
	}

	return 0;
}