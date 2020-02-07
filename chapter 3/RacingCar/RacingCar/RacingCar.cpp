#include <iostream>
#define ID_LEN 20
#define MAX_SPD 200
#define FUEL_SETP 2
#define ACC_STEP 10
#define BRK_STEP 10
using namespace std;

struct Car {
	char gamer_id[ID_LEN];
	int fuelGauge;
	int curSpeed;
};

void ShowCarState(const Car& car) {
	cout << "소유자ID: " << car.gamer_id << endl;
	cout << "연료량: " << car.fuelGauge << endl;
	cout << "현재속도: " << car.curSpeed << "km/s" << endl;
}

void Accel(Car& car) {
	if (car.fuelGauge <= 0)
		return;
	else
		car.fuelGauge -= FUEL_SETP;
	if (car.curSpeed + ACC_STEP >= MAX_SPD) {
		car.curSpeed = MAX_SPD;
		return;
	}
	car.curSpeed += MAX_SPD;
}

void Break(Car& car) {
	if (car.curSpeed - BRK_STEP <= 0) {
		car.curSpeed = 0;
		return;
	}
	car.curSpeed -= BRK_STEP;
	return;
}

int main(void) {

	Car run99 = {"run99", 100, 0 };
	Accel(run99); // 98 200
	Accel(run99); // 96 200
	ShowCarState(run99);
	Break(run99); // 96 190
	ShowCarState(run99);

	Car sped77 = { "sped77", 100, 0 };
	Accel(sped77); // 98 200
	Break(sped77); // 98 190
	ShowCarState(sped77);
	return 0;

}

