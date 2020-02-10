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
		cout << "MyFriendInfo ������ ȣ��" << endl;
	}

	void ShowFriendInfo() const {
		cout << "�̸�: " << name << endl;
		cout << "����: " << age << endl;
	}
	~MyFriendInfo() {
		delete[] name;
		cout << "MyFriendInfo �Ҹ��� ȣ��" << endl;
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

		cout << "MyFriendDetailInfo ������ ȣ��" << endl;
	}

	void SHowMyFriendDetailInfo() const {
		ShowFriendInfo();
		cout << "�ּ�: " << addr << endl;
		cout << "��ȣ: " << phone << endl;
	}

	// �� Ŭ�������� �����Ҵ��� �κи� delete ���ָ� �ȴ�
	~MyFriendDetailInfo() {
		delete[] addr;
		delete[] phone;
		cout << "MyFriendDetailInfo �Ҹ��� ȣ��" << endl;
	}
};

int main(void) {

	MyFriendInfo people1("��ȿ��", 24); // ������ 1�� ȣ��
	people1.ShowFriendInfo();

	MyFriendDetailInfo people2("��ȿ��", 24, "�����", "010-1111-2222"); // ������ 2�� ȣ��
	people2.ShowFriendInfo();
	people2.SHowMyFriendDetailInfo();

	// DetailInfo �Ҹ���
	// Info �Ҹ���
	// Info �Ҹ���

	return 0;
}