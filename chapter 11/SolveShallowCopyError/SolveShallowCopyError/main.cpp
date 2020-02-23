#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
using namespace std;

// default ���Կ����ڴ� ��������ڿ� ������ �������� ���´�.
// �ٷ�, shallow copy�� �����Ѵٴ� ��!
// �� �ڵ�� default ��������ڿ� ���� shallow copy�� �Ͼ��, �̷� ���� �߻��ϴ� �������� �����ִ� �ڵ��̴�.

class Info {
private:
	char* name;
	int age;
public:
	Info(const char* name, int age)
		:age(age) {
		this->name = new char[strlen(name) + 1]; // �޸� ���� Ȯ��
		strcpy(this->name, name);
	}

	void ShowInfo() const {
		cout << "�̸�: " << name << endl;
		cout << "����: " << age << endl;
	}

	Info& operator=(Info& info) {
		delete[] name; // �޸��� ������ ���� ���� ������ new�� �Ҵ��� ���� ����
		age = info.age; // age ���� ����
		name = new char[strlen(info.name) + 1]; // name�� �����ϱ� ���� �޸� �Ҵ�
		strcpy(name, info.name); // name�� deep copy
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

	// ����1.
	// person1�� name�� ����� �ּҿ� person2�� name�� ����� �ּҰ� ����
	// ���� �Ҹ��� ȣ���ϸ� �̹� delete�� �޸𸮰����� �ٽ� �� �� delete�Ͽ� ���� �߻�

	// ����2.
	// person2�� name�� ����Ű�� "Yoon ji yul" �޸��ּҰ� ���ư����� (�������ִ�.)
	// ���� �޸� ������ ���� �߻�

	person1.ShowInfo();
	person2.ShowInfo();

	return 0;

}