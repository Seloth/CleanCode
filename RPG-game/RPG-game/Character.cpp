#include "stdafx.h"

#include "Character.h"
#include "ConsoleUI.h"

Character::Character()
	:health(100), mana(100), power(5)
{
}

Character::Character(std::string name, int health, int mana, unsigned int power)
	: name(name), health(health), mana(mana), power(power)
{
}

Character::Character(Character* enemy)
	: health(100), mana(100), power(5)
{
}

std::string Character::getName()
{
	return name;
}

int Character::getHealth()
{
	return health;
}

int Character::getMana()
{
	return mana;
}

unsigned int Character::getPower()
{
	return power;
}

std::list<Effect> Character::getActiveEffects()
{
	return activeEffects;
}

std::vector<Spell> Character::getSpellbook()
{
	return spellbook;
}

void Character::useAttack()
{
	useAttack(target);
}

void Character::useAttack(Character* target)
{
	int damage = rand() % power + 1;
	target->health -= damage;
	UI::attackLog(this->name, "Attack", damage);
}

bool Character::useSpell(Spell* spell, Character* target)
{
	bool result = false;
	if (this->mana < spell->getManaCost())
	{
		result = false;
	}
	else
	{
		this->mana -= spell->getManaCost();
		target->health -= spell->getDamage();
		target->applyEffect(spell->getEffect());
		result = true;
		UI::attackLog(this->name, spell->getName(), spell->getDamage());
	}
	return result;
}

void Character::applyEffect(const Effect& effect)
{
	/*for (std::list<Effect>::iterator it = activeEffects.begin(); it != activeEffects.end(); ++it)
	{
	if (*it == effect)
	{
	*it.setTurns(effect.getTurns());
	}

	}*/

	activeEffects.push_back(effect);
}

void Character::doAllEffects()
{
	//bool expired = [](Effect* effect) { return effect->getTurns()==0; };

	activeEffects.remove_if([](Effect effect) { return effect.getTurns() == 0; });
	for (std::list<Effect>::iterator it = activeEffects.begin(); it != activeEffects.end(); ++it)
	{
		//it->name;
		if (it->getTurns() > 0)
		{
			doEffect(*it);
		}
		else
		{
			std::list<Effect>::iterator delIt = it;
			it++;
			activeEffects.erase(delIt);
		}

	}
}

void Character::doEffect(Effect& effect)
{
	if (effect.getTurns() > 0)
	{
		if (effect.getHealthPerTurn() != 0)
		{
			changeHealth(effect.getHealthPerTurn());
		}
		if (effect.getManaPerTurn() != 0)
		{
			changeMana(effect.getManaPerTurn());
		}
		if (effect.getPowerForTurn() != 0)
		{
			//temppower=
		}
		if (effect.getStun())
		{
			//character.setstun
		}
		effect.setTurns(effect.getTurns() - 1);
	}
}

void Character::makeTurn()
{
	useAttack(target);
}

void Character::changeHealth(int delta)
{
	health += delta;
}

void Character::changeMana(int delta)
{
	mana += delta;
}

void Character::setEnemy(Character* newEnemy)
{
	target = newEnemy;
}

Character* Character::getTarget()
{
	return target;
}

void Character::setSpellbook(std::vector<Spell> spellbook)
{
	this->spellbook = spellbook;
}