#include <cstring>
#include <iostream>
using namespace std;

// Police Ŭ������ ������� ���� ���簡 �̷������� ���Կ����ڿ� ��������ڴ� ����

class Gun {
private:
	int bullet;
public:
	Gun(int bnum = 0) :
		bullet(bnum) {};
	void Shot() {
		cout << "BBANG!" << endl;
		bullet--;
	}

	Gun& operator=(Gun& gun) {
		bullet = gun.bullet;
	}

	void ShowBullet() const{
		cout << "bullet: " << bullet << endl;
	}

	int getBullet() {
		return bullet;
	}
};

class Police {
private:
	int handcuff;
	Gun* pistol;
public:

	Police()
		:handcuff(0), pistol(NULL) {};

	Police(int bnum, int bcuff)
		:handcuff(bcuff) {
		if (bnum > 0) {
			pistol = new Gun(bnum);
		}
		else {
			pistol = NULL;
		}
	}

	// Police Ŭ������ ������� ���� ���簡 �̷������� ���Կ����ڿ� ��������ڴ� ����
	// ���������
	Police(const Police& police) {
		handcuff = police.handcuff;
		if (police.pistol == NULL) {
			pistol = NULL;
		}
		else {
			// police�� ��������� Gun ��ü�� �ƴ϶� Gun�� �����ͺ������ ���� �����.
			delete pistol;
			pistol = new Gun(police.pistol->getBullet());
		}
	}

	// Police Ŭ������ ������� ���� ���簡 �̷������� ���Կ����ڿ� ��������ڴ� ����
	// ���Կ�����
	Police& operator=(const Police& police) {
		// police�� ��������� Gun ��ü�� �ƴ϶� Gun�� �����ͺ������ ���� �����.
		handcuff = police.handcuff;
		delete pistol; // �޸� �����ϴ� �� ����
		pistol = new Gun(police.pistol->getBullet());

		return *this;
	}

	void PutHandcuff() {
		if (handcuff > 0) {
			cout << "SNAP!" << endl;
			handcuff--;
		}
	}

	void Shot() {
		if (pistol == NULL) {
			cout << "Hut BBANG!" << endl;
		}
		else {
			pistol->Shot();
		}
	}

	void Show() const {
		pistol->ShowBullet();
		cout << "handcuff: " << handcuff << endl;
		cout << "========================================" << endl;
	}

	~Police() {
		delete pistol;
	}
};

int main(void) {

	Police policer1(10, 20);
	Police policer2 = policer1; // ���������
	Police policer3;

	policer2.Show(); // 10 20
	policer2.Shot(); 

	policer1.Show(); // 10 20
	policer2.Show(); // 9 20

	policer3 = policer2; // ���Կ�����
	policer2.Shot(); 

	policer2.Show(); // 8 20
	policer3.Show(); // 9 20

	

	return 0;
}
