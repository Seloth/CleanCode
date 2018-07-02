#pragma once
#include "stdafx.h"
//#include "Character.h"

class Effect
{
public:
	Effect();
	Effect(std::string name, int healthPerTurn, int manaPerTurn, int powerForTurn, bool stun, unsigned int turns);
	bool operator==(const Effect& other) const;

	//void doEffect(Character& target);
	std::string getName();
	int getHealthPerTurn();
	int getManaPerTurn();
	int getPowerForTurn();
	bool getStun();
	int getTurns();

	void setTurns(int newTurns);

private:
	std::string name;
	int healthPerTurn;
	int manaPerTurn;
	int powerForTurn;
	bool stun;
	unsigned int turns;
};

