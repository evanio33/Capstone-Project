#pragma once

#include <string>
#include <iostream>
#include <algorithm>
#include "Dice_Roller.h"
#include "stats.h"
#include "Races.h"

class character {
public:
	character();
	~character();
	//void setCharacter();
	void setLevelInit();
	void setName(std::string);
	void setProficiencyBonus(int);
	void set_race();
	void setClass();
	void setStats();
	//void setEquipment();

	int getLevel();
	int getProficiency();
	std::string getName(); 
	std::string getClass();
	int getAbility(int);
	int getSkill(int, int);

	stats* ch_stats;
	baseRace* race;
private:
	
	int level;
	int xp;
	int profBonus;
	std::string name;
	std::string charClass;
	//std::vector <std::string> equipment;

};