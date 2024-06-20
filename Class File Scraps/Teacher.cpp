#include "Teacher.h"

Teacher::Teacher() : Human() {
	knowledge = 50;
}


Teacher::Teacher(string in_name, float init_money, int init_knowledge) : Human(in_name, init_money) {
	knowledge = init_knowledge;
}

void Teacher::learn() {
	knowledge = knowledge + 10;
	bank.withdraw(50);
}

int Teacher::show_knowledge() {
	return knowledge;
}

string Teacher::show_name() {
	return "Prof. " + name;
}