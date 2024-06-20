#include <iostream>
#include <string>
using std::cout;
using std::cin;
using std::endl;
using std::string;
	/* int main() {
	string name;
	float year, salary;
	cout << "Hello, please enter your name: ";
	cin >> name;
	cout << "name[0]: " << name[0] << endl;
	cout << "Hello " << name << endl;
	cout << "Enter number of year: ";
	cin >> year;
	cout << "Enter your salary: ";
	cin >> salary;
	float bonus = 0;
	if (name[0] == 'B' || (name[0] == 'b')) {
		bonus = bonus + 1500;
	}
	cout << "Bonus: " << bonus << endl;

	if (year > 10) {
		bonus = bonus + salary * 0.08;
	}
	else if (year > 5) {
		bonus = bonus + salary * .05;
	}
	*
	int main() {
		int height[5] = { 1,2,3,4,5 };
		for (int i = 0; i < 5; i++) {
			cout << height[i] << endl;

		}
		cout << "Thank you" << endl;
		*/

	/*int main(){
		int num;
		cout << "Enter a number: ";
		cin >> num;
		int fac = 1;

		for (int i = num; i > 0; i = i - 1) {
			fac = fac * i;

		}
		cout << "The final number is: " << fac; */
	int main(){
		string names[3];
		cout << "Please enter the first name: ";
		cin >> names[0];
		cout << "Please enter the second name: ";
		cin >> names[1];
		cout << "Please enter the third name: ";
		cin >> names[2];
		for (int i = 0; i < 3; i++) {
			cout << names[i];

		}

	return 0;
}