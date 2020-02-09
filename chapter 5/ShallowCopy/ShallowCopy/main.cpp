#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
using namespace std;

class Simple {
private:
	char* name;
	int age;
public:
	Simple(const char* name, int age) {
		this->name = new char[strlen(name) + 1];
		strcpy(this->name, name);
		this->age = age;
	}
	void Show() const {
		cout << "이름: " << name << endl;
		cout << "나이: " << age << endl;
	}
	~Simple() {
		delete[]name;
		cout << "call destructor" << endl;
	}
};

int main(void) {

	Simple sp1("Lee dong won", 29);
	Simple sp2 = sp1; // shallow copy

	sp1.Show();
	sp2.Show();

	return 0;
}