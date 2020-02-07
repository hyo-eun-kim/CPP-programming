#include <iostream>
using namespace std;

// 왜 C++에서 malloc과 free를 사용하는 것을 지양해야 하는 지에 대한 예제

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