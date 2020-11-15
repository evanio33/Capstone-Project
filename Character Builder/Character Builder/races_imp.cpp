#include "Races.h"

//*****************************************
//base race class

baseRace::baseRace()
	:speed(25), darkvision(0), age(30), height(5.0)
{
	languages.push_back("Common");
	abilityScoreIncrease = 0;

}

baseRace::~baseRace()
{
}

//****************************************
//dwarf race class

	dwarf::dwarf(stats dwarfStats)
	{
		speed = 25;
		darkvision = 1;
		set_size();
		languages.push_back(", dwarvish");
		set_age();
		set_subRace();
		set_training(subRace);
		set_abilityImprovement(&dwarfStats);

	}

	void dwarf::set_size()//sets height of character. must be between 4 and 5 feet tall
	{
		std::cout << "Enter character's height: ";
		std::cin >> height;
		if (height > 5 || height < 4)
		{
			std::cin.clear();
			std::cin.ignore(10000, '\n');
			set_size();
		}
	}

	void dwarf::set_subRace()
	{
		std::string dwarfSub;
		std::cout << "Choose Hill or Mountain dwarf: ";
		std::cin >> dwarfSub;
		std::cin.clear();
		std::cin.ignore(10000, '\n');
		transform(dwarfSub.begin(), dwarfSub.end(), dwarfSub.begin(), ::tolower);
		if (dwarfSub == "hill")
		{
			std::cout << "you chose hill dwarf" << std::endl;
			subRace = 0;
		}
		else if (dwarfSub == "mountain")
		{
			std::cout << "you chose mountain dwarf" << std::endl;
			subRace = 1;
		}
		else
		{
			std::cout << "Invallid selection, choose again." << std::endl;
			set_subRace();
		}
	}

	void dwarf::set_abilityImprovement(stats *stats)
	{
		stats->abilityScores[2] += 2;
		stats->abilityMod[2] += 1;
		if (subRace == 0)
		{
			stats->abilityScores[4] += 1;
			if (stats->abilityScores[4] % 2 == 0)
				stats->abilityMod[4] += 1;
		}
		else if (subRace == 1)
		{
			stats->abilityScores[0] += 2;
			stats->abilityMod[0] += 1;
		}
	}

	void dwarf::set_training(int)	//sets training proficiencies of character. takes subrace variable as parameter
	{
		training.push_back("battle axe");
		training.push_back(", hand axe");
		training.push_back(", light hammer");
		training.push_back(", warhammer");

		if (subRace == 1)
		{
			training.push_back(", light armor");
			training.push_back(", medium armor");
		}
	}

	//sets age. must be capped at 350 years
	void dwarf::set_age()
	{
		std::cout << "Enter an age lower than 350: ";
		std::cin.clear();
		std::cin.ignore(100000, '\n');
		std::cin >> age;
		if (age > 350 || age < 0 || !(std::cin >> age))
		{
			std::cout << "Invalid input. Try again." << std::endl;
			set_age();
		}
	}

	dwarf::~dwarf() {}


//****************************************
//human race class

	human::human(stats humanStats)
	{
		speed = 30;
		darkvision = 0;
		set_size();
		set_age();
		set_abilityImprovement(&humanStats);

	}

	//sets age. must be less than 90 and greater than 15.
	void human::set_age()
	{
		std::cout << "Enter age. Must be less than 90.\n";
		std::cin.clear();
		std::cin.ignore(100000, '\n');
		std::cin >> age;
		if (age > 90 || age < 15 || !(std::cin >> age))
		{
			std::cout << "Invalid input. Try again." << std::endl;
			set_age();
		}

	}

	void human::set_size()
	{
		std::cout << "Enter character's height. must between 4 and 7 feet tall." << std::endl;
		std::cin.clear();
		std::cin.ignore(100000, '\n');
		std::cin >> height;
		if (height < 4 || height > 7 || !(std::cin >> height))
		{
			std::cout << "invalid input. Try again." << std::endl;
			set_size();
		}

	}
	
	void human::set_abilityImprovement(stats* stats)
	{
		for (int values : stats->abilityScores)
		{
			stats->abilityScores[values] += 1;
			if (stats->abilityScores[values] % 2 == 0)
			{
				stats->abilityMod[values] += 1;
			}
		}
	}

	human::~human() {}

