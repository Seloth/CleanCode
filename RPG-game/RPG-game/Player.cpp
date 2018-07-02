#include "stdafx.h"

#include "Player.h"
#include "ConsoleUI.h"

Player::Player()
	:Character("Player", 100, 100, 10)
{
	Effect fire("Fire", -3, 0, 0, false, 3);
	Spell fireball("Fireball", 20, 20, fire);
	Spell heal("Heal", -20, 10);

	std::vector<Spell> spellbook;
	spellbook.push_back(fireball);
	spellbook.push_back(heal);

	setSpellbook(spellbook);
}

void Player::makeTurn()
{
	UI::playerTurn(this);
}