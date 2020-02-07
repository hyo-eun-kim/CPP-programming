#include <iostream>
#define ID_LEN 20
#define MAX_SPD 200
#define FUEL_SETP 2
#define ACC_STEP 10
#define BRK_STEP 10
using namespace std;

// 구조체 내에 함수

struct Car {
	char gamer_id[ID_LEN];
	int fuelGauge;
	int curSpeed;

	void ShowCarState() {
		cout << "소유자ID: " << gamer_id << endl;
		cout << "연료량: " << fuelGauge << endl;
		cout << "현재속도: " << curSpeed << "km/s" << endl;
		cout << endl;
	}

	void Accel() {
		if (fuelGauge <= 0)
			return;
		else
			fuelGauge -= FUEL_SETP;
		if (curSpeed + ACC_STEP >= MAX_SPD) {
			curSpeed = MAX_SPD;
			return;
		}
		curSpeed += MAX_SPD;
	}

	void Break() {
		if (curSpeed - BRK_STEP <= 0) {
			curSpeed = 0;
			return;
		}
		curSpeed -= BRK_STEP;
		return;
	}

};



int main(void) {

	Car run99 = { "run99", 100, 0 };
	run99.Accel();
	run99.Accel();
	run99.Break();
	run99.ShowCarState();

	Car sped77 = { "sped77", 100, 0 };
	sped77.Accel();
	sped77.Break();
	sped77.ShowCarState();

	return 0;

}

