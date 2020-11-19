#pragma once

#include <string>
#include <iostream>
#include <algorithm>
#include "Dice_Roller.h"
#include "stats.h"
#include "Races.h"
#include "player_class.h"

class character {

//public method declarations
public:
	//constructor/destructor
	character();
	~character();



	//print methods
	void const print_abilityScores();
	void const print_abilityMods();
	void const print_skills();
	void const print_saves();
	void const print_name();
	void const print_level();
	void const print_proficiencyBonus();
	void const print_race();
	void const print_class();
	void const print_all();
private:
	//Setters
	void setLevelInit();
	void set_name();
	void setProficiencyBonus(int);
	void set_race();
	void set_stats();
	void set_class();
	//void setEquipment();

	//Getters
	int const getLevel();
	int const getProficiency();
	std::string const getName();
	std::string const getClass();
	int const getAbility(int);
	int const getSkill(int, int);

public:
//public variables
	stats* ch_stats;
	baseRace* ch_race;
	base_class* ch_class;
	std::string c_class;

private:
//private variables
	int level;
	int xp;
	int profBonus;
	std::string name;
	int c_race;
	int i_class;
	//std::vector <std::string> equipment;

};