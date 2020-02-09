#include <iostream>
using namespace std;

class SoSimple {
private:
	int num1;
	int num2;
public:
	SoSimple(int num1, int num2) {
		this->num1 = num1;
		this->num2 = num2;
	}
	/*
	SoSimple(SoSimple& simple)
		:num1(simple.num1), num2(simple.num2) {};
	*/
	void Show() {
		cout << num1 << endl;
		cout << num2 << endl;
	}

};

int main(void) {
	SoSimple sim1(15, 30);
	cout << "생성 및 초기화 직전" << endl;
	SoSimple sim2 = sim1;
	sim2.Show();
}