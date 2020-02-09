#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
using namespace std;

namespace COMP_POS {
	enum {CLERK, SENIOR, ASSIST, MANAGER};
}

void showLevel(int pos) {
	switch (pos) {
	case 0:
		cout << "사원" << endl;
		break;
	case 1:
		cout << "주임" << endl;
		break;
	case 2:
		cout << "대리" << endl;
		break;
	case 3:
		cout << "과장" << endl;
		break;
	}
}

class NameCard {
private:
	char* name;
	char* company;
	char* phone;
	int level;
public:

	// 생성자
	NameCard(const char* name, const char* company, const char* phone, int level)
		:level(level) {
		this->name = new char[strlen(name) + 1];
		this->company = new char[strlen(company) + 1];
		this->phone = new char[strlen(phone) + 1];

		strcpy(this->name, name);
		strcpy(this->company, company);
		strcpy(this->phone, phone);
	}

	// 복사생성자
	NameCard(const NameCard& info){
		name = new char[strlen(info.name) + 1];
		company = new char[strlen(info.company) + 1];
		phone = new char[strlen(info.phone) + 1];

		strcpy(name, info.name);
		strcpy(company, info.company);
		strcpy(phone, info.phone);

		level = info.level;
	}

	void Show() const {
		cout << "이름: " << name << endl;
		cout << "회사: " << company << endl;
		cout << "전화번호: " << phone << endl;
		cout << "직급: ";
		showLevel(level);

 	}

	// 소멸자
	~NameCard() {
		delete[] name;
		delete[] company;
		delete[] phone;
		cout << "call destructor" << endl;
	}
};

int main(void) {

	NameCard manClerk("Lee", "ABC", "010-1111-2222", COMP_POS::CLERK);
	NameCard copy1 = manClerk; // deep copy
	NameCard manSenior("Hong", "Orange", "010-3333-5555", COMP_POS::SENIOR);
	NameCard copy2 = manSenior; // deep copy

	copy1.Show();
	copy2.Show();

	return 0;

}