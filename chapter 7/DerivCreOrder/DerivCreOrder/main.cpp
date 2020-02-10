#include <iostream>
using namespace std;

class Base {
private:
	int baseNum;
public:

	// void ������
	Base() :baseNum(20) {
		cout << "Base()" << endl;
	}

	Base(int num) :baseNum(num) {
		cout << "Base(int)" << endl;
	}

	void ShowBaseData() {
		cout << baseNum << endl;
	}

};

// Base Ŭ������ ��ӹ��� Derived Ŭ����
class Derived : public Base {
private:
	int deriveNum;
public:
	Derived() {
		// ����Ŭ������ �����ڸ� ������� ������ void �����ڰ� ȣ��ȴ�
		deriveNum = 30;
		cout << "Derived()" << endl;
	}
	Derived(int num) {
		// ����Ŭ������ �����ڸ� ������� ������ void �����ڰ� ȣ��ȴ�
		deriveNum = num;
		cout << "Derived(int)" << endl;
	}
	Derived(int num1, int num2)
		:Base(num1), deriveNum(num2){
		cout << "Derived(int, int)" << endl;
	}

	void ShowDerivedData() {
		ShowBaseData();
		cout << deriveNum << endl << endl;
	}
};

int main(void) {

	cout << "case1" << endl;
	Derived obj1;
	obj1.ShowDerivedData();
	cout << "--------------------" << endl;

	cout << "case2" << endl;
	Derived obj2(12);
	obj2.ShowDerivedData();
	cout << "--------------------" << endl;

	cout << "case3" << endl;
	Derived obj3(23, 24);
	obj3.ShowDerivedData();
	cout << "--------------------" << endl;

	return 0;
}