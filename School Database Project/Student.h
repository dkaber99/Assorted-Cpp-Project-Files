#pragma once
#include "User.h"
	class student : public user{
	//string[5] clsched;

	public:
	//Methods
		

void printsched() {
	cout << "This prints the student's schedule\n";

}
void addcourse(/*string[5] availclasses*/) {
cout << "This will add course based off what is given \n";

}
void dropcourse(/*string[5] availclasses*/) {
	cout << "This will drop a course based off what is given \n";

}
string searchcourse(/*string[5] availclasses*/) {
	cout << "This will return a course based off what is given \n";
	return "";
}

	};