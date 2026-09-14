

#include <iostream>
#include "Game.h"
#include "EventManager.h"

void Game::ShowMenu()
{
	std::cout << "============================= \n";
	std::cout << "    THE ABANDONED DISTRICT    \n";
	std::cout << "============================= \n";

	std::cout << "1. Start Game \n";
	std::cout << "2. Exit Game \n";

}

Game::Game()
{
}

void Game::Run()
{
	int option = 0;
	bool valid = false;

	while (!valid)
	{
		ShowMenu();
		std::cout << "Enter menu option: ";
		std::cin >> option;

		if (option == 1)
		{
			valid = true;
			EventManager manager;
			manager.Run();
		}
		else if (option == 2)
		{
			std::cout << "Exiting game...";
		}
		else
		{
			std::cout << "Invalid option. Please try again. \n\n";
		}
	}

}