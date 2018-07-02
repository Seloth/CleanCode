#pragma once

#include "Character.h"
#include "Item.h"
//#include "ConsoleUI.h"


class Player : public Character
{
public:
	Player();

	virtual void makeTurn();

	void UseItem(Item* item, Character* target);

private:

};

