#pragma once
#include "User.h"

class Admin : public user {
	
public:
	//Methods
	
	void  addtolist(){
		cout << "Add course to list\n";
	}
	void removecourse() {
		cout << "Remove Course\n";
	}
	void adduser() {
		cout << "Add user to course\n";
	}
	void removeuser() {
		cout << "Remove user to list\n";
	}
	void printroster() {
		cout << "Print list Of User\n";
	}
	void printcourses() {
		cout << "Show Courses Available\n";
	}
	void searchroster() {
		cout << "Search Roster\n";
		}

};