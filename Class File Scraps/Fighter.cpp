#include "Fighter.h"

Fighter::Fighter() : Human() {
	health = 100;
}
Fighter::Fighter(string name, float init_cash, int init_health) : Human(name, init_cash) {
	health = init_health;
}

// method
void Fighter::fight() {
	health = health - 10;
	//receive_money(50);
	bank.deposit(50);
}
void Fighter::train() {
	health = health + 20;
	//spend_money(30);
	bank.withdraw(30);
}

int Fighter::show_health() {
	return health;
}

string Fighter::show_name() {
	return "Warrior " + name;
}