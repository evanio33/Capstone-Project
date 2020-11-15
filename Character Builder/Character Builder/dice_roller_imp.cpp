#include "Dice_Roller.h"


diceRoller::diceRoller() 
{
	srand((unsigned)time(0));
}

//destructor
diceRoller::~diceRoller() {}

int diceRoller::roll(int type, int amount) 
{
	int randNum = 0, total = 0, i = 0;

	do {
		randNum = (rand() % type + 1);
		total += randNum;
		i++;
		//Sleep(1500);
		randNum = 0;
	} while (i < amount);
	return total;
}



//  Rolls 4d6 dice, removes the lowest, and adds them all together. 
int diceRoller::abilityRoller()
{
	std::vector <int> rolls;

	for(int i = 0; i < 4; i++)
	{
		rolls.push_back(roll(6, 1));
	
	}

	std::sort(rolls.begin(), rolls.end(), std::greater<int>());

	for (int value : rolls)
	{
		std::cout << "you rolled a " << value << std::endl;
	}

	rolls.pop_back();

	std::cout << "the total is: " << accumulate(rolls.begin(), rolls.end(), 0) << std::endl;
	
	return accumulate(rolls.begin(), rolls.end(), 0);
}
