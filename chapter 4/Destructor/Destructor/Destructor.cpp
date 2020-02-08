#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
using namespace std;

class Info {
private:
	char* name;
	int age;
public:
	Info(const char* myName, int myAge)
	:age(myAge){
		int len = strlen(myName)+1;
		name = new char[len];
		strcpy(name, myName);
	}
	void Show() {
		cout << "이름: " << name << endl;
		cout << "나이: " << age << endl;
	}
	~Info() {
		delete []name;
		cout << "called destructor!" << endl;
	}

};

int main(void) {

	Info hyoeun("jung eun", 24);
	Info changhun("ji eun", 24);

	hyoeun.Show();
	changhun.Show();

	return 0;
}