#include <iostream>
#include <string>
#include <fstream>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::ofstream;
using std::ifstream;

int main() {
	/* cout << "Enter your first name: ";
	string first;
	cin >> first;
	string last;
	cout << "Enter your last name ";
	cin >> last;
	cout << "Your first name is " << first << endl;
	cout << "Your last name is " << last << endl; */
	/*string name;
	cout << "Enter your name: ";
	getline(cin, name);
	cout << "Your name is " << name << endl;
	*/
	/*
	string name[3] = { "Dylan K","Tony Stark", "Harry Potter" };
	cout << name[0][0] << name[1][1] << name[2][2] << endl;
	name[0][0] = 'Z';
	cout << "Your Zname is " << name[0] << endl;*/

	//2D array
	/*/
	int data[4][3] = { { 15,10,8 }, {5,14,3 },{41,11,11}, {10,5,4} };
	cout << "data at row 0 col 0 is " << data[0][0] << endl;
	int max = data[0][0];
	for (int row = 0; row < 4; row++) {
		cout << data[row] << endl;
		for (int col = 0; col < 3; col++) {
			if (max < data[row][col]) {
				max = data[row][col];
			}
			cout << data[row][col] << " ";

		}
		cout << endl;
	}
	cout << "The max is " << max; */


	/*ofstream myfile("name.txt");
	myfile << "Pilin" << endl;
	myfile << "Ryan Glynn" << endl;
	myfile.close();*/
	string first;
	string out;
	ifstream myfile("name.txt");
	myfile >> first;
	getline(myfile, first);
	myfile.close();
	return 0;
}