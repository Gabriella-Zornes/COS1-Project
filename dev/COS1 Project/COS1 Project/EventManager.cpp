#include "EventManager.h"
#include <iostream>
#include <fstream>




EventManager::EventManager()
{
	currentEvent = 0;
}

int EventManager::GetValidatedChoice(int maxChoice)
{
	std::string input;
	int choice = 0;

	while (true)
	{
		std::cout << "Enter what you would like to do next: ";
		std::getline(std::cin, input);

		try
		{
			choice = std::stoi(input);

			if (choice >= 1 && choice <= maxChoice)
			{
				return choice;
			}
			else
			{
				std::cout << "Invalid Option. Please try again. \n";
			}
		}
		catch (...)

		{
			std::cout << "Invalid input. Number only. \n";
		}
	
	}
}

void EventManager::Run()
{
	bool running = true;

	while (running)
	{
		Event e;


		switch (currentEvent)
		{
		case 0: //arrival squence 
		{
			std::cout << "\n =========================================== \n";
			std::cout << "    Welcome to the Abanondoned District \n";
			std::cout << " =========================================== \n\n";

			std::cout << " You are the last one left on the bus. The bus drops you off at the edge of the old industrial district. \n";
			std::cout << " A tall, overgrown building looming ahead, silent and forgotten. \n";
			std::cout << " The air feels heavier than it should... \n""\n";

			std::cout << "Do you: \n";

			e.AddChoice("Approach the building");
			e.AddChoice("Look around the street");
			e.AddChoice("Leave the area\n"); //should leave the area be an option? do i want to force the player farther? 

			

			e.DisplayChoices();

			int choice0 = GetValidatedChoice(e.GetChoiceCount());


			if (choice0 == 1)
				currentEvent = 1;
			else if (choice0 == 2) 
				currentEvent = 2;
			else running = false;
			break;
		}
		case 1: //approach the building
		{
			std::cout << "\n You approach the building...you notice that the front doors are steel and covered in chains and grime. \n";
			std::cout << " Though, you notice a door in which some of the chains are hanging loose. Looks like those doors have been forced opened... \n\n";

			std::cout << "Do you: \n";

			e.AddChoice("go through the open doors");
			e.AddChoice("inspect the front doors");
			e.AddChoice("take a step back");

			e.DisplayChoices();

			int choice1 = GetValidatedChoice(e.GetChoiceCount());


			if (choice1 == 1) currentEvent = 3;
			else if (choice1 == 2) currentEvent = 4;
			else if (choice1 == 3)
			{
				saveAndstay();
				currentEvent = 0;
			}
			else currentEvent = 1;

			break;
		}
		case 2: //choosing to look around the street
		{
			std::cout << "\n You look around at the street you're on...there's no one around. \n";
			std::cout << "The street is silent, street lights flickering even though the power seems like it should be off by now. \n";
			std::cout << "You suddenly hear metal clanking in the distance \n\n ";

			std::cout << "Do you: \n";

			e.AddChoice("Follow the clanking");
			e.AddChoice("Return to the building");
			e.AddChoice("Turn the other way");

			e.DisplayChoices();

			int choice2 = GetValidatedChoice(e.GetChoiceCount());


			if (choice2 == 1) currentEvent = 5;
			else if (choice2 == 2) currentEvent = 1;
			else running = false;
			break;
		}

		case 3: //going through already opened door
		{

			std::cout << "\n You step inside the lobby. Dust hangs in the air. \n";
			std::cout << "A faint emergency light glows down the hall. \n";
			std::cout << "On the floor, you notice a small metal object. \n\n";

			std::cout << "Do you: \n";
			e.AddChoice("Pick up the object");
			e.AddChoice("Go farther into the hallway");
			e.AddChoice("Leave the building");

			e.DisplayChoices();

			int choice3 = GetValidatedChoice(e.GetChoiceCount());


			if (choice3 == 1)
			{
				Inventory.push_back("Small Metal Key");
				std::cout << "\n You picked up: Small Matel Key\n";
				currentEvent = 3;
			}
			else if (choice3 == 2)
			{
				currentEvent = 6; //hallway
			}
			else
			{
				currentEvent = 1;
			}


		}
		break;


		case 4: //key unlock squence
		{
			std::cout << " The doors seem to be secured pretty tightly...almost as if it wasnt someone inside, but something outside keeping it in... \n";
			std::cout << "Even so, you tug on the chains, it won't budge. \n";
			std::cout << "It must be locked. \n";

			bool hasKey = false;
			for (const std::string& item : Inventory)
			{
				if (item == "Small Metal Key")
					hasKey = true;
			}

			if (hasKey)
			{
				std::cout << "You notice the lock matches the key you found.\n\n";
				e.AddChoice("Use the key");
			}

			e.AddChoice("Return to the entrance");

			e.DisplayChoices();

			int choice4 = GetValidatedChoice(e.GetChoiceCount());

			if (hasKey && choice4 == 1)
			{
				std::cout << "\nYou unlock the chain. The door creaks open.\n";
				currentEvent = 7;
			}
			else
			{
				currentEvent = 1;
			}

			
		}
		break;

		case 5: //clanking in the street
		{
			std::cout << "You walk down the street towards the clanking \n";
			std::cout << "You approach the the building that the metal sound is coming from and suddenly...\n";
			std::cout << "the sounds stops.\n";
			std::cout << "Your heart starts racing and the air starts to really feel thick. \n";

			std::cout << "Do you: \n";
			e.AddChoice("Continue exploring");
			e.AddChoice("Return to building");
			e.AddChoice("Save Game");


			e.DisplayChoices();

			int choice5 = GetValidatedChoice(e.GetChoiceCount());

			if (choice5 == 1) currentEvent = 1;
			else if (choice5 == 2) currentEvent = 8;
			else if (choice5 == 3)
			{
				saveAndstay();
				currentEvent = 3;
			}
			else running = false;

			
		}
		break;
		case 6: //continue down the hall
		{
			std::cout << "\nYou continue down the hallway. \n";
			std::cout << "The glowing exit sign flickers, creating shadows along the walls. \n";
			std::cout << "A broken vending machine hums quietly.  \n";
			std::cout << "On the floor, in a pile of dust, you notice a small battery. \n\n";

			std::cout << "Do you: \n";
			e.AddChoice("Pick up the battery");
			e.AddChoice("Continue into the hallway");
			e.AddChoice("Return to lobby");

			e.DisplayChoices();

			int choice6 = GetValidatedChoice(e.GetChoiceCount());


			if (choice6 == 1)
			{
				Inventory.push_back("Battery");
				std::cout << "\n You picked up: Battery\n";
				currentEvent = 6;
			}
			else if (choice6 == 2)
			{
				currentEvent = 9;
			}
			else
			{
				currentEvent = 3;
			}

			

		}
		break;

		case 7: //whats behind locked door
		{
			std::cout << "\nYou step through the now unlocked door.\n";
			std::cout << "The room beyond is small and cluttered with old research equipment.\n";
			std::cout << "A notebook covered in dust lies open on a desk.\n\n";


			e.AddChoice("Read the notebook");
			e.AddChoice("Search the room");
			e.AddChoice("Return to the entrance\n");

			e.AddChoice("Save Game");

			e.DisplayChoices();

			int choice7 = GetValidatedChoice(e.GetChoiceCount());



			if (choice7 == 1) //read the notebook
			{
				std::cout << "\nThe notebook mentions strange experiments conducted in the basement.\n";
				std::cout << "Most pages are torn out.\n";
				currentEvent = 7; // stay here
			}
			else if (choice7 == 2)
			{
				Inventory.push_back("Old Notebook");
				std::cout << "\nYou picked up: Old Notebook\n";
				currentEvent = 7;
			}
			else if (choice7 == 4)
			{
				saveAndstay();
				currentEvent = 0;
			}
			else
			{
				currentEvent = 1; // back outside
			}

			
		}
		break;
		case 8:
		{
			std::cout << "\nYou search the area where the sound came from.\n";
			std::cout << "Fresh foot prints trail off into a dark alley way.\n";

			e.AddChoice("Follow the footsteps");
			e.AddChoice("Return to the street");
			e.AddChoice("Leave the area");

			e.DisplayChoices();

			int choice8 = GetValidatedChoice(e.GetChoiceCount());

			if (choice8 == 1) currentEvent = 10;
			else if (choice8 == 2) currentEvent = 2;
			else running = false;
		}
		break;
		
		case 9:
		{
			std::cout << "\nYou reach the end of the hallway. \n";
			std::cout << "A heavy metal door blocks your path. \n";
			std::cout << "A faded sign reads: BASEMENT ACCESS. \n \n";

			bool hasBattery = false;
			for (const std::string& item : Inventory)
			{
				if (item == "Battery")
					hasBattery = true;
			}
			Event e;

			if (hasBattery)
			{
				e.AddChoice("Use the battery to power your flashlight");
			}
				e.AddChoice("Return to the hallway");
				e.AddChoice("Save Game");

				e.DisplayChoices();

				int choice9 = GetValidatedChoice(e.GetChoiceCount());

				if (hasBattery && choice9 == 1)
				{
					std::cout << "\nYou insert the battery. The flashlight flickers to life.\n";
					Inventory.push_back("Working Flashlight");
					currentEvent = 9;
				}
				else if ((hasBattery && choice9 == 2) || (!hasBattery && choice9 == 1))
				{
					std::cout << "\nYou push hard against the door.\n";
					std::cout << "The damaged lock snaps and the door swings open.\n";
					currentEvent = 10;
				}
				else if ((hasBattery && choice9 == 3) || (!hasBattery && choice9 == 2))
				{
					currentEvent = 6;
				}
				else
				{
					SaveGame("save.txt");
					currentEvent = 9;
				}
			
		}

			break;

		case 10:
		{
			std::cout << "\nYou desecend the stairs into the basement. \n";
			std::cout << "Cold air wraps around you like a shroud. \n";
			std::cout << "Footprints lead deeper into the darkness. \n \n";
			Event e;

			e.AddChoice("Follow the footprints");
			e.AddChoice("Search the basement");
			e.AddChoice("Retreat upstairs");
			

			e.DisplayChoices();

			int choice10 = GetValidatedChoice(e.GetChoiceCount());

			if (choice10 == 1)
			{
				currentEvent = 11;
			}
			else if (choice10 == 2)
			{
				std::cout << "\nYou find a torn ID badge.\n";
				Inventory.push_back("Torn ID Badge");
				currentEvent = 10;
			}
			else if (choice10 == 3)
			{
				currentEvent = 9;
			}
			else
			{
				SaveGame("save.txt");
				currentEvent = 10;
			}
		}
		


		break;
		case 11:
		{

		}
			break;

		case 12:
		{

		}
		break;

		default:
			std::cout << "You leave the area. The mystery remains unsolved. \n";
			break;
		

		}


	}
	

}

