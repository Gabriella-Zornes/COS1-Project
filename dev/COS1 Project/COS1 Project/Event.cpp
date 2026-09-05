#include "Event.h"
#include <iostream>
Event::Event()
{

}

void Event::AddChoice(const std::string& choiceText, int nextEventid)
{
	choices.push_back(choiceText);
}

void Event::DisplayChoices() const
{
	for (int i = 1; i < choices.size(); i++)
	{
		std::cout << (i + 1) << ". " << choices[i] << "\n";
	}
}

int Event::GetChoiceCount() const
{
	return choices.size();
}
