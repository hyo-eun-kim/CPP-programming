#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
using namespace std;

// 명함을 의미하는 NameCard 클래스를 정의해보자.
// 클래스에는 성명, 회사이름, 전화번호, 직급의 정보가 저장되어야 한다.
// 단 직급 정보를 제외한 나머지는 문자열의 형태로 저장 하되
// 길이에 딱 맞는 메모리 공간을 할당 받는 형태로 정의해야 한다.
// 그리고 직급 정보는 int형 멤버변수를 선언해서 저장을 하되
// enum {CLERK, SENIOR, ASSIST, MANAGER}을 활용해야 한다.

namespace COMP_POS {
	enum {
		CLERK, SENIOR, ASSIST, MANAGER
	};

	void ShowPosition(int pos) {
		switch (pos) {
		case CLERK:
			cout << "사원" << endl;
			break;
		case SENIOR:
			cout << "주임" << endl;
			break;
		case ASSIST:
			cout << "대리" << endl;
			break;
		case MANAGER:
			cout << "과장" << endl;
			break;
		}
	}
}

class NameCard {
private:
	char* name;
	char* company;
	char* phone;
	int rank;
public:

	// 생성자 (Constructor)
	NameCard(const char* myName, const char* myCompany, const char* myPhone, int myRank)
		// 멤버 이니셜라이저
		:rank(myRank) {
		int nameLen = strlen(myName) + 1;
		int cmpLen = strlen(myCompany) + 1;
		int phLen = strlen(myPhone) + 1;

		// 동적 할당
		name = new char[nameLen];
		company = new char[cmpLen];
		phone = new char[phLen];

		strcpy(name, myName);
		strcpy(company, myCompany);
		strcpy(phone, myPhone);
	}

	void Show() {
		cout << "이름: " << name << endl;
		cout << "회사: " << company << endl;
		cout << "전화번호: " << phone << endl;
		cout << "직급: ";
		COMP_POS::ShowPosition(rank);
		cout << endl;
	}

	// 소멸자 (Destructor)
	~NameCard() {
		// 동적할당한 메모리 영역 해제
		delete[] name;
		delete[] company;
		delete[] phone;
		cout << "call destructor" << endl;
	}
};


int main(void) {

	NameCard manClerk("Lee", "ABCEng", "010-1111-2222", COMP_POS::CLERK);
	NameCard manSenior("Hong", "OrnageEng", "010-3333-4444", COMP_POS::SENIOR);
	NameCard manAssist("Kim", "SoGoodComp", "010-5555-6666", COMP_POS::ASSIST);

	manClerk.Show();
	manSenior.Show();
	manAssist.Show();

	return 0;
}