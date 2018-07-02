#pragma once
#include "stdafx.h"
#include "Character.h"
#include "Effect.h"
#include "Spell.h"

using namespace std;

class UI
{
public:

	static void turnStart(int turn);
	static void attackLog(std::string name, std::string abilityName, int damage);
	static void characterInfo(Character* character);
	static int playerTurn(Character* player);
	static void endBattle(bool won);

	static void options();
	static int spellOptions(Character* player);
	void itemOptions();
	static Character* chooseTarget(Character* player);

private:

};

