#include <iostream>
using namespace std;

int main(void) {

	int num = 12;
	int* ptr = &num;
	int** dptr = &ptr;

	int& ref = num;
	int* (&pref) = ptr; // 포인터변수 ptr의 reference pref
	int** (&dpref) = dptr; // 포인터변수 dptr의 reference dpref

	cout << ref << endl; // 12
	cout << *pref << endl; // 12 
	cout << **dpref << endl; // 12

	return 0;
}