#pragma once
#include <iostream>
using std::string;
using std::cin;
using std::cout;



class user {
	string firstname;
	string lastname;
	string Idnum; //Make a string
	string Email;
public:
	//constructor
	user() {
		firstname = "Default";
		lastname = "DefaultLast. ";
		Idnum = "0000000 ";
	}
	user(string first, string last, int Idnew) {
		firstname = first;
		lastname = last;
		Idnum = Idnew;
	}

	//methods

	void setfirstname(string newfirst) {
		cout << "Setting name function\n";
		firstname = newfirst;

	}
	void setlastname(string newlast) {
		cout << "Setting last name function called\n";
		lastname = newlast;
	}
	void setId(string NewId) {
		Idnum = NewId;
	}
	void printinfo() {
		cout << "Here all info will be printed\n";
		cout << "User's Name Is: " << firstname << " " << lastname << "\n";
		cout << "User id is: W00" << Idnum << "\n";
	}
	string getID() {
		return Idnum;
	}
	string getname() {
		return firstname;
	}
	string getsurname() {
		return lastname;
	}
	string returnemail() {
		Email = lastname + firstname[0];
		return (Email);
	}
};


