#include "stdafx.h"

#include "Spell.h"

Spell::Spell(std::string name, int damage, int manaCost, Effect effect)
	:name(name), damage(damage), manaCost(manaCost), effect(effect)
{
}

Spell::Spell(std::string name, int damage, int manaCost)
	: name(name), damage(damage), manaCost(manaCost)
{
	//effect = Effect("None", 0, 0, 0, 0, 0);
}

std::string Spell::getName()
{
	return name;
}

int Spell::getDamage()
{
	return damage;
}

int Spell::getManaCost()
{
	return manaCost;
}

Effect Spell::getEffect()
{
	return effect;
}

//unsigned int Spell::getTurns()
//{
//	return effectTurns;
//}