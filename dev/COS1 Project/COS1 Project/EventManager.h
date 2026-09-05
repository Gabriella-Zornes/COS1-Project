#pragma once
#include "Event.h"
#include <vector>

class EventManager
{

private:
	
	int currentEvent;

public:
	EventManager();

	void LoadEvents();
	void Run();


};

