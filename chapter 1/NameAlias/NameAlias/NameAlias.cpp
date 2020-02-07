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

	namespace ABC = AAA::BBB::CCC; // 이름공간의 별칭 지정

	cout << ABC::num1 << endl;
	cout << ABC::num2 << endl;

	return 0;
}