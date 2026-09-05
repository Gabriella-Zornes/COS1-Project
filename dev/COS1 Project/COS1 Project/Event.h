#pragma once

#include <string>
#include <vector>

class Event
{
	private:
		
		std::vector<std::string> choices;


public:
	Event(); 

	void AddChoice(const std::string& choiceText);
	void DisplayChoices() const;
	int GetChoiceCount() const; 

};

