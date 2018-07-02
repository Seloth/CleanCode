#pragma once
#include "stdafx.h"
//#include "Character.h"
#include "Effect.h"

class Spell
{
public:
	Spell(std::string name, int damage, int manaCost, Effect effect);
	Spell(std::string name, int damage, int manaCost);

	//int DoSpell(Character target);
	//int Effect();

	std::string getName();
	int getDamage();
	int getManaCost();
	Effect getEffect();
	//unsigned int getTurns();

private:
	std::string name;
	int damage;
	int manaCost;
	Effect effect;
	//unsigned int effectTurns;
};
