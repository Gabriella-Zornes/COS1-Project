#pragma once
#include "Event.h"
#include <vector>

class EventManager
{

private:
	std::vector<Event> events;
	int currentEvent;

public:
	EventManager();

	void LoadEvents();
	void Run();


};

