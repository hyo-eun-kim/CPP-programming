#include <iostream>
using namespace std;

void IncreaseOne(int& num) {
	num++;
}

void InverseSign(int& num) {
	num *= (-1);
}

int main(void) {

	int val = 3;
	cout << "val > " << val << endl;

	IncreaseOne(val);
	cout << "val > " << val << endl;

	InverseSign(val);
	cout << "val > " << val << endl;

	return 0;
}