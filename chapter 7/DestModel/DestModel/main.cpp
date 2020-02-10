#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
using namespace std;

class Person {
private:
	char* name;
public:
	Person(const char* name) {
		this->name = new char[strlen(name) + 1];
		strcpy(this->name, name);
	}
	~Person() {
		cout << name << " Call ~Person" << endl;
		delete[] name;
	}
	void WhatYourName() const{
		cout << "My name is " << name << endl;
	}

	char* GetName() {
		return name;
	}
};

class UnivStudent : public Person {
private:
	char* major;
public:
	UnivStudent(const char* name, const char* major)
		:Person(name) {
		this->major = new char[strlen(major) + 1];
		strcpy(this->major, major);
	}
	~UnivStudent() {
		cout << GetName() << " Call ~UnivStudent" << endl;
		delete[] major;
	}
	void WhoAreYou() const {
		WhatYourName();
		cout << "My dept is " << major << endl << endl;
	}
};


int main(void) {

	UnivStudent person1("Kim", "Math");
	UnivStudent person2("Hong", "Physics");

	person1.WhoAreYou();
	person2.WhoAreYou();

	// Hong Call ~UnivStudnet // 유도클래스 소멸자 호출
	// Hong Call ~Person
	// Kim Call ~UnivStudent
	// Kim call ~Person

	return 0;
}