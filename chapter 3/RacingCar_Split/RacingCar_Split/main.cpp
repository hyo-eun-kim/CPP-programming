#pragma once
#include "Car.h"

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