void EventManager::SaveGame(const std::string& filename)
{
	std::ofstream out(filename);

	if (!out.is_open())
	{
		std::cout << "Error saving game.\n";
		return;
	}

	out << currentEvent << "\n";

	// Write inventory size
	out << Inventory.size() << "\n";

	// Write each item
	for (const std::string& item : Inventory)
	{
		out << item << "\n";
	}

	out.close();

	std::cout << "Game saved successfully.\n";
}

bool EventManager::LoadGame(const std::string& filename)
{
	std::ifstream in(filename);

	if (!in.is_open())
	{
		std::cout << "Save file not found..";
		return false;
	}
	Inventory.clear();

	std::string line;

	if (!std::getline(in, line)) 
	{
		std::cout << "Save file corrupted.\n";
		return false;
	}

	try
	{
		currentEvent = std::stoi(line);
	}
	catch (...)
	{
		std::cout << "Save file corrupted.\n";
		return false;
	}

	// Read inventory count
	if (!std::getline(in, line))
	{
		std::cout << "Save file corrupted.\n";
		return false;
	}

	int count = 0;
	try
	{
		count = std::stoi(line);
	}
	catch (...)
	{
		std::cout << "Save file corrupted.\n";
		return false;
	}

	// Read each inventory item
	for (int i = 0; i < count; i++)
	{
		if (!std::getline(in, line))
		{
			std::cout << "Save file corrupted.\n";
			return false;
		}

		Inventory.push_back(line);
	}

	std::cout << "Game loaded successfully.\n";
	return true;
}




void EventManager::saveAndstay()
{
	SaveGame("Game.txt");
	std::cout << "\n Game successfully saved. \n";

}