//***************************************
//halfling race class

	halfling::halfling(stats halflingStats)
	{
		languages.push_back(", halfling");
		speed = 25;
		set_size();
		set_subRace();
		set_traits();
		set_abilityImprovement(&halflingStats);
	}

	void halfling::set_age()
	{
		std::cout << "Enter age. must be less than 250.\n";
		std::cin.clear();
		std::cin.ignore(100000, '\n');
		std::cin >> age;
		if (age < 15 || age > 250 || !(std::cin >> age))
		{
			std::cout << "Invalid input. Try again." << std::endl;
			set_age();
		}
	}

	//sets height. must be between 3 and 4 feet. 
	void halfling::set_size()
	{
		std::cout << "Enter character's height. Must be between 3 and 4 feet tall." << std::endl;
		std::cin.clear();
		std::cin.ignore(10000000, '\n');
		std::cin >> height;
		if (height < 3 || height > 4 || !(std::cin >> height))
		{
			std::cout << "invalid input. Try again." << std::endl;
			set_size();
		}
	}

	void halfling::set_subRace()
	{
		std::string halfSub;
		std::cout << "Choose lightfoot or stout halfling" << std::endl;
		std::cin.clear();
		std::cin.ignore(1000000, '\n');
		std::cin >> halfSub;
		transform(halfSub.begin(), halfSub.end(), halfSub.begin(), ::tolower);

		//check for subrace
		if (halfSub == "lightfoot")
		{
			std::cout << "You chose lightfoot halfling" << std::endl;
			subRace = 0;
		}
		else if (halfSub == "stout")
		{
			std::cout << "You chose stout halfling" << std::endl;
			subRace = 1;
		}
		else
		{
			std::cout << "Invalid selection. Try again." << std::endl;
			set_subRace();
		}
	}

	void halfling::set_traits() {
		traits.push_back("Lucky: When you roll a 1 on a d20 for an attack roll, ability check, or saving throw, you can reroll the die and must use the new roll.");
		traits.push_back("Brave: You have advantage on saving throws against being frightened.");
		traits.push_back("Halfling Nimbleness: You can move through the space of any creature that is of a size larger than yours.");

		if (subRace == 0)
		{
			traits.push_back("Naturally Stealthy: You can attempt to hide even when you are obscured only by a creature that is at least one size larger than you.");
		}
		else if (subRace == 1)
		{
			traits.push_back("Stout Resilience: You have advantage on saving throws against poison, and you have resistance against poison damage.");
		}
	}

	void halfling::set_abilityImprovement(stats* stats)
	{
		stats->abilityScores[1] += 2;
		stats->abilityMod[1] += 1;

		//checks subRace and distributes attribute points accordingly
		if (subRace == 0)
		{
			stats->abilityScores[5] += 1;
			if (stats->abilityScores[5] % 2 == 0)
				stats->abilityMod[5] += 1;
		}
		else if (subRace == 1)
		{
			stats->abilityMod[2] += 1;
			if (stats->abilityScores[2] % 2 == 0)
				stats->abilityMod[2] += 1;
		}
	}

	halfling::~halfling() {}

//***************************************
//elf race class

	elf::elf(stats elfStats)
	{
		speed = 30;
		darkvision = 1;
		set_age();
		set_size();
		set_subRace();
		set_traits();
		set_abilityImprovement(&elfStats);
	}

	void elf::set_age()
	{
		std::cout << "Enter age. Must be less than 750." << std::endl;
		std::cin.clear();
		std::cin.ignore(100000, '\n');
		std::cin >> age;
		if (age < 15 || age > 750 || !(std::cin >> age))
		{
			std::cout << "Invalid input. Try again." << std::endl;
			set_age();
		}
	}

	void elf::set_size()
	{
		std::cout << "Enter character's height. Must be between 4 and 7 feet tall." std::endl;
		std::cin.clear();
		std::cin.ignore(1000000, '\n');
		std::cin >> height;
		if (height < 4 || height > 7 || !(std::cin >> height))
		{
			std::cout << "Invalid input. Try again." << std::endl;
			set_size();
		}
	}

	void elf::set_subRace()
	{
		std::string sub;
		std::cout << "Choose high or wood elf." << std::endl;
		std::cin.clear();
		std::cin.ignore(100000, '\n');
		std::cin >> sub;
		transform(sub.begin(), sub.end(), sub.begin(), ::tolower);
		if (sub == "high")
		{
			std::cout << "you chose High Elf." << std::endl;
			subRace = 0;
		}
		else if (sub == "wood")
		{
			std::cout << "You chose Wood Elf." << std::endl;
			subRace = 1;
		}
		else
		{
			std::cout << "Invalid Selection. Try again." << std::endl;
			set_subRace();
		}

	}

	void elf::set_traits()
	{
		traits.push_back("Fey Ancestry: You have advantage on saving throws against being charmed, and magic can't put you to sleep.\n");
		traits.push_back("Trance: Elves don't need to sleep. Instead, they meditate deeply, remaining semiconscious for 4 hours a day. Long rests only take 4 hours.\n");
		training.push_back("Longsword");
		training.push_back(", shortsword");
		training.push_back(", shortbow");
		training.push_back(", longbow");
		if (subRace == 1)
		{
			speed = 35;
			traits.push_back("Mask of the Wild: You can attempt to hide even when you are only lightly obscured by foliage, heavy rain, falling snow, mist, and other natural phenomena");
			
		}
	}

	void elf::set_abilityImprovement(stats* stats)
	{
		stats->abilityScores[1] += 2;
		stats->abilityMod[1] += 1;
		if (subRace == 0)
		{
			stats->abilityScores[3] += 1;
			if (stats->abilityScores[3] % 2 == 0)
				stats->abilityMod[3] += 1;
		}
		else if (subRace == 1)
		{
			stats->abilityScores[4] += 1;
			if (stats->abilityScores[4] % 2 == 0)
				stats->abilityMod[4] += 1;
		}
	}

	elf::~elf() {}

