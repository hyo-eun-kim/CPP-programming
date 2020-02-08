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

class ColdPatient {
public:
	void TakeSinivelCap(const SinivelCap& cap) const {
		cap.Take();
	}
	void TakeSneezeCap(const SneezeCap& cap) const {
		cap.Take();
	}
	void TakeSnuffCap(const SnuffCap& cap)const {
		cap.Take();
	}
};

int main(void) {

	SinivelCap sinivel;
	SneezeCap sneeze;
	SnuffCap snuff;

	ColdPatient hyoeun;
	hyoeun.TakeSinivelCap(sinivel);
	hyoeun.TakeSneezeCap(sneeze);
	hyoeun.TakeSnuffCap(snuff);
	
	return 0;
}