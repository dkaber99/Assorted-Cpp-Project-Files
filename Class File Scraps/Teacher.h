#pragma once
#include "Human.h"
class Teacher :
	public Human
{
	int knowledge;

public:
	// constructor
	Teacher();
	Teacher(string in_name, float init_money, int init_knowledge);

	// method
	void learn();
	int show_knowledge();
	string show_name();

};

