

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

	ShowMenu();
	std::cout << "Enter option: ";
	std::cin >> option;

	if (option == 1)
	{
		EventManager manager;
		manager.LoadEvents();
		manager.Run();
	}
	else
	{
		std::cout << "Exiting game...";
	}


}