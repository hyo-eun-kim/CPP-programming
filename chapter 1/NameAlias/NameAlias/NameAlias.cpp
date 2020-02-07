#include <iostream>

using namespace std;

namespace AAA {
	namespace BBB {
		namespace CCC {
			int num1 = 10;
			int num2 = 20;
		}
	}
}

int main(void) {

	cout << AAA::BBB::CCC::num1 << endl;
	cout << AAA::BBB::CCC::num2 << endl;

	namespace ABC = AAA::BBB::CCC; // �̸������� ��Ī ����

	cout << ABC::num1 << endl;
	cout << ABC::num2 << endl;

	return 0;
}