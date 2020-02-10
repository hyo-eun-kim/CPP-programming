#include <iostream>
using namespace std;


class Gun {
private:
	int bullet;
public:
	Gun(int val) :bullet(val) {}

	void Shot() {
		cout << "BBANG!" << endl;
		bullet--;
	}
};

// ���� ������ ������ �׷��� ���� ���� �� �� ��������
class Police{
private:
	int handcuff;
	Gun* gun;
public:
	Police(int handcuff)
		:handcuff(handcuff){
		gun = NULL;
	}

	void GetGun(int bullet) {
		gun = new Gun(bullet);
	}

	void Shot() {
		if (gun == NULL) {
			cout << "���� �������� �ʾҽ��ϴ�" << endl;
			return;
		}
		gun->Shot();
	}

	void PutHandCuff() {
		cout << "SNAP!" << endl;
		handcuff--;
	}

};

int main(void) {

	Police person(5);

	person.Shot(); // ���� �������� �ʾҽ��ϴ�

	person.GetGun(10); 
	person.Shot();

	
	return 0;
}