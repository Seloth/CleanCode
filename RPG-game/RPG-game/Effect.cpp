#include "stdafx.h"

#include "Effect.h"

Effect::Effect()
	:name("None"), healthPerTurn(0), manaPerTurn(0), powerForTurn(0), stun(0), turns(0)
{
}

Effect::Effect(std::string name, int healthPerTurn, int manaPerTurn, int powerForTurn, bool stun, unsigned int turns)
	: name(name), healthPerTurn(healthPerTurn), manaPerTurn(manaPerTurn), powerForTurn(powerForTurn), stun(stun), turns(turns)
{
}

bool Effect::operator==(const Effect& other) const
{
	return this->name == other.name;
}

//void Effect::doEffect(Character target)
//{
//
//}
std::string Effect::getName()
{
	return name;
}

int Effect::getHealthPerTurn()
{
	return healthPerTurn;
}

int Effect::getManaPerTurn()
{
	return manaPerTurn;
}

int Effect::getPowerForTurn()
{
	return powerForTurn;
}

bool Effect::getStun()
{
	return stun;
}

int Effect::getTurns()
{
	return turns;
}

void Effect::setTurns(int newTurns)
{
	turns = newTurns;
}