#include <iostream>
#include <fstream>
#include <string>
using std::cin;
using std::cout;
using std::endl;
using std::ofstream;
using std::ifstream;
using std::string;

void printboard(char market[][10]);
void printlist(string list[]);
void wordsearch( char market[][10]);


int main() {
	char supermarket[10][10];
	string inglist[8] = { "GARLIC","SPINACH","TOMATO","BREAD","SUGAR","PASTA","ORANGE","MILK" };
	ifstream readfile("ingredient.txt");
	for (int row = 0; row < 10; row++) {
		for (int col = 0; col < 10; col++) {
		readfile >> supermarket[row][col];
		}
	}

	readfile.close();


	int input = 0;
	while (input != 4) {
		cout << "Please Enter an Option:\n1. Print The Board\n2. Check Ingredients List\n3.Search For An Ingredients\n4. Exit\n";
		cin >> input;
		switch (input) {
		case 1:
			printboard(supermarket); 
			break;

		case 2:
			printlist(inglist);
			break;

		case 3:
			wordsearch(supermarket);
			break;

		case 4:
			cout << "Goodbye and Thank You\n";
			input = 4;
			break;
		default:
			cout << "Invalid Option\n";
			break;
		}
		
	}
	return 0;
} 
void printboard(char market[][10]) {
	for (int y = 0; y < 10; y++) {
		for (int x = 0; x < 10; x++) {
			cout << market[y][x] << " "; //Check which is which

		}
		cout << endl;
	}
}
void printlist(string list[]) {
	for (int y = 0; y < 10; y++) {
			cout << list[y] << " ";
		
		cout << "\n";
	}
}
void wordsearch(char market[][10]) {
	//int row = 0;
	//int col = 0;
	int let = 0;
	int dir = 0;
	string lookingfor;
	int origposrow = 0;
	int origposcol = 0;
	cout << "Please Enter An Ingredient\n";
	cin >> lookingfor;
	cout << "You are looking for: " << lookingfor << endl;
	cout << "It is " << lookingfor.length() << " Letters Long "; //Add for loop to find word in array by name


	for (int row = 0; row < 10; row++) {
		for (int col = 0; col < 10; col++)
		{
			if (lookingfor[0] == market[row][col]) { //Going down the tree for if a letter is found

				origposcol = col;
				origposrow = row;

				for (int i = 1; i < lookingfor.length(); i++) {
					if (lookingfor[i] == market[row][col + i]) {
						let++;
					}
					else {
						let = 0;
						break;
					}
				} cout << let << endl;;
				if (let == lookingfor.length() - 1) {
					cout << "The word is found\n";
					cout << "Found At: [" << row << "," << col << "] ";
					cout << "right\n";
					break;
				}
				else {
					for (int i = 1; i < lookingfor.length(); i++) {
						if (lookingfor[i] == market[row][col - i]) {
							let++;
						}
						else {
							let = 0;
							break;
						}
					}

					if (let == lookingfor.length() - 1) {
						cout << "The word is found\n";
						cout << "Found At: [" << row << "," << col << "], ";
						cout << "left\n";
						break;
					}
					else {
						for (int i = 1; i < lookingfor.length(); i++) {
							if (lookingfor[i] == market[row + i][col]) {
								let++;
							}
							else {
								let = 0;
								break;
							}
						}
					}
					if (let == lookingfor.length() - 1) {
						cout << "The word is found\n";
						cout << "Found At: [" << row << "," << col << "] ";
						cout << "down\n";
						break;
					}
					else {
						for (int i = 1; i < lookingfor.length(); i++) {
							if (lookingfor[i] == market[row - i][col]) {
								let++;
							}
							else {
								let = 0;
								break;
							}
						}
						if (let == lookingfor.length() - 1) {
							cout << "The word is found\n";
							cout << "Found At: [" << row << "," << col << "] ";
							cout << "up\n";
							break;
						}
					}

				}
			}
		}
	}
}