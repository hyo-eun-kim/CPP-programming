#include <iostream>
using namespace std;

int IsPositive(int num) {
	if (num < 0) {
		return false;
	}
	else {
		return true;
	}
}

int main(void) {

	bool isPos; // bool�� (C������ ������)
	int num;
	cout << "input number: ";
	cin >> num;

	isPos = IsPositive(num);
	if (isPos) {
		cout << "Positive number" << endl;
	}
	else {
		cout << "Negative number" << endl;
	}
	
	return 0;
}