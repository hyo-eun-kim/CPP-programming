#include <iostream>
#include <cstdlib>
using namespace std;

class BoundCheckIntArray {
private:
	int* arr;
	int arrlen;
	BoundCheckIntArray(BoundCheckIntArray& array) {}; // ���������
	BoundCheckIntArray& operator=(const BoundCheckIntArray& array) {}; // ���Կ�����
public:

	BoundCheckIntArray(int len):arrlen(len) {
		arr = new int[arrlen];
	}

	int& operator[](int index) {
		if (index < 0 || index>=arrlen) {
			cout << "out of index" << endl;
		}
		else {
			cout << "operator[]" << endl;
			return arr[index];
		}
	}

	int operator[](int index) const{
		if (index < 0 || index >= arrlen) {
			cout << "out of index" << endl;
		}
		else {
			cout << "const operator[]" << endl;
			return arr[index];
		}
	}

	int getLen()const {
		return arrlen;
	}

};

void ShowAllData(const BoundCheckIntArray& array) {
	for (int i = 0; i < array.getLen(); i++) {
		// int operator[](int index) const ȣ�� (const ��ü�̹Ƿ�)
		cout << array[i] << endl;
	}
}

int main(void) {
	BoundCheckIntArray array(5);

	for (int i = 0; i < array.getLen(); i++) {
		array[i] = i + 1;
	}

	ShowAllData(array);
}