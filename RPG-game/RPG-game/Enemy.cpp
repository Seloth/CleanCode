#include "stdafx.h"

#include "Enemy.h"

Enemy::Enemy()
	:Character("Enemy", 100, 100, 15)
{
	Effect fire("Fire", -3, 0, 0, false, 3);
	Spell fireball("Fireball", 20, 20, fire);
	Spell heal("Heal", -20, 10);
	Spell lifeTap("Life Tap", 5, -20);

	std::vector<Spell> spellbook;
	spellbook.push_back(fireball);
	spellbook.push_back(heal);
	spellbook.push_back(lifeTap);

	setSpellbook(spellbook);
}

void Enemy::makeTurn()
{
	if (rand() % 10 < 5)
	{
		useAttack();
	}
	else
	{
		if (getMana() < 50 && getHealth() > 50)
		{
			useSpell(&getSpellbook()[2], getTarget());
		}
		else if (getMana() > 50 && getHealth() > 50)
		{
			useSpell(&getSpellbook()[0], getTarget());
		}
		else if (getMana() > 50 && getHealth() < 50)
		{
			useSpell(&getSpellbook()[1], this);
		}
		else
		{
			useAttack();
		}
	}
}