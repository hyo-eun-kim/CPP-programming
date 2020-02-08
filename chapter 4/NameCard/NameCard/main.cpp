#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
using namespace std;

// ������ �ǹ��ϴ� NameCard Ŭ������ �����غ���.
// Ŭ�������� ����, ȸ���̸�, ��ȭ��ȣ, ������ ������ ����Ǿ�� �Ѵ�.
// �� ���� ������ ������ �������� ���ڿ��� ���·� ���� �ϵ�
// ���̿� �� �´� �޸� ������ �Ҵ� �޴� ���·� �����ؾ� �Ѵ�.
// �׸��� ���� ������ int�� ��������� �����ؼ� ������ �ϵ�
// enum {CLERK, SENIOR, ASSIST, MANAGER}�� Ȱ���ؾ� �Ѵ�.

namespace COMP_POS {
	enum {
		CLERK, SENIOR, ASSIST, MANAGER
	};

	void ShowPosition(int pos) {
		switch (pos) {
		case CLERK:
			cout << "���" << endl;
			break;
		case SENIOR:
			cout << "����" << endl;
			break;
		case ASSIST:
			cout << "�븮" << endl;
			break;
		case MANAGER:
			cout << "����" << endl;
			break;
		}
	}
}

class NameCard {
private:
	char* name;
	char* company;
	char* phone;
	int rank;
public:

	// ������ (Constructor)
	NameCard(const char* myName, const char* myCompany, const char* myPhone, int myRank)
		// ��� �̴ϼȶ�����
		:rank(myRank) {
		int nameLen = strlen(myName) + 1;
		int cmpLen = strlen(myCompany) + 1;
		int phLen = strlen(myPhone) + 1;

		// ���� �Ҵ�
		name = new char[nameLen];
		company = new char[cmpLen];
		phone = new char[phLen];

		strcpy(name, myName);
		strcpy(company, myCompany);
		strcpy(phone, myPhone);
	}

	void Show() {
		cout << "�̸�: " << name << endl;
		cout << "ȸ��: " << company << endl;
		cout << "��ȭ��ȣ: " << phone << endl;
		cout << "����: ";
		COMP_POS::ShowPosition(rank);
		cout << endl;
	}

	// �Ҹ��� (Destructor)
	~NameCard() {
		// �����Ҵ��� �޸� ���� ����
		delete[] name;
		delete[] company;
		delete[] phone;
		cout << "call destructor" << endl;
	}
};


int main(void) {

	NameCard manClerk("Lee", "ABCEng", "010-1111-2222", COMP_POS::CLERK);
	NameCard manSenior("Hong", "OrnageEng", "010-3333-4444", COMP_POS::SENIOR);
	NameCard manAssist("Kim", "SoGoodComp", "010-5555-6666", COMP_POS::ASSIST);

	manClerk.Show();
	manSenior.Show();
	manAssist.Show();

	return 0;
}