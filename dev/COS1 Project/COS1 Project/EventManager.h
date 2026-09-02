#pragma once
#include "Event.h"

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

