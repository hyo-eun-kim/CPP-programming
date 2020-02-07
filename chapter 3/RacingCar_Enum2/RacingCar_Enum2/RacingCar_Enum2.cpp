#include <iostream>
using namespace std;


namespace CAR_CONST {
	enum {
		ID_LEN = 20,
		MAX_SPD = 200,
		FUEL_STEP = 2,
		ACC_STEP = 10,
		BRK_STEP = 10
	};
}

// 구조체 내부에 함수의 선언 + 정의 함께 있으니 너무 복잡
// 구조체 내부에는 함수의 선언만 해두고,
// 정의는 구조체 밖에 하자 (대신 이 함수가 구조체 소속이라는 것을 명시해주어야 한다.)

struct Car {

	char gamerID[CAR_CONST::ID_LEN];
	int fuelGauge;
	int curSpeed;

	void ShowCarState();
	void Accel();
	void Break();

};

// 구조체 내부에서 함수가 정의되면 함수를 인라인으로 처리하라는 의미 내포
// 따라서 구조체 외부에서 함수 정의하고 + 인라인 함수로 처리하고 싶다면
// inline 키워드를 따로 명시해주어야 한다.

inline void Car::ShowCarState() {
	cout << "소유자ID: " << gamerID << endl;
	cout << "연료량: " << fuelGauge << "%" << endl;
	cout << "현재속도: " << curSpeed << "km/s" << endl;
	cout << endl;
}

inline void Car::Accel() {
	if (fuelGauge <= 0) {
		return;
	}
	else {
		fuelGauge -= CAR_CONST::FUEL_STEP;
		if (curSpeed + CAR_CONST::ACC_STEP > CAR_CONST::MAX_SPD) {
			curSpeed = CAR_CONST::MAX_SPD;
			return;
		}
		curSpeed += CAR_CONST::ACC_STEP;
	}
}

inline void Car::Break() {
	if (curSpeed - CAR_CONST::BRK_STEP < 0) {
		curSpeed = 0;
		return;
	}
	else {
		curSpeed -= CAR_CONST::BRK_STEP;
		return;
	}
}

int main(void) {

	Car run99 = { "run99", 100, 0 };
	run99.Accel();
	run99.Accel();
	run99.ShowCarState();
	run99.Break();
	run99.ShowCarState();

	Car sped77 = { "sped77", 100, 0 };
	sped77.Accel();
	sped77.Break();
	sped77.ShowCarState();

	return 0;
}
