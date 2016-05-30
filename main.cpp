// ConsoleApplication1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "n00b.h"
#include "minion.h"
#include <iostream>
#include <time.h>
#include <Windows.h>

string _enter_dungeon = "Welcome in the dungeon! Sharpen your sword and prepare your shield. May the odds be in your favour!\n";

bool war(n00b&, minion&);

int main(int argc, char argv[])
{
	srand(time(NULL));
	n00b _n00b;
	cout << _n00b.stats();
	//cout << "\n\n\n\n\n";
	minion minions[5];
	//cout << _minion.description();

	cout << _enter_dungeon;
	for (int i = 0; i < 5; i++)
	{
		cout << "Wild " << minions[i].name() << "appears!\nFIGHT!\n";
		if (war(_n00b, minions[i]) == true)
		{
			cout << "YOU DIE!\n\n\n\n\n\n\n\n\n";
			break;
		}
		else
		{
			cout << "WIN!\n";
			cout << _n00b.stats() << endl;
			Sleep(10000);
			cout << "\n\n\n\n\n\n\n\n";
		}
	}

	system("PAUSE");
    return 0;
}

bool war(n00b& _hero, minion& _enemy)
{
	bool isHrDead = false;
	bool isEnDead = false;
	//while one of them is dead, not both you idiot!
	/*while (isHrDead == false && isEnDead == false)
	{
		cout << "We're fighting!\n";
		isEnDead = true;
	}*/
	cout << "Enemy hp: " << _enemy.hp() << endl;
	while (isHrDead == false && isEnDead == false)
	{
		int x = rand() % 100 + 1;
		cout << "Hero's dice throw on attack chance " << x << endl;
		if (_hero.attack().chance >= x)
		{
			x = rand() % 100 + 1;
			cout << "Enemy's dice throw on defence chance " << x << endl;
			if (_enemy.defence().chance >= x)
			{
				isEnDead = _enemy.damage(((_hero.attack().power - _enemy.defence().power) < 0) ? 0 : _hero.attack().power - _enemy.defence().power);
				cout << "Hero hits with parry for " << (((_hero.attack().power - _enemy.defence().power) < 0) ? 0 : _hero.attack().power - _enemy.defence().power) << endl;
			}
			else
			{
				isEnDead = _enemy.damage(_hero.attack().power);
				cout << "Hero hits with no parry for " << _hero.attack().power << endl;
			}
		}
		else
			cout << "Hero misses!\n";
		if (isEnDead == true)
			break;
		Sleep(5000);
		x = rand() % 100 + 1;
		cout << "Enemy's dice throw on attack chance " << x << endl;
		if (_enemy.attack().chance >= x)
		{
			x = rand() % 100 + 1;
			cout << "Hero's dice throw on defence chance " << x << endl;
			if (_hero.defence().chance >= x)
			{
				isHrDead = _hero.damage(((_enemy.attack().power - _hero.defence().power) < 0) ? 0 : _enemy.attack().power - _hero.defence().power);
				cout << "Enemy attacks with parry for " << (((_enemy.attack().power - _hero.defence().power) < 0) ? 0 : _enemy.attack().power - _hero.defence().power) << endl;
			}
			else
			{
				isHrDead = _hero.damage(_enemy.attack().power);
				cout << "Enemy hit with no parry for " << _enemy.attack().power << endl;
			}
		}
		else
			cout << "Enemy misses\n";

		Sleep(5000);
	}
	return isHrDead;
}