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
	Temporary(100); // 1. ��ü���� (create obj: 100)
	// 2. destropy obj: 100
	cout << "after make!" << endl << endl; // 3. after make!

	Temporary(200).Show(); // ��ü���� -> Show()
	// ��ü�Ҹ�
	cout << "after make!" << endl << endl;

	const Temporary& ref = Temporary(300); // 1. ��ü����
	cout << "end of main" << endl << endl; // 2. ���
	// 3. ��ü�Ҹ�
	return 0;
}