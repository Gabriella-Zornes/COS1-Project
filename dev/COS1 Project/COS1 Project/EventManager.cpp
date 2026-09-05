#include "EventManager.h"
#include <iostream>


EventManager::EventManager()
{
	currentEvent = 0;
}

void EventManager::Run()
{
	bool running = true;

	while (running)
	{
		Event e;

		switch (currentEvent)
		{
		case 0:
			std::cout << "=========================================== \n";
			std::cout << "   Welcome to the Abanondoned District \n";
			std::cout << "=========================================== \n";

			std::cout << " You are the last one left on the bus. The bus drops you off at the edge of the old industrial district. \n";
			std::cout << " A tall, overgrown building looma ahead, silent and forgotten. \n";
			std::cout << " The air feels heavier than it should... \n";

			e.AddChoice("1. Approach the building");
			e.AddChoice("2. Look around the street");
			e.AddChoice("3. Leave the area");

			e.DisplayChoices();

			int choice;
			std::cin >> choice;

			if (choice == 1) currentEvent = 1;
			else if (choice == 2) currentEvent = 2;
			else running = false;
			break;






		}
	}
}


