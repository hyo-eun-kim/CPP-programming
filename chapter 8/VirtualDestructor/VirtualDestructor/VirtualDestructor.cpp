#define _CRT_SECURE_NO_WARNINGS
#include <cstring>
#include <iostream>
using namespace std;

class First {
private:
	char* name1;
public:
	First(const char* name) {
		name1 = new char[strlen(name) + 1];
		strcpy(name1, name);
	}
	virtual ~First() {
		cout << "~First()" << endl;
		delete[] name1;
	}
};

class Second : public First {
private:
	char* name2;
public:
	Second(const char* name1, const char* name)
		:First(name1){
		name2 = new char[strlen(name) + 1];
		strcpy(name2, name);
	}

	virtual ~Second() {
		cout << "~Second()" << endl;
		delete[] name2;
	}
};

int main(void) {

	First* p = new Second("kim", "jeong");

	delete p; // ���⼭ �Ҹ��� ȣ��ȴ�

	// �Ҹ��ڿ� virtual Ű���� ����ؼ� Second Ŭ������ �Ҹ��ڿ� First Ŭ������ �Ҹ��� ȣ���
	// �׷��� ������ First Ŭ������ �Ҹ��ڸ� ȣ���
	// �ֳ��ϸ� p�� First ��ü�� �������̱� ������!

	return 0;
}