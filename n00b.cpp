#include "n00b.h"
#include <stdlib.h>

n00b::n00b()
{
	_baseHp = _hp = 100;
	_baseMana = _mana = 100;
	_attack = { 30 + rand() % 30, 30 + rand() % 30 };
	_defence = {30 + rand() % 30, 30 + rand() % 30 };
	_exp = 0;
	_lvl = 1;
	_name = "n00b";
}

bool n00b::damage(int value)
{
	_hp -= value;
	return _hp <= 0;
}

void n00b::heal()
{
	_hp = _baseHp;
}

string n00b::stats()
{
	return _name + "\n==========\nLevel: " + to_string(_lvl) + "\nExp: " + to_string(_exp) + "\nHealth: " + to_string(_hp) + "\nMana: " + to_string(_mana) +
		"\nAttack chance: " + to_string(_attack.chance) + "\nAttack power: " + to_string(_attack.power) + "\nDefence chance: " + to_string(_defence.chance) + "\nDefence power: " + to_string(_defence.power) + "\n";
}