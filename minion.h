#pragma once
#include <string>
#include <vector>
#include "n00b.h"

class minion
{
private:
	string _possNames[10] = { "Troll ", "Grammar Nazi ", "Pedobear ", "PC Master Race ", "Rage Wolf ", "Moon Moon", "Chuck Norris ", "Bad Luck Brian", "Scumbag Steve ", "Good Guy Greg "};
	string _name;
	int _hp, _baseHp;
	int _mana, _baseMana;
	fight _attack, _defence;

public:
	minion();

	string name() { return _name; }
	int hp() { return _hp; }
	int mana() { return _mana; }
	fight attack() { return _attack; }
	fight defence() { return _defence; }
	bool damage(int value);
	string description();
};