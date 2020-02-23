#include <cstring>
#include <iostream>
using namespace std;

// Police 클래스를 대상으로 깊은 복사가 이뤄지도록 대입연산자와 복사생성자는 정의

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

	// Police 클래스를 대상으로 깊은 복사가 이뤄지도록 대입연산자와 복사생성자는 정의
	// 복사생성자
	Police(const Police& police) {
		handcuff = police.handcuff;
		if (police.pistol == NULL) {
			pistol = NULL;
		}
		else {
			// police의 멤버변수로 Gun 객체가 아니라 Gun의 포인터변수라는 것을 기억해.
			delete pistol;
			pistol = new Gun(police.pistol->getBullet());
		}
	}

	// Police 클래스를 대상으로 깊은 복사가 이뤄지도록 대입연산자와 복사생성자는 정의
	// 대입연산자
	Police& operator=(const Police& police) {
		// police의 멤버변수로 Gun 객체가 아니라 Gun의 포인터변수라는 것을 기억해.
		handcuff = police.handcuff;
		delete pistol; // 메모리 떠나니는 것 방지
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
	Police policer2 = policer1; // 복사생성자
	Police policer3;

	policer2.Show(); // 10 20
	policer2.Shot(); 

	policer1.Show(); // 10 20
	policer2.Show(); // 9 20

	policer3 = policer2; // 대입연산자
	policer2.Shot(); 

	policer2.Show(); // 8 20
	policer3.Show(); // 9 20

	

	return 0;
}
