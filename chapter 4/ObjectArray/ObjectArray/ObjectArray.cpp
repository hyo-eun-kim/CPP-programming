#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
using namespace std;

class Person {
private:
	char* name;
	int age;
public:
	Person(char* myName, int myAge) {
		name = new char[strlen(myName) + 1];
		strcpy(name, myName);
		age = myAge;
	}
	Person() {
		name = NULL;
		age = 0;
		cout << "Constructor called" << endl;
	}
	void SetPerson(char* myName, int myAge) {
		name = myName;
		age = myAge;
	}
	void Show() {
		cout << "name: " << name << endl;
		cout << "age: " << age << endl;
		cout << endl;
	}
	~Person() {
		delete[]name;
		cout << "Destructor called" << endl;
	}
};

int main(void) {

	Person people[3]; // 객체 배열 생성 
	// 객체 배열을 생성하더라도 생성자는 호출된다. (여기서는 3번 호출되겠다.)
	// 이 때는 생성자에 인자를 전달하지 못하기 때문에 People() 생성자가 호출된다.
	// (당연히 People() 생성자가 정의되어 있어야 한다.)

	char name_input[100];
	char* name;
	int age;

	// 객체배열 선언이후 원하는 값으로 초기화시키기 위해서는
	// 일일이 초기화 과정을 거쳐야 한다.
	for (int i = 0; i < 3; i++) {
		cout << "name > ";
		cin >> name_input;
		cout << "Age > ";
		cin >> age;

		name = new char[strlen(name_input) + 1];
		strcpy(name, name_input);

		people[i].SetPerson(name, age);

	}
	
	people[0].Show();
	people[1].Show();
	people[2].Show();
	

	return 0;
}