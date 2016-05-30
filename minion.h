#pragma once
#include <string>
#include "n00b.h"

using namespace std;

class minion
{
private:
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