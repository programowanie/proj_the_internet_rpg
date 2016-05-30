#include <stdlib.h>
#include "minion.h"

int random()
{
	return rand() % 100;
}

minion::minion()
{
	_name = "troll ";
	_hp = _baseHp = random();
	_mana = _baseMana = random();
	_attack = {10 + rand() % 30, 10 + rand() % 30};
	_defence = {10 + rand() % 30, 10 + rand() % 30};

}

string minion::description()
{
	return _name + "\n==========\nHealth: " + to_string(_hp) + "\nMana: " + to_string(_mana) +
		"\nAttack chance: " + to_string(_attack.chance) + "\nAttack power: " + to_string(_attack.power) + "\nDefence chance: " + to_string(_defence.chance) + "\nDefence power: " + to_string(_defence.power) + "\n";
}

bool minion::damage(int value)
{
	_hp -= value;
	return _hp <= 0;
}