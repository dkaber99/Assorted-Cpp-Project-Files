#include <iostream>
#include <string>

using std::cout;
using std::cin;
using std::string;

	int main()
{
	string name;
        string people[9]= {"David","Jose","Mike","Alishia","Kate","Dan","Ellen","Nate", "Dylan"};

        int namefound = 0; //An int that is for checking if the name has been found

	while(namefound == 0){
	std::cout << "Enter your name. First letter uppercase please ";
        std::cin >> name;
	for(int x=0;x < 9;x++){
	if(name == people[x]){
	std::cout << "Your name is in the system welcome! \n";
	namefound = 1;//When name is found namefound is increased to 1 to end the loop
			}
		}
		if(namefound == 0){ //int check added here to prevent accidently tripping it after the name is found
	 std::cout << "Your name is not in the system please try another \n";
	}
}
people[1] = "John"; //Changes second name in the array to John
for(int p = 0; p<9;p++){
cout << people[p] << " ";//Prints array
}

return 0;
}
