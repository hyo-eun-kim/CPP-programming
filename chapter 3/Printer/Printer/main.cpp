#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
using namespace std;

class Printer {
private:
	char str[100];
public:
	// 문자열 저장
	void SetString(const char* p) {
		strcpy(str, p);
	}
	// 문자열 출력
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