#pragma once
#include "User.h"


class Instructor : public user {

public:
	//Methods
	
string searchcourses() {
	cout << "This will print available courses\n";
	return "";
}
/*void printclasses() {
	cout << "This will print the classes";
}*/
void printsched() {
	cout << "This will print the schedule\n";
}

};
