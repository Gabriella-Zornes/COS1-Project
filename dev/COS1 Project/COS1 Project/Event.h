#pragma once

#include <string>
#include <vector>

class Event
{

public:
	Event(); 

	void AddChoice(const std::string& choiceText);
	void DisplayChoices() const;
	int GetChoiceCount() const; 

};

