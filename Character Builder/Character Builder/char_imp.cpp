#include "character.h"



//A method that determine's the character's level. 
	//  The user inputs an integer between 1 and 20.
	//  If the user attempts to input a number outside the range, 
	//  an error message is displayed and the method is called again. 
void character::setLevelInit() {
	std::cout << "What level is your character? ";
	std::cin >> level;

	//in case user enters invalid level
	if (level < 1 || level > 20) {
		std::cout << "Invalid level value. Enter a value between 1 and 20" << std::endl;
		std::cin.clear();
		std::cin.ignore(10000, '\n');
		setLevelInit();
	}
}

void character::set_name() {
	std::cout << "Enter character's name: ";
	std::getline(std::cin, name);
	//name = n;
}

//Method to set proficiency bonus. This bonus is determined by level
	//  Proficiency bonus is added to rolls in which the character does something that they are proficient in. 
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



void character::set_stats() {
	ch_stats = new stats;
}

void character::set_race()
{
	
	std::cout << "Choose your player race. Choose from "
		<< "Dwarf, Human, Halfling, and Elf" << std::endl
		<< "----------" << std::endl
		<< "1:  Dwarf"
		<< "\n2:  Human "
		<< "\n3:  Halfling"
		<< "\n4:  Elf\n";

	std::cin.clear();
	std::cin.ignore(10000, '\n');
	std::cin >> c_race;

	switch (c_race) 
	{
	case 1:
		std::cout << "You chose a dwarf" << std::endl;
		ch_race = new dwarf(*ch_stats);
		break;
	case 2:
		std::cout << "You chose a Human" << std::endl;
		ch_race = new human(*ch_stats);
		break;
	case 3:
		std::cout << "You chose Halfling" << std::endl;
		ch_race = new halfling(*ch_stats);
		break;
	case 4:
		std::cout << "you chose an Elf" << std::endl;
		ch_race = new elf(*ch_stats);
		break;
	default:
		std::cout << "invalid entry. Try again." << std::endl;
		set_race();
		break;
	}
}

void character::set_class()
{
	int i_class;
	std::cout << "Enter your character class. choose from \n"
		<< "1:  Fighter\n2:  Rogue\n3:  Wizard" << std::endl;
	std::cin.clear();
	std::cin.ignore(100000, '\n');
	std::cin >> i_class;

	switch (i_class)
	{
	case 1:
		std::cout << "you chose Fighter\n";
		c_class = "fighter";
		ch_class = new fighter;
		break;
	case 2:
		std::cout << "You chose Rogue\n";
		c_class = "rogue";
		ch_class = new rogue;
		break;
	case 3:
		std::cout << "You chose Wizard\n";
		c_class = "wizard";
		ch_class = new wizard;
		break;
	default:
		std::cout << "incorrect input. Try again.\n";
		set_class();
		break;
	}
}

//*****************************************************************************************************************************
//GETTER METHODS

int const character::getLevel(){
	return level;
}

int const character::getProficiency() {
	return profBonus;
}

std::string const character::getName(){ 
	return name;
}

std::string const character::getClass() {
	return c_class;
}

int const character::getAbility(int score) {
	return ch_stats->get_abilityScore(score);
}

int const character::getSkill(int ability, int skill)
{
	return ch_stats->get_skill(ability, skill);
}

//*****************************************************************************************************************************
//Print methods

//prints all ability scores
void const character::print_abilityScores() 
{
	std::cout << "\n\nABILITY SCORES" << std::endl;
	for (int i = 0; i < ch_stats->abilityScores.size(); i++)
		std::cout << ch_stats->c_abilities[i] << ": " << ch_stats->get_abilityScore(i) << std::endl;
}

//prints all ability modifiers
void const character::print_abilityMods() 
{
	std::cout << "\n\nABILITY MODIFIERS" << std::endl;
	for (int i = 0; i < ch_stats->abilityScores.size(); i++)
		std::cout << ch_stats->c_abilities[i] << " Modifier: " << ch_stats->get_Mod(i) << std::endl;
}

//Method that prints all skills
void const character::print_skills() 
{
	std::cout << "\n\nSKILLS" << std::endl;
	int skillsCounter = 0;
	for (int i = 0; i < ch_stats->abilityMod.size(); i++)
	{
		std::cout << ch_stats->c_abilities[i] << std::endl;
		if (i != 2)
		{
			for (int j = 0; j < ch_stats->skills[i].size(); j++)
			{
				std::cout << ch_stats->s_skills[skillsCounter] << ": " << ch_stats->skills[i][j] << std::endl;
				skillsCounter++;
			}
			std::cout << std::endl;
		}
		else {
			std::cout << "no skills\n\n";
			skillsCounter++;
		}
	}
}

//Method that prints all saving throws
void const character::print_saves()
{
	std::cout << "\n\nSAVING THROWS" << std::endl;
	for (int i = 0; i < ch_stats->abilityScores.size(); i++)
	{
		std::cout << ch_stats->c_abilities[i] << ": " << ch_stats->savingThrows[i] << std::endl;
	}
}

//Method that prints character's name
void const character::print_name() 
{
	std::cout << "\nCharacter name: " << name << std::endl;
}

void const character::print_level() 
{
	std::cout << "\nCharacter's Level: " << level << std::endl;
}

void const character::print_proficiencyBonus() 
{
	std::cout << "\nProficiency Bonus: " << profBonus << std::endl;
}

void const character::print_race() 
{
	std::cout << "\ncharacter race: " << c_race << std::endl;
}


void const character::print_class() 
{
	std::cout << "\nCharacter class: " << c_class << std::endl;
}

void const character::print_all() 
{
	print_name();
	print_level();
	print_race();
	print_class();
	print_abilityScores();
	print_abilityMods();
	print_proficiencyBonus();
	print_skills();
}



//*****************************************************************************************************************************
//constructor and destructor
character::character() 
{
	set_name();
	setLevelInit();
	setProficiencyBonus(level);
	set_stats();
	set_race();
	set_class();
}

character::~character() {}