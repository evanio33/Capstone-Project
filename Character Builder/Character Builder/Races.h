#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

#include "stats.h"

class baseRace {

public:
	int abilityScoreIncrease; 
	int speed;
	double height;
	int age;
	bool darkvision;
	std::vector <std::string> training;
	std::vector <std::string> languages;

	
public:
	baseRace();
	~baseRace();

private:
	virtual void set_abilityImprovement(stats*);


};

class dwarf : public baseRace 
{
//variable declarations
public:
	
	
private:
	int subRace;
	//stats dwarfStats;

//method declarations
public:
	dwarf(stats);
	~dwarf();
private:
	//sets sub race
	void set_subRace();
	//sets height of character. must be between 4 and 5 feet tall
	void set_size();	
	//sets training proficiencies of character. takes subrace variable as parameter
	void set_training(int);	
	//sets age. must be capped at 350 years
	void set_age();	
	//set ability score improvement
	void set_abilityImprovement(stats*);



};

class human : public baseRace 
{
//variable declarations
public:
private:

//method declarations
public:
	human(stats);
	~human();
private:
	void set_size();
	void set_age();
	void set_abilityImprovement(stats*);
};

class halfling : public baseRace 
{
//variable declarations
public:
	std::vector<std::string> traits;
	
private:
	int subRace;


//method declarations
public:
	halfling(stats);
	~halfling();
private:
	void set_size();
	void set_age();
	void set_subRace();
	void set_traits();
	void set_abilityImprovement(stats*);
};

class elf : public baseRace 
{
//variable declarations
public:
	std::vector<std::string> traits;
	
private:
	int subRace;

//method declarations
public:
	elf(stats);
	~elf();
private:
	void set_size();
	void set_age();
	void set_subRace();
	void set_traits();
	void set_abilityImprovement(stats*);

};