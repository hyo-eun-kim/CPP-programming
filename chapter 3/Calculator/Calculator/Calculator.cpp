#include "Calculator.h"
#include <iostream>
using namespace std;

void Calculator::Init() {
	count[0] = 0;
	count[1] = 0;
	count[2] = 0;
	count[3] = 0;
}

double Calculator::Add(double x, double y) {
	count[0]++;
	return x + y;
}
double Calculator::Min(double x, double y) {
	count[1]++;
	return x - y;
}
double Calculator::Mul(double x, double y) {
	count[2]++;
	return x * y;
}
double Calculator::Div(double x, double y) {
	count[3]++;
	return x / y;
}
void Calculator::ShowOpCount() {
	cout << "����: " << count[0] << " ";
	cout << "����: " << count[1] << " ";
	cout << "����: " << count[2] << " ";
	cout << "������: " << count[3] << endl;
}