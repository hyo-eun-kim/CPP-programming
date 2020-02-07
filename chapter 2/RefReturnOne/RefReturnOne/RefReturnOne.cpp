#include <iostream>
using namespace std;

int& RefReturnFunc(int& num) {
	num++;
	return num;
}

int ValueReturnFUnc(int& num) {
	num++;
	return num;
}

int main(void) {

	int num1 = 1;
	int& num2 = RefReturnFunc(num1); // num1:2
	int num3 = RefReturnFunc(num1); // num1:3, num3:3
	int num4 = ValueReturnFUnc(num1); // num1:4, num4:4

	num1++; // num1: 5
	num2++; // num1: 6
	num3++; // num3: 4
	num4++; // num4: 5
	cout << "num1 : " << num1 << endl;
	cout << "num2 : " << num2 << endl;
	cout << "num3 : " << num3 << endl;
	cout << "num4 : " << num4 << endl;

	return 0;
}