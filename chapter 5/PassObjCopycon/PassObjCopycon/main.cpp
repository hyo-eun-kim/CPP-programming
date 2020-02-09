#include <iostream>
using namespace std;

class SoSimple {
private:
	int num;
public:
	SoSimple(int num) :num(num) {};
	SoSimple(const SoSimple& copy) :num(copy.num) {
		cout << "called SoSimple(const SoSimple& copy)" << endl;
	};
	void Show() const {
		cout << "num: " << num << endl;
	}
};

int main(void) {

	SoSimple sp1(7);
	SoSimple sp2 = sp1; // �Ű������� ��ü ���޵Ǹ� ��������� ȣ��
	sp2.Show();

	return 0;
}