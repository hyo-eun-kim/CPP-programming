#include <iostream>
using namespace std;

// �� C++���� malloc�� free�� ����ϴ� ���� �����ؾ� �ϴ� ���� ���� ����

class Simple {
public:
	Simple() {
		cout << "I'm simple constructor!" << endl;
	}
};

int main(void) {

	cout << "case 1: ";
	Simple* sp1 = new Simple; // new

	cout << "case 2: ";
	Simple* sp2 = (Simple*)malloc(sizeof(Simple) * 1); // malloc

	cout << endl << "end of main" << endl;
	delete sp1;
	free(sp2);

	return 0;
}