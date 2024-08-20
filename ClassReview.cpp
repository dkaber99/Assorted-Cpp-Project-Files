#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

using std::cout;
using std::cin;
using std::endl;

class testperson{
    private:
    //int idnum = 0;
    //char[] name;
    
    public:
    int idnum = 10;
    void setidnum(int newnum){
        idnum = newnum;
    }
    int returnnum(){
        return idnum;
    }
    
};
class newperson : public testperson{
  
  
    
};


int main(){
testperson numbaone;    
std::cout << "This is my first and only test message";
numbaone.setidnum(5);
std::cout << "\n His number is: " + to_string(numbaone.returnnum()) << endl;

newperson numbatwo;    
std::cout << "This is my Second and only test message";
numbatwo.setidnum(5);
std::cout << "\n His number(mr 2) is: " + to_string(numbaone.returnnum());

return 0;
}

