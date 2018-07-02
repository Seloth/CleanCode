#pragma once
#include "stdafx.h"

class Item
{
public:
	Item();
	~Item();

	virtual int Target() = 0;
	virtual int Effect() = 0;

private:
	std::string name;
	int healthPerTurn;
	int manaPerTurn;
	unsigned int turns;
};

