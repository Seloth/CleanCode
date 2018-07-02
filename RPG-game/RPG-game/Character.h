#pragma once
#include "stdafx.h"

#include "Item.h"
#include "Spell.h"
#include "Effect.h"
//#include "ConsoleUI.h"

class Character
{
public:
	Character();
	Character(std::string name, int health, int mana, unsigned int power);
	Character(Character* enemy);

	virtual void makeTurn();
	void doEffect(Effect& effect);
	void doAllEffects();
	void applyEffect(const Effect& effect);

	void useAttack();
	void useAttack(Character* target);
	bool useSpell(Spell* spell, Character* target);
	bool useItem(Item* item, Character* target);

	void changeHealth(int delta);
	void changeMana(int delta);

	std::string getName();
	int getHealth();
	int getMana();
	unsigned int getPower();
	std::list<Effect> getActiveEffects();
	std::vector<Spell> getSpellbook();


	void setEnemy(Character* newEnemy);
	void setSpellbook(std::vector<Spell>);
	Character* getTarget();

private:
	std::string name;
	int health;
	int mana;
	unsigned int power;

	std::list<Effect> activeEffects;
	std::vector<Spell> spellbook;

	Item* inventory[5];

	Character* target;
};

