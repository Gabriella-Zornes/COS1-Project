

#include <iostream>
#include "Game.h"
#include "EventManager.h"

void Game::Title()
{
	std::cout << "============================= \n";
	std::cout << "    THE ABANDONED DISTRICT    \n";
	std::cout << "============================= \n";

}
void Game::ShowMenu()
{
	
	std::cout << "1. Start Game \n";
	std::cout << "2. Exit Game \n";

}

Game::Game()
{
}

void Game::Run()
{
	Title();
    while (true)
      {
            ShowMenu();
            std::cout << "Enter menu option: ";

            std::string input;
            std::getline(std::cin, input);

            int option = 0; 

            try
            {
                option = std::stoi(input); 
            }
            catch (...)
            {
                std::cout << "Invalid option. Numbers only.\n\n";
                continue; // reprompt menu
            }

            if (option == 1)
            {
                EventManager manager;
                manager.Run();
                break;
            }
            else if (option == 2)
            {
                std::cout << "Exiting game...\n";
                break;
            }
            else
            {
                std::cout << "Invalid option. Please try again.\n\n";
            }
      }
    


}