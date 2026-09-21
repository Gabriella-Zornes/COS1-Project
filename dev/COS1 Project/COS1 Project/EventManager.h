#pragma once
#include "Event.h"
#include <vector>


class EventManager
{

private:
	
	int currentEvent;
	std::vector<std::string> Inventory;

public:
	EventManager();
	void Run();
	int GetValidatedChoice(int maxChoice);
	void SaveGame(const std::string& fileName);
	bool LoadGame(const std::string& fileName)

};

