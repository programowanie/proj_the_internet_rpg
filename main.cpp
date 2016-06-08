// ConsoleApplication1.cpp : Defines the entry point for the console application.
//

//create skills in fight and make showing plot more universal

#include "stdafx.h"
#include "n00b.h"
#include "minion.h"
#include <iostream>
#include <time.h>
#include <Windows.h>
#include <stdlib.h>
#include <fstream>

string _enter_dungeon = "Welcome in the dungeon! Sharpen your sword and prepare your shield. May the odds be in your favour!\n";

bool war(n00b&, minion&);

int main(int argc, char argv[])
{
	srand(time(NULL));
	n00b _n00b;
	cout << _n00b.stats();
	minion minions[5];
	string line;
	vector <string> plot;
	ifstream myfile("Plot.txt");
	if (myfile.is_open())
	{
		while (getline(myfile, line))
		{
			plot.push_back(line);
		}
		myfile.close();
	}
	else cout << "Unable to open file";
	for (int i = 0; i<5; i++)
		cout << plot[i] << endl;
	int x;
	cin >> x;
	switch (x)
	{
	case 1:
		for (int i = 10; i<16; i++)
			cout << plot[i] << endl;
		break;
	case 2:
		cout << plot[6] << endl << plot[7] << endl;
		system("pause");
		return 0;
	default:
		cout << "Obey my commands IDIOT!!!\n";
		system("pause");
		return 0;
	}
	cin >> x;
	switch (x)
	{
	case 1:
		for (int i = 18; i<23; i++)
			cout << plot[i];
	case 2:
		for (int i = 24; i<26; i++)
			cout << plot[i];
		break;
	default:
		cout << "Obey my commands IDIOT!!!\n";
		system("pause");
		return 0;
	}

	int _noOfWins=0;
	cout << _enter_dungeon;
	Sleep(2000);
	int _ammountOfMonsters = 3 + rand() % 7;
	for (int i = 0; i < _ammountOfMonsters; i++)
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
			_noOfWins++;
			Sleep(2000);
			cout << "\n\n\n\n\n\n\n\n";
		}
	}
	if (_noOfWins == _ammountOfMonsters)
	{
		cout << "Congratulations on winning your first dungeon!\n";
		for (int i = 28; i < 32; i++)
			cout << plot[i] << endl;
	}
	system("PAUSE");
    return 0;
}

bool war(n00b& _hero, minion& _enemy)
{
	bool isHrDead = false;
	bool isEnDead = false;
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
		Sleep(1000);
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
				cout << "Enemy hits with no parry for " << _enemy.attack().power << endl;
			}
		}
		else
			cout << "Enemy misses\n";

		Sleep(1000);
	}
	return isHrDead;
}