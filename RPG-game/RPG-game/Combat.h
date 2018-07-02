#pragma once

#include "Character.h"
#include "ConsoleUI.h"

class Combat
{
public:
	Combat(Character* player, Character* enemy);

	void makeTurn(Character* current);
	void doCombat();
	bool gotWinner();


private:
	Character* player;
	Character* enemy;
	int turn = 1;
};

