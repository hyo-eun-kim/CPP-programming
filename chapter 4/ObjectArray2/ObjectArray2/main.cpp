#define _CRT_SECURE_NO_WARNINGS
#include <cstring>
#include <iostream>
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
	}

	void SetPerson(char* myName, int myAge) {
		name = new char[strlen(myName) + 1];
		strcpy(name, myName);
		age = myAge;
	}

	void Show() const{
		cout << "이름: " << name << ", ";
		cout << "나이: " << age << endl;
	}

	~Person() {
		delete[]name;
		cout << "called destructor!" << endl;
	}
};

int main(void) {
	Person* people[3];
	
	char input_name[100];
	char* name;
	int age;


	for (int i = 0; i < 3; i++) {
		cout << "이름: ";
		cin >> input_name;
		cout << "나이: ";
		cin >> age;

		name = new char[strlen(input_name) + 1];
		strcpy(name, input_name);

		people[i] = new Person(name, age);
	}

	people[0]->Show();
	people[1]->Show();
	people[2]->Show();

	delete people[0];
	delete people[1];
	delete people[2];

	return 0;
}