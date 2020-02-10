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

// Ŭ���� �ܺο��� �ʱ�ȭ

int SoSimple::SoSimpleCnt = 0;
int SoSimple::cnt = 0;

int main(void) {
	cout << SoSimple::SoSimpleCnt << "��° Simple ��ü" << endl;
	cout << SoSimple::cnt << "(cnt)" << endl;
	cout << SoSimple::value << "(cnt static value)" << endl;


	SoSimple sim1;
	SoSimple sim2;

	// Ŭ���� ������ ������� public���� �����س��ұ� ������
	// Ŭ���� �ܺο��� ���� �����ϴ�.

	cout << SoSimple::SoSimpleCnt << "��° Simple ��ü" << endl;
	cout << sim1.SoSimpleCnt << "��° Simple ��ü" << endl;
	cout << sim2.SoSimpleCnt << "��° Simple ��ü" << endl;
	cout << SoSimple::value << "(const static value)" << endl;

	cout << SoSimple::cnt << endl;
	cout << sim1.cnt << endl;
	cout << sim2.cnt << endl;
	cout << SoSimple::value << "(const static value)" << endl;

	return 0;
}