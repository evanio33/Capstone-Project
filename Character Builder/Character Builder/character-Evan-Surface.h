#pragma once

#include <string>
#include <iostream>
#include <algorithm>
#include "Dice_Roller.h"
#include "stats.h"

class character {
public:
	character();
	~character();
	//void setCharacter();
	void setLevelInit();
	void setName(std::string);
	void setProficiencyBonus(int);
	void setClass();
	void setStats();
	//void setEquipment();

	int getLevel();
	int getProficiencyBonus();
	std::string getName(); 
	std::string getClass();
	int getAbility(int);
	int getSkill(int, int);
	//int getAbility(int);

	stats* ch_stats;
private:
	
	int level;
	int xp;
	int profBonus;
	std::string name;
	std::string charClass;
	std::string equipment[];

};