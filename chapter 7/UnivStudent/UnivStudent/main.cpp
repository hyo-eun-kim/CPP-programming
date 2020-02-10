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
		cout << "Person class ��ü �Ҹ�" << endl;
	}
};

// Person Ŭ����(����Ŭ����)�� ��ӹ��� UnivStudent Ŭ����(����Ŭ����)
class UnivStudent : public Person {
private:
	char dept[CHAR_LEN];
public:
	// ����Ŭ������ �����ڿ����� ����Ŭ������ �����ڸ� ȣ���Ͽ�
	// ����Ŭ������ ��������� �ʱ�ȭ���־�� �Ѵ�.
	// ���� ����Ŭ������ �����ڸ� ȣ���ϴ� ���� ������� �ʾҴٸ� void �����ڰ� ȣ��ȴ�.
	UnivStudent(int age, const char* name, const char* dept)
		:Person(age, name) {
		// 1. ����Ŭ������ ������ ȣ��
		// 2. ����Ŭ������ ������ ȣ�� + ����
		// 3. ����Ŭ������ ������ ����
		strcpy(this->dept, dept);
	}
	void WhoAreYou() {
		Introduce();
		cout << "My major is " << dept << endl << endl;
	}
	
	~UnivStudent() {
		cout << "UnivStudent Ŭ���� ��ü �Ҹ�" << endl;
	}
};

int main(void) {
	UnivStudent person1(22, "Lee", "Computer eng");
	UnivStudent person2(21, "Yoon", "Electronic eng");

	person1.WhoAreYou();
	person2.WhoAreYou();

	return 0;
}
