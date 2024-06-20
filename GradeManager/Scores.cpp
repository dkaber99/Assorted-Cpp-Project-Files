#include <iostream>
#include <string>

using std::cout;
using std::cin;

void printarr(int arr[],int size);
void modifyscore(int arr[]);
int showfinal(int arr[]);
float findavg(int arr[]);
//void printarr(int arr[],int size);
int showtotal(int arr[]);

int main() {
	int score[10] = { 8,10,8,5,7,8,9,10,6,7 };
	int choice = 0;
	while (choice != 5) {
		cout << "Please Enter A Choice: 1- Modify Your Scores 2-Show Your Final Grade 3-Show Your Average 4-Show Your Scores 5-Quit\n";
		cin >> choice;

		switch (choice) {

		case 1:
			modifyscore(score);
			break;
		case 2:
			cout << "Your Total Score Is: " << showtotal(score) << " \n";
			break;
		case 3:
			cout << "Your Average was: " << findavg(score) << "\n";
			break;
			
		case 4:
			printarr(score,10);
			break;
		
		case 5:
			cout << "Thank you for using Dylan's Grade Analyzing Software";
			choice = 5;
			break;
		
		case 6:
			cout << "The total was :" << showtotal(score) << "\n";
			break;
		default:
			cout << "You Entered An Invalid option!\n";
		}
		
	}
	return 0;
}


void modifyscore(int arr[]) {
	int numtest;
	int newscore;
	cout << "Which test do you want to change? Enter a number ";
	cin >> numtest;
	cout << "What do you want to change the score to? \n";
	cin >> newscore;
	numtest = numtest - 1;
	arr[numtest] = newscore;

}

int showtotal(int arr[]) {
	int total = 0;
	for (int x = 0; x < 10; x++) {

		total += arr[x];
	}
	return total;
}

int showfinal(int arr[]){
	int total = 0;
	for (int x = 0; x < 10; x++) {

		total += arr[x];
	}
if(total > 93){
cout << "You got an A\n";
}

else if(total >= 85){
cout << "You got a B\n";

}
else if(total >= 70){
cout << "You got a C\n";

}

else if(total >= 60){
cout << "You got a D\n";

}
else if(total < 60){
cout << "You got an F\n";

}
else{
cout << "You cheated \n"; //Impossible to trigger	
}

return total;
}

float findavg(int arr[]){
float avg = 0;
int total = 0;
for (int x =0;x<10;x++){

total += arr[x];

}
avg = (float)total/10; 

return avg;
}


void printarr(int arr[], int size) {

	for (int x = 0; x < size; x++) {

		cout << arr[x] << " ";

	}
	cout << "\n";
}
