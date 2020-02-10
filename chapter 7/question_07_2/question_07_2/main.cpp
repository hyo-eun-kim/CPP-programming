#define _CRT_SECURE_NO_WARNINGS
#include <cstring>
#include <iostream>
using namespace std;

class MyFriendInfo {
private:
	char* name;
	int age;
public:

	MyFriendInfo() {
		name = NULL;
		age = 0;
	}

	MyFriendInfo(const char* name, int age):age(age) {
		this->name = new char[strlen(name) + 1];
		strcpy(this->name, name);
		cout << "MyFriendInfo 생성자 호출" << endl;
	}

	void ShowFriendInfo() const {
		cout << "이름: " << name << endl;
		cout << "나이: " << age << endl;
	}
	~MyFriendInfo() {
		delete[] name;
		cout << "MyFriendInfo 소멸자 호출" << endl;
	}
};

class MyFriendDetailInfo : public MyFriendInfo {
private:
	char* addr;
	char* phone;
public:

	MyFriendDetailInfo(const char* name, int age, const char* addr, const char* phone)
	:MyFriendInfo(name, age){
		this->addr  = new char[strlen(addr) + 1];
		this->phone = new char[strlen(phone) + 1];

		strcpy(this->addr, addr);
		strcpy(this->phone, phone);

		cout << "MyFriendDetailInfo 생성자 호출" << endl;
	}

	void SHowMyFriendDetailInfo() const {
		ShowFriendInfo();
		cout << "주소: " << addr << endl;
		cout << "번호: " << phone << endl;
	}

	// 이 클래스에서 동적할당한 부분만 delete 해주면 된다
	~MyFriendDetailInfo() {
		delete[] addr;
		delete[] phone;
		cout << "MyFriendDetailInfo 소멸자 호출" << endl;
	}
};

int main(void) {

	MyFriendInfo people1("김효은", 24); // 생성자 1번 호출
	people1.ShowFriendInfo();

	MyFriendDetailInfo people2("김효은", 24, "서울시", "010-1111-2222"); // 생성자 2번 호출
	people2.ShowFriendInfo();
	people2.SHowMyFriendDetailInfo();

	// DetailInfo 소멸자
	// Info 소멸자
	// Info 소멸자

	return 0;
}