// RPG-game.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Combat.h"
#include "Character.h"
#include "Player.h"
#include "Enemy.h"


int main()
{
	Character* player = new Player();
	Character* enemy = new Enemy();
	//player->setEnemy(enemy);
	//enemy->setEnemy(player);
	Combat game(player, enemy);

	game.doCombat();

	system("pause");
    return 0;
}

