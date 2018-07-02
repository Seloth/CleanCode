#include "stdafx.h"

#include "ConsoleUI.h"

void UI::turnStart(int turn)
{
	cout << "====================ROUND " << turn << "====================" << endl;
}

void UI::characterInfo(Character* character)
{
	cout << character->getName() << ":" << endl;
	cout << "Health: " << character->getHealth() << endl;
	cout << "Mana: " << character->getMana() << endl;

	std::list<Effect> effects = character->getActiveEffects();

	cout << "Active Effects: ";
	for (std::list<Effect>::iterator it = effects.begin(); it != effects.end(); ++it)
	{
		cout << it->getName() << "(" << it->getTurns() << ") ";
	}
	cout << endl << endl;

}

int UI::playerTurn(Character* player)
{
	int choise = 0;
	bool turnOver = false;

	while (!turnOver)
	{
		options();
		cin >> choise;
		while (choise <= 0 || choise >= 3)
		{
			printf("Invalid choise!\n");
			printf("Input again: ");
			cin >> choise;
		}
		switch (choise)
		{
		case 1:
		{
			player->useAttack();
			turnOver = true;
			break;
		}
		case 2:
		{
			std::vector<Spell> spellbook = player->getSpellbook();
			int res = spellOptions(player);
			if (res >= 0)
			{
				if (player->useSpell(&spellbook[res], chooseTarget(player)))
				{
					turnOver = true;
				}
				else
				{
					printf("Not enough Mana!\n");
				}
			}
		}
		default:
			break;
		}

	}
	return 0;
}

void UI::options()
{
	printf("Choose your move:\n");
	printf("1. Attack\n");
	printf("2. Spellbook\n");
	printf("3. Items\n");

}

int UI::spellOptions(Character* player)
{
	int result = 0;
	std::vector<Spell> spellbook = player->getSpellbook();

	printf("Choose spell to cast:\n");
	for (int i = 0; i < spellbook.size(); ++i)
	{
		cout << i + 1 << " . " << spellbook.at(i).getName() << endl;
	}
	printf("\n0. Back\n");

	int choise = -1;
	cin >> choise;
	while (choise < 0 || choise >= spellbook.size())
	{
		printf("Invalid choise!\n");
		printf("Input again: ");
		cin >> choise;
	}
	switch (choise)
	{
	case 0: return -1;
	default:
	{
		return choise - 1;
		break;
	}
	}

}
void UI::itemOptions()
{
	printf("Choose item to use:\n");
	printf("1. Food\n");
	printf("2. Heal\n");
	printf("3. Stun\n");
}

Character* UI::chooseTarget(Character* player)
{
	printf("Choose target:\n");
	printf("1. Self\n");
	printf("2. Enemy\n");

	int target = 0;
	int choise = 0;
	cin >> choise;
	while (choise < 0 || choise > 3)
	{
		printf("Invalid choise!\n");
		printf("Input again: ");
		cin >> choise;
	}
	if (choise == 1) return player;
	else return player->getTarget();
}

void UI::attackLog(std::string name, std::string abilityName, int damage)
{
	cout << name << " used " << abilityName << " and dealt " << damage << endl;
}

void UI::endBattle(bool won)
{
	if (won)
	{
		printf("YOU WON!\n");
	}
	else
	{
		printf("YOU LOST!!!\n");
	}

	system("pause");
}