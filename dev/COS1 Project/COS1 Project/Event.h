#pragma once

#include <string>
#include <vector>

class Event
{
	private:
		int id;
		std::string text;
		std::vector<std::string> choices;
		std::vector<int> nextEvents;

public:
	Event(int id,  const std::string& text); //text is const because the story text shouldnt be changed and passed by ref so it isnt copied

	void AddChoice(const std::string& choiceText, int nextEventid); 
	void Display() const;
	int GetNextEvent(int ChoiceIndex) const;

};

