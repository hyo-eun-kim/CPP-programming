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

// 총을 소유한 경찰과 그렇지 않은 경찰 둘 다 생성가능
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
			cout << "총을 소지하지 않았습니다" << endl;
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

	person.Shot(); // 총을 소지하지 않았습니다

	person.GetGun(10); 
	person.Shot();

	
	return 0;
}