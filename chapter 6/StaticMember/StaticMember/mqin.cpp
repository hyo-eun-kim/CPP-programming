#include <iostream>
using namespace std;


class SoSimple {
private:
	static int soSimpleCnt; // Ŭ���� ����
public:
	SoSimple() {
		soSimpleCnt++;
		cout << soSimpleCnt << "��° SoSimple ��ü" << endl;
	}
};

class SoComplex {
private:
	static int soComplexCnt; // Ŭ���� ����
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

// �����ڰ� �ƴ� Ŭ���� �ܺο��� �ʱ�ȭ�� �ؾ��Ѵ�.
// �����ڸ� ���� �ʱ�ȭ�� �ϰ� �Ǹ�, ��ü ������ �� ���� Ŭ���� ������ ��� 0�� �Ǿ������ ����
int SoSimple::soSimpleCnt = 0;
int SoComplex::soComplexCnt = 0;

int main(void) {
	SoSimple s1;
	SoSimple s2;

	SoComplex c1;
	SoComplex c2 = c1;
	new SoComplex;

	return 0;
}