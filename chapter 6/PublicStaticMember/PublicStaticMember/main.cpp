#include <iostream>
using namespace std;

class SoSimple {
public:
	static int SoSimpleCnt;
	static int cnt;
	const static int value = 100;
public:
	SoSimple() {
		SoSimpleCnt++;
		cnt += 2;
	}
};

// 클래스 외부에서 초기화

int SoSimple::SoSimpleCnt = 0;
int SoSimple::cnt = 0;

int main(void) {
	cout << SoSimple::SoSimpleCnt << "번째 Simple 객체" << endl;
	cout << SoSimple::cnt << "(cnt)" << endl;
	cout << SoSimple::value << "(cnt static value)" << endl;


	SoSimple sim1;
	SoSimple sim2;

	// 클래스 변수의 접근제어를 public으로 설정해놓았기 때문에
	// 클래스 외부에서 접근 가능하다.

	cout << SoSimple::SoSimpleCnt << "번째 Simple 객체" << endl;
	cout << sim1.SoSimpleCnt << "번째 Simple 객체" << endl;
	cout << sim2.SoSimpleCnt << "번째 Simple 객체" << endl;
	cout << SoSimple::value << "(const static value)" << endl;

	cout << SoSimple::cnt << endl;
	cout << sim1.cnt << endl;
	cout << sim2.cnt << endl;
	cout << SoSimple::value << "(const static value)" << endl;

	return 0;
}