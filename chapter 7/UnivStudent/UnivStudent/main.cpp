#define _CRT_SECURE_NO_WARNINGS
#include <cstring>
#include <iostream>
using namespace std;

#define CHAR_LEN 50

class Person {
private:
	int age;
	char name[CHAR_LEN];
public:
	Person(int age, const char* name) {
		this->age = age;
		strcpy(this->name, name);
	}
	void Introduce() {
		cout << "My name is " << name << endl;
		cout << "I'm " << age << " years old" << endl;
	}
	~Person() {
		cout << "Person class 객체 소멸" << endl;
	}
};

// Person 클래스(기초클래스)를 상속받은 UnivStudent 클래스(유도클래스)
class UnivStudent : public Person {
private:
	char dept[CHAR_LEN];
public:
	// 유도클래스의 생성자에서는 기초클래스의 생성자를 호출하여
	// 기초클래스의 멤버변수를 초기화해주어야 한다.
	// 만약 기초클래스의 생성자를 호출하는 것을 명시하지 않았다면 void 생성자가 호출된다.
	UnivStudent(int age, const char* name, const char* dept)
		:Person(age, name) {
		// 1. 유도클래스의 생성자 호출
		// 2. 기초클래스의 생성자 호출 + 실행
		// 3. 유도클래스의 생성자 실행
		strcpy(this->dept, dept);
	}
	void WhoAreYou() {
		Introduce();
		cout << "My major is " << dept << endl << endl;
	}
	
	~UnivStudent() {
		cout << "UnivStudent 클래스 객체 소멸" << endl;
	}
};

int main(void) {
	UnivStudent person1(22, "Lee", "Computer eng");
	UnivStudent person2(21, "Yoon", "Electronic eng");

	person1.WhoAreYou();
	person2.WhoAreYou();

	return 0;
}
