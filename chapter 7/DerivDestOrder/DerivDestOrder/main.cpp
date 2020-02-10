#include <iostream>
using namespace std;

class Base {
private:
	int baseNum;
public:

	// void ������
	Base() :baseNum(20) {
		cout << "Base() : " << baseNum << endl;
	}

	Base(int num) :baseNum(num) {
		cout << "Base(int) : " << baseNum << endl;
	}

	void ShowBaseData() {
		cout << baseNum << endl;
	}

	~Base() {
		cout << "~Base() : " << baseNum << endl;
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
		cout << "Derived() : " << deriveNum << endl;
	}
	Derived(int num) {
		// ����Ŭ������ �����ڸ� ������� ������ void �����ڰ� ȣ��ȴ�
		deriveNum = num;
		cout << "Derived(int) : " << deriveNum << endl;
	}
	Derived(int num1, int num2)
		:Base(num1), deriveNum(num2) {
		cout << "Derived(int, int) : " << deriveNum << endl;
	}

	void ShowDerivedData() {
		ShowBaseData();
		cout << deriveNum << endl << endl;
	}

	~Derived() {
		cout << "~Derived : " << deriveNum << endl;
	}
};

int main(void) {


	Derived obj1(15, 15);
	Derived obj2(27, 27);

	/*
	Base(int) : 15			// ����Ŭ���� ������ ����
	Derived(int, int) : 15	// ����Ŭ���� ������ ����
	Base(int) : 27			// ����Ŭ���� ������ ����
	Derived(int, int) : 27	// ����Ŭ���� ������ ����
	~Derived : 27			// ����Ŭ���� �Ҹ��� ����
	~Base() : 27			// ����Ŭ���� �Ҹ��� ����
	~Derived : 15			// ����Ŭ���� �Ҹ��� ����
	~Base() : 15			// ����Ŭ���� �Ҹ��� ����

	��ü�� �����Ǿ��� ������ �ݴ�� ��ü�� �Ҹ�ȴ�.
	���� ���߿� �����Ǿ��� ��ü�� ���� ���� �Ҹ�ȴ�.

	*/

	return 0;
}