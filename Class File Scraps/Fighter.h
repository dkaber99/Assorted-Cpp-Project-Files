#pragma once
#include "Human.h"
class Fighter :
	public Human
{
	int health;

public:
	// constructor
	Fighter();
	Fighter(string name, float init_cash, int init_health);

	// method
	void fight();
	void train();
	int show_health();
	string show_name();

};

