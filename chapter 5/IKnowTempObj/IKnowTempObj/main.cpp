#include <iostream>
using namespace std;

class Temporary {
private:
	int num;
public:
	Temporary(int num) :num(num) {
		cout << "create obj: " << num << endl;
	}

	void Show() {
		cout << "My num is " << num << endl;
	}

	~Temporary() {
		cout << "destropy obj: " << num << endl;
	}
};

int main(void) {
	Temporary(100); // 1. 按眉积己 (create obj: 100)
	// 2. destropy obj: 100
	cout << "after make!" << endl << endl; // 3. after make!

	Temporary(200).Show(); // 按眉积己 -> Show()
	// 按眉家戈
	cout << "after make!" << endl << endl;

	const Temporary& ref = Temporary(300); // 1. 按眉积己
	cout << "end of main" << endl << endl; // 2. 免仿
	// 3. 按眉家戈
	return 0;
}