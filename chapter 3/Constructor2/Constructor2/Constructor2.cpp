#include <iostream>
using namespace std;

// ���ھ��� �����ڸ� ȣ���� �� ��ȣ�� ���� �ʴ� ���� ���� �ڵ�

class SimpleClass {
private:
	int num1;
	int num2;
public:
	// ������ (constructor)
	SimpleClass(int n1=1, int n2=2) {
		num1 = n1;
		num2 = n2;
	}
	void Show() {
		cout << num1 << ", " << num2 << endl;
	}
};

SimpleClass sc1() {
	SimpleClass sc(7, 5);
	return sc;
}

int main(void) {

	SimpleClass sc1();
	SimpleClass sc2 = sc1();

	sc2.Show();


	return 0;
}