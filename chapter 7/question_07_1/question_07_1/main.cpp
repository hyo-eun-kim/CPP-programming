#include <iostream>
using namespace std;

class Car {
private:
	int gasolinGauge;
public:

	Car() {
		gasolinGauge = 0;
		cout << "Car Constructor : Car()" << endl;
	}

	Car(int val) :gasolinGauge(val) {
		cout << "Car Constructor : Car(int)" << endl;
	};

	int GetGasGauge() {
		return gasolinGauge;
	}
};

// Car를 상속받은 HybridCar
class HybridCar : public Car {
private:
	int electricGauge;
public:

	HybridCar() {
		electricGauge = 0;
		cout << "HybridCar Constructor : HybirdCar()" << endl;
	}

	HybridCar(int val) {
		electricGauge = val;
		cout << "HybridCar Constructor : HybirdCar(int)" << endl;
	}

	HybridCar(int val1, int val2)
		:Car(val1){
		electricGauge = val2;
		cout << "HybridCar Constructor : HybirdCar(int, int)" << endl;
	}

	int GetElecGauge(){
		return electricGauge;
	}
};

class HybridWaterCar : public HybridCar {
private:
	int waterGauge;
public:

	HybridWaterCar() {
		waterGauge = 0;
		cout << "HybridWaterCar Constructor : HybirdWaterCar()" << endl;
	}

	HybridWaterCar(int val) {
		waterGauge = val;
		cout << "HybridWaterCar Constructor : HybirdWaterCar(int)" << endl;
	}

	HybridWaterCar(int val1, int val2)
	:HybridCar(val1){
		waterGauge = val2;
		cout << "HybridWaterCar Constructor : HybirdWaterCar(int, int)" << endl;
	}

	void Show() {
		cout << "잔여 가솔린: " << GetGasGauge() << endl;
		cout << "잔여 전기량: " << GetElecGauge() << endl;
		cout << "잔여 워터량: " << waterGauge << endl;
	}
};

int main(void) {
	
	Car car1;
	cout << car1.GetGasGauge() << endl; // 0

	Car car2(10);
	cout << car2.GetGasGauge() << endl; // 10

	cout << "------------------------------" << endl;

	HybridCar car3; // 0 0
	HybridCar car4(20); // 0 20
	HybridCar car5(30, 40); // 30 40

	cout << car3.GetGasGauge() << endl;
	cout << car3.GetElecGauge() << endl;

	cout << car4.GetGasGauge() << endl;
	cout << car4.GetElecGauge() << endl;

	cout << car5.GetGasGauge() << endl;
	cout << car5.GetElecGauge() << endl;

	cout << "------------------------------" << endl;

	HybridWaterCar car6;
	HybridWaterCar car7(50);
	HybridWaterCar car8(60, 70);

	car6.Show(); // 0 0 0 
	car7.Show(); // 0 0 50
	car8.Show(); // 0 60 70

	return 0;
}