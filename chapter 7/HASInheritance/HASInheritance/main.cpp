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

// ������ ���� ���� ������ ǥ�� �����ϴ� :( 
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