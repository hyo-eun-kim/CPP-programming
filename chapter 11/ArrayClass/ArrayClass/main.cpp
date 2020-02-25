#include <iostream>
#include <cstdlib>
using namespace std;

class BoundCheckIntArray {
private:
	int* arr;
	int arrlen;
public:
	BoundCheckIntArray(int len) :arrlen(len) {
		arr = new int[len];
	}

	int& operator[](int index) {
		if (index < 0 || index >= arrlen) {
			cout << "Array index out of bound exception" << endl;
		}
		else {
			return arr[index];
		}
	}
	
	~BoundCheckIntArray() {
		delete[] arr;
	}
};

int main(void) {

	BoundCheckIntArray arr(5);
	for (int i = 0; i < 5; i++) {
		arr[i] = i + 1;
	}

	for (int i = 0; i < 5; i++) {
		cout << arr[i] << endl;
	}
}