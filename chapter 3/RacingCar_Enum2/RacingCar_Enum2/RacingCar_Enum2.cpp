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

// ����ü ���ο� �Լ��� ���� + ���� �Բ� ������ �ʹ� ����
// ����ü ���ο��� �Լ��� ���� �صΰ�,
// ���Ǵ� ����ü �ۿ� ���� (��� �� �Լ��� ����ü �Ҽ��̶�� ���� ������־�� �Ѵ�.)

struct Car {

	char gamerID[CAR_CONST::ID_LEN];
	int fuelGauge;
	int curSpeed;

	void ShowCarState();
	void Accel();
	void Break();

};

// ����ü ���ο��� �Լ��� ���ǵǸ� �Լ��� �ζ������� ó���϶�� �ǹ� ����
// ���� ����ü �ܺο��� �Լ� �����ϰ� + �ζ��� �Լ��� ó���ϰ� �ʹٸ�
// inline Ű���带 ���� ������־�� �Ѵ�.

inline void Car::ShowCarState() {
	cout << "������ID: " << gamerID << endl;
	cout << "���ᷮ: " << fuelGauge << "%" << endl;
	cout << "����ӵ�: " << curSpeed << "km/s" << endl;
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
