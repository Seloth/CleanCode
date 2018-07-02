#include "stdafx.h"

#include "Combat.h"

Combat::Combat(Character* player, Character* enemy)
	:player(player), enemy(enemy)
{
	this->player->setEnemy(enemy);
	this->enemy->setEnemy(player);
}

void Combat::makeTurn(Character* currPlayer)
{
	currPlayer->doAllEffects();
	currPlayer->makeTurn();
}

void Combat::doCombat()
{
	bool combatFinished = false;
	while (!combatFinished)
	{
		UI::turnStart(turn);
		UI::characterInfo(player);
		UI::characterInfo(enemy);

		makeTurn(player);
		combatFinished = gotWinner();

		makeTurn(enemy);
		combatFinished = gotWinner();

		turn++;
	}

}

bool Combat::gotWinner()
{
	if (player->getHealth() <= 0)
	{
		UI::endBattle(false);
	}
	if (enemy->getHealth() <= 0)
	{
		UI::endBattle(true);
	}
	return player->getHealth() <= 0 || enemy->getHealth() <= 0;
}