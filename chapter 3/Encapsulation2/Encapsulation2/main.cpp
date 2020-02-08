#include <iostream>
using namespace std;

class SinivelCap {
public:
	void Take() const {
		cout << "�๰�� �����" << endl;
	}
};

class SneezeCap {
public:
	void Take() const {
		cout << "��ä�Ⱑ �����" << endl;
	}
};

class SnuffCap {
public:
	void Take() const {
		cout << "�ڸ����� �շ���" << endl;
	}
};

// �����ִ� ������ �Լ��� �ϳ��� Ŭ���� �ȿ� ���� �� -> ĸ��ȭ
// ĸ��ȭ�� ����� �����̴�. �ֳ��ϸ� ĸ��ȭ�� ������ �����ϴ� ���� ���� �ʱ� �����̴�.

class Cold {
private:
	SinivelCap sinivel;
	SneezeCap sneeze;
	SnuffCap snuff;
public:
	void Take() const {
		sinivel.Take();
		sneeze.Take();
		snuff.Take();
	}
};

class ColdPatient {
public:
	void TakeMedicine(Cold& cold) const{
		cold.Take();
	}
};

int main(void) {

	Cold medicine;
	ColdPatient hyoeun;
	hyoeun.TakeMedicine(medicine);

	return 0;
}