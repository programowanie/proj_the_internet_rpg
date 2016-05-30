#pragma once
#include <string>

using namespace std;

struct fight
{
	int chance;
	int power;
};


class n00b
{
private:
	string _name;
	int _hp, _baseHp;
	int _mana, _baseMana;
	int _exp, _lvl;
	fight _attack;
	fight _defence;

public:
	n00b();

	int hp() { return _hp; }
	int mana() { return _mana; }
	bool damage(int value);
	fight attack() { return _attack; }
	fight defence() { return _defence; }
	void heal();
	void lvl_up();

	string stats();
};