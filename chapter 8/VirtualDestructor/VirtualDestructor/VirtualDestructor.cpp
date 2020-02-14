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

	delete p; // 여기서 소멸자 호출된다

	// 소멸자에 virtual 키워드 사용해서 Second 클래스의 소멸자와 First 클래스의 소멸자 호출됨
	// 그렇지 않으면 First 클래스의 소멸자만 호출됨
	// 왜냐하면 p가 First 객체의 포인터이기 때문에!

	return 0;
}