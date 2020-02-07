#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
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


class Car {
private:	
	// Ŭ���� �������� ���� ���
	char gamerID[CAR_CONST::ID_LEN];
	int fuelGauge;
	int curSpeed;
public:
	// ��𼭵� ���� ���
	void InitMember(const char* ID, int fuel);
	void ShowCarState();
	void Accel();
	void Break();

};

void Car::InitMember(const char* ID, int fuel) {
	strcpy(gamerID, ID);
	fuelGauge = fuel;
	curSpeed = 0;
}

void Car::ShowCarState() {
	cout << "������ID: " << gamerID << endl;
	cout << "���ᷮ: " << fuelGauge << "%" << endl;
	cout << "����ӵ�: " << curSpeed << "km/s" << endl;
	cout << endl;
}

void Car::Accel() {
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

void Car::Break() {
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

	Car run99;
	run99.InitMember("run99", 100);
	run99.Accel();
	run99.Accel();
	run99.ShowCarState();
	run99.Break();
	run99.ShowCarState();

	Car sped77;
	sped77.InitMember("sped77", 100);
	sped77.Accel();
	sped77.Break();
	sped77.ShowCarState();

	return 0;
}
