#include <iostream>
using namespace std;

int soSimpleCnt;  // SoSimple Ŭ������ ���� ��������
int soComplexCnt; // SoComplex Ŭ������ ���� ��������

class SoSimple {
public:
	SoSimple() {
		soSimpleCnt++;
		cout << soSimpleCnt << "��° SoSimple ��ü" << endl;
	}
};

class SoComplex {
public:
	SoComplex() {
		soComplexCnt++;
		cout << soComplexCnt << "��° SoComplex ��ü" << endl;
	}
	SoComplex(SoComplex& cpx) {
		soComplexCnt++;
		cout << soComplexCnt << "��° SoComplex ��ü" << endl;
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