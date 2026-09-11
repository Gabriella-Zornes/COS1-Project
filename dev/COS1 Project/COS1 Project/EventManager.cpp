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
			std::cout << "\n =========================================== \n";
			std::cout << "    Welcome to the Abanondoned District \n";
			std::cout <<    "=========================================== \n";

			std::cout << " You are the last one left on the bus. The bus drops you off at the edge of the old industrial district. \n";
			std::cout << " A tall, overgrown building looming ahead, silent and forgotten. \n";
			std::cout << " The air feels heavier than it should... \n""\n";

			std::cout << "Do you: \n";
			e.AddChoice("Approach the building");
			e.AddChoice("Look around the street");
			e.AddChoice("Leave the area"); //should leave the area be an option? do i want to force the player farther? 

			e.DisplayChoices();

			int choice;
			std::cout << "Enter what you would do next (1-3): ";
			std::cin >> choice;

			if (choice == 1) currentEvent = 1;
			else if (choice == 2) currentEvent = 2;
			else running = false;

			
			break;
		case 1:
			std::cout << "\n You approach the building...you notice that the doors are steel and covered in chains and covered with grime. \n";
			std::cout << " Though, you notice some of the chains are hanging loose. Looks like the doors have been forced opened... \n\n";
			
			std::cout << "Do you: \n";
			e.AddChoice("Open the door and go in");
			e.AddChoice("inspect the door farther");
			e.AddChoice("take a step back");
			
			e.DisplayChoices();

			int choice1;
			std::cout << "Enter what you would do next (1-3): ";
			std::cin >> choice1;

			if (choice1 == 1) currentEvent = 3;
			else if (choice1 == 2) currentEvent = 4;
			else currentEvent = 0;

			break;

		case 2:
			std::cout << "\n You look around at the street you're on...there's no one around. \n";
			std::cout << "The street is silent, street lights flickering even though the power seems like it should be off by now. \n";
			std::cout << "You suddenly hear metal clanking in the distance \n\n ";

			std::cout << "Do you: \n";
			e.AddChoice("Follow the clanking");
			e.AddChoice("Return to the building");
			e.AddChoice("Turn the other way");

			e.DisplayChoices();

			int choice2;
			std::cout << "Enter what you would do next (1-3): ";
			std::cin >> choice2;

			if (choice2 == 1) currentEvent = 5;
			else if (choice2 == 2) currentEvent = 1;
			else running = false;
			break;
		default:
			running = false;
			break;	

		case 3:
			
			std::cout << "\n You step inside the lobby. Dust hangs in the air. \n";
			std::cout << "A faint emergency light glows down the hall. \n";
			std::cout << "On the floor, you notice a small metal object. \n\n";

			std::cout << "Do you: \n";
			e.AddChoice("Pick up the object");
			e.AddChoice("Go farther into the hallway");
			e.AddChoice("Leave the building");

			e.DisplayChoices();

			int choice3;
			std::cout << "Enter what you would do next (1-3): ";
			std::cin >> choice3;

			if (choice3 == 1)
			{
				Inventory.push_back("Small Metal Key");
				std::cout << "\n You picked up: Small Matel Key\n";
				currentEvent = 6;
			}
			else if (choice3 == 2)
			{
				currentEvent = 6; //hallway
			}
			else
			{
				currentEvent = 0;
			}
			
			break;

		case 4:
			//stuck for what do/put for inspecting the door
			break;

		case 5:
			std::cout << "You walk down the street towards the clanking \n";
			std::cout << "You approach the the building that the metal sound is coming from and suddenly...\n";
			std::cout << "the sounds stops.\n";
			std::cout << "Your heart starts racing and the air starts to really feel thick. \n";

			std::cout << "Do you: \n";
			e.AddChoice("");
			e.AddChoice("");
			e.AddChoice("");

			e.DisplayChoices();

			int choice4;
			std::cout << "Enter what you would do next (1-3): ";
			std::cin >> choice4;
			break;
		case 6:
			break;
		}
	}
	std::cout << "You leave the area. The mystery remains unsolved. \n";
}


