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

	Person people[3]; // ��ü �迭 ���� 
	// ��ü �迭�� �����ϴ��� �����ڴ� ȣ��ȴ�. (���⼭�� 3�� ȣ��ǰڴ�.)
	// �� ���� �����ڿ� ���ڸ� �������� ���ϱ� ������ People() �����ڰ� ȣ��ȴ�.
	// (�翬�� People() �����ڰ� ���ǵǾ� �־�� �Ѵ�.)

	char name_input[100];
	char* name;
	int age;

	// ��ü�迭 �������� ���ϴ� ������ �ʱ�ȭ��Ű�� ���ؼ���
	// ������ �ʱ�ȭ ������ ���ľ� �Ѵ�.
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