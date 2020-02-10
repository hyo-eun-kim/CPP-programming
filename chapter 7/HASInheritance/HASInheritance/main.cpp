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

// 무조건 총을 가진 경찰만 표현 가능하다 :( 
class Police : public Gun {
private:
	int handcuff;
public:
	Police(int bullet_v, int handcuff_v)
		:Gun(bullet_v), handcuff(handcuff_v){}

	void PutHandCuff() {
		cout << "SNAP!" << endl;
		handcuff--;
	}
};

int main(void) {

	Police person(5, 3);
	person.Shot();
	person.PutHandCuff();

	return 0;
}