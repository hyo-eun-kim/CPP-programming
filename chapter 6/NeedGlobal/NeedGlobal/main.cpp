#include <iostream>
using namespace std;

int soSimpleCnt;  // SoSimple 클래스를 위한 전역변수
int soComplexCnt; // SoComplex 클래스를 위한 전역변수

class SoSimple {
public:
	SoSimple() {
		soSimpleCnt++;
		cout << soSimpleCnt << "번째 SoSimple 객체" << endl;
	}
};

class SoComplex {
public:
	SoComplex() {
		soComplexCnt++;
		cout << soComplexCnt << "번째 SoComplex 객체" << endl;
	}
	SoComplex(SoComplex& cpx) {
		soComplexCnt++;
		cout << soComplexCnt << "번째 SoComplex 객체" << endl;
	}
};

int main(void) {
	SoSimple s1;
	SoSimple s2;

	SoComplex c1;
	SoComplex c2 = c1;
	new SoComplex;
	
	return 0;
}