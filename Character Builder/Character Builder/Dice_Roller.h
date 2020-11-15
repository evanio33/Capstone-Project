#pragma once

#include <vector>
#include <time.h>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <functional>
#include <numeric>

#ifdef _WIN32
#include <Windows.h>
#else
#include <unistd.h>
#endif

class diceRoller {
public:
	diceRoller();
	~diceRoller();
	int roll(int, int);
	int abilityRoller();
private:
	
};