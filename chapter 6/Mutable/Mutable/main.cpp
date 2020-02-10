#include <iostream>
using namespace std;

class SoSimple {
private:
	int num1;
	mutable int num2;
public:
	SoSimple(int n1, int n2)
		:num1(n1), num2(n2){}
	void Show() {
		cout << num1 << ", " << num2 << endl;
	}
	void Copy() const{
		// mutable�� ��� const �Լ� �������� ���� ������ �����ϴ�.
		// ������ �̰��� const ������ ����Ʈ���� ������ �ִ��� ���������� ����ϵ��� �Ѵ�.
		num2 = num1;
	}
};

int main(void) {
	SoSimple sp(1, 2);
	sp.Show();
	sp.Copy();
	sp.Show();

	return 0;
}