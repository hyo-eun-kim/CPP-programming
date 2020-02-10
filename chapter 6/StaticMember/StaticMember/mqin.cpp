#include <iostream>
using namespace std;


class SoSimple {
private:
	static int soSimpleCnt; // 클래스 변수
public:
	SoSimple() {
		soSimpleCnt++;
		cout << soSimpleCnt << "번째 SoSimple 객체" << endl;
	}
};

class SoComplex {
private:
	static int soComplexCnt; // 클래스 변수
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

// 생성자가 아닌 클래스 외부에서 초기화를 해야한다.
// 생성자를 통해 초기화를 하게 되면, 객체 생성할 때 마다 클래스 변수가 계속 0이 되어버리기 때문
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