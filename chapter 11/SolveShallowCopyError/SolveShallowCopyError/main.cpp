#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
using namespace std;

// default 대입연산자는 복사생성자와 유사한 문제점을 갖는다.
// 바로, shallow copy를 진행한다는 점!
// 이 코드는 default 복사생성자에 의해 shallow copy가 일어나고, 이로 인해 발생하는 문제점을 보여주는 코드이다.

class Info {
private:
	char* name;
	int age;
public:
	Info(const char* name, int age)
		:age(age) {
		this->name = new char[strlen(name) + 1]; // 메모리 공간 확보
		strcpy(this->name, name);
	}

	void ShowInfo() const {
		cout << "이름: " << name << endl;
		cout << "나이: " << age << endl;
	}

	Info& operator=(Info& info) {
		delete[] name; // 메모리의 누수를 막기 위해 이전에 new로 할당한 공간 해제
		age = info.age; // age 정보 복사
		name = new char[strlen(info.name) + 1]; // name을 저장하기 위해 메모리 할당
		strcpy(name, info.name); // name을 deep copy
		return *this;
	}

	~Info() {
		delete[] name;
		cout << "called destructor" << endl;
	}
};

int main(void) {
	Info person1("Lee dong woo", 29);
	Info person2("Yoon ji yul", 22);

	person2 = person1; // shallow copy

	// 문제1.
	// person1의 name에 저장된 주소와 person2의 name에 저장된 주소가 동일
	// 따라서 소멸자 호출하며 이미 delete한 메모리공간을 다시 한 번 delete하여 에러 발생

	// 문제2.
	// person2의 name이 가리키던 "Yoon ji yul" 메모리주소가 날아가버림 (떠돌고있다.)
	// 따라서 메모리 누수의 문제 발생

	person1.ShowInfo();
	person2.ShowInfo();

	return 0;

}