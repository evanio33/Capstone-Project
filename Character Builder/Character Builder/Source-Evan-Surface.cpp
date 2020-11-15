#include <iostream>
#include <string>
#include <cassert>
#include "Dice_Roller.h"
#include "stats.h"
#include "character.h"


int main() {
	//diceRoller myDice();

	// myDice.rolld6();
	//myDice.rolld8();
	//myDice.rolld20();
	//myDice.rolld100();

	character *cha = new character();

	std::cout << "hello, " << cha->getName() << " you are a level " << cha->getLevel() << " " << cha->getClass()  << std::endl;
	std::cout << "Your strength is: " << cha->getAbility(0) << " your dex is: " << cha->getAbility(1) << std::endl;
	std::cout << "\nYour skill in Acrobatics is: " << cha->getSkill(1,0)<< std::endl;


	//diceRoller tester;
	//std::cout << tester.abilityRoller() << std::endl;
	
	// std::cout << 3 % 2;
	return 0;
}