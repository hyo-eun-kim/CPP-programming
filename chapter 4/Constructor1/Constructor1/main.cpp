// ������ (Constructor)
// 1. Ŭ������ �̸��� ������ �Լ�
// 2. ��ȯ���� ���� �Լ�

// �����ڴ� ��ü ���� �� �ڵ����� �� �� �� ȣ��Ǵ� �Լ�
// ������(constructor) ���� �Լ��̹Ƿ� �����ε��� �����ϸ�, default���� ������ �� �ִ�.

#include <iostream>
using namespace std;

class SimpleClass {
private:
	int num1;
	int num2;
public:
	SimpleClass() {
		num1 = 0;
		num2 = 0;
	}
	SimpleClass(int n) {
		num1 = n;
		num2 = 0;
	}
	SimpleClass(int n1, int n2) {
		num1 = n1;
		num2 = n2;
	}
	void Show() {
		cout << "num1: " << num1 << endl;
		cout << "num2: " << num2 << endl;
	}
};

int main(void) {
	SimpleClass c1;
	c1.Show();

	SimpleClass c2(2);
	c2.Show();

	SimpleClass c3(3, 5);
	c3.Show();
}