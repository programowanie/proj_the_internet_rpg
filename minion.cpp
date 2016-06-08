#include <stdlib.h>
#include "minion.h"

int random()
{
	return rand() % 100;
}

minion::minion()
{
	_name = _possNames[rand()%10];
	_hp = _baseHp = random();
	_mana = _baseMana = random();
	_attack = {20 + rand() % 30, 10 + rand() % 30};
	_defence = {20 + rand() % 30, 10 + rand() % 30};

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