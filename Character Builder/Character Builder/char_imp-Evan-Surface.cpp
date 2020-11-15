#include "character.h"



void character::setLevelInit() {
	std::cout << "What level is your character? ";
	bool validLevel = false;
	while (validLevel == false)
	{
		std::cin >> level;

		//in case user enters invalid level
		if (level < 1 || level > 20) {
			std::cout << "Invalid level value. Enter a value between 1 and 20" << std::endl;
			std::cin.clear();
			std::cin.ignore(1000000, '\n');
		}
		else
			validLevel = true;
		std::cout << level << std::endl;
	}
}

void character::setName(std::string n) {
	//std::cout << "Enter character's name: ";
	//std::getline(std::cin, name);

	name = n;
}

void character::setProficiencyBonus(int level) {
	switch (level) {
	case 1: case 2: case 3: case 4:
		profBonus = 2;
		break;
	case 5: case 6: case 7: case 8:
		profBonus = 3;
		break;
	case 9: case 10: case 11: case 12:
		profBonus = 4;
		break;
	case 13: case 14: case 15: case 16:
		profBonus = 5;
		break;
	case 17: case 18: case 19: case 20:
		profBonus = 6;
		break;
	default:
		std::cout << "invalid level" << std::endl;
		break;
	}
}

void character::setClass() {
	std::cout << "Enter your character class. choose from " 
		<< "Fighter, Rogue, or Wizard" << std::endl;
	std::cin >> charClass;
	transform(charClass.begin(), charClass.end(), charClass.begin(), ::tolower);
	std::cout << charClass << std::endl;
	if (charClass == "fighter")
	{
		std::cout << "what up my fighter bro" << std::endl;
	}
	else if (charClass == "rogue")
	{
		std::cout << "what up you sneaky rogue" << std::endl;
	} 
	else if (charClass == "wizard")
	{
		std::cout << "come on do some spells and shit mr Wizard" << std::endl;
	}
	else
	{
		std::cout << "invalid class selection, try again." << std::endl;
		setClass();
	}
}

void character::setStats() {
	ch_stats = new stats;
}

int character::getLevel(){
	return level;
}

int character::getProficiencyBonus() {
	return profBonus;
}

std::string character::getName(){ 
	return name;
}

std::string character::getClass() {
	return charClass;
}

int character::getAbility(int score) {
	return ch_stats->get_abilityScore(score);
}

int character::getSkill(int skill, int index)
{
	return ch_stats->get_skill(skill, index);
}



character::character() {
	setName();
	setLevelInit();
	setProficiencyBonus(level);
	setClass();
	setStats();
}

character::~character() {}