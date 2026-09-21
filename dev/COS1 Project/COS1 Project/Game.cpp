

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
    std::cout << "2. Load Game\n";
	std::cout << "3. Exit Game \n";

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
            else if (option == 2) // Resume Game
            {
                EventManager manager;

                if (manager.LoadGame("save.txt"))
                {
                    manager.Run();   // jump straight into saved event
                    break;
                }
                else
                {
                    std::cout << "No saved game found.\n\n";
                    continue;
                }
                break;
            }
            else if (option == 3)
            {
                std::cout << "Exiting game...\n";
                break;
            }
      }
    


}