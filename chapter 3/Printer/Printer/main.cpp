#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
using namespace std;

class Printer {
private:
	char str[100];
public:
	// ���ڿ� ����
	void SetString(const char* p) {
		strcpy(str, p);
	}
	// ���ڿ� ���
	void ShowString() {
		std::cout << str << std::endl;
	}
};

int main(void) {

	Printer pnt;
	pnt.SetString("Hello World!");
	pnt.ShowString();

	pnt.SetString("I love C++");
	pnt.ShowString();

	return 0;
}