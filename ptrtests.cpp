#include <iostream>

using std::cin;
using std::cout;
using std::endl;

int main(){
int num1;
int num2 = 20;
//Find amount of memory to store num1 (bytes)
cout << sizeof(num1);
//Find address of num1
int* ptr_num1 = &num1;
int* ptr_num2 = &num2;
num3 = &ptr_num1 + ptr_num2;
cout << "Address of num1 is " << &num1 << endl;
int arr[5] = {10,20,30,40,50};
//Check array size(in bytes) Should be 20bytes
sizeof(arr);
int arrsize = &arr[];
int arr_size = sizeof(arr1) / sizeof(int);
cout << "The number of elements in arr1 is " << arr1_size << endl;
cout << "Index 0 of arr1 is " << arr1 << endl;
//Print every element in an array
for (int i=0;i < arr1_size();i++){
cout << arr[i] << " ";
} //The ^^^^^^address
//Use pointer to print array
 
cout << arr << " ";

void add100 (int* arr1,int arr_size){
for(int i=0;i<arr.size();i++){
	*(arr+i) = *(arr+i) +100;
	}	
}
//after add 100
return 0;
}
int ptr_sum2(int* ptr_var1, int* ptr_var2){
	return *ptr_var1 + *ptr_var2;
}
int sum2(int var1,int var2){
	int ans;
	ans = var1 +var2;
	return ans;
}