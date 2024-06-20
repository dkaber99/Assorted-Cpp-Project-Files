#include <iostream>
#include <cstdlib>

using std::cout;
using std::cin;
//using RAND_MAX;

int main() {
	int rnum;
	rnum = rand() % 100 + 1;
	int issolved = 0;
	int enter = 0;
	while (issolved == 0) {
		cout << "Enter a number between 1-100 \n";
		cin >> enter;
		if (rnum == enter) {
			issolved = 1;
		}
		else if (rnum > enter) {
			cout << "The number you entered is too small \n";
		}
		else if (rnum < enter) {
			cout << "The number you entered is too large \n";
		}
	}
	cout << "You Entered The Correct Number Good Job\n";
	return 0;
}