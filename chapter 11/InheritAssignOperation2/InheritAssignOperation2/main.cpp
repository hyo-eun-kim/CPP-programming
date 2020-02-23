#include <iostream>
using namespace std;

class First {
private:
	int num1, num2;
public:
	First(int n1 = 0, int n2 = 0)
		:num1(n1), num2(n2) {}
	void ShowData() {
		cout << num1 << ", " << num2 << endl;
	}
};

class Second : public First {
private:
	int num3, num4;
public:
	Second(int n1 = 0, int n2 = 0, int n3 = 0, int n4 = 0)
		:First(n1, n2), num3(n3), num4(n4) {}
	void ShowData() {
		First::ShowData();
		cout << num3 << ", " << num4 << endl;
	}
	void operator=(Second& sec) {
		First::operator=(sec);	// ������ num3, num4���� �� ����
		// ���Կ����ڸ� ����Ŭ�������� �����ε��� ��� ����Ŭ������ ���Կ����ڸ� ��������� ȣ���ؾ� ��
		num3 = sec.num3;
		num4 = sec.num4;
	}
};

int main(void) {

	Second obj1(10, 20, 30, 40);
	Second obj2;

	obj2 = obj1;
	obj2.ShowData(); // 0, 0, 30, 40

	// ����Ŭ�������� ���Կ����ڸ� �����ε��� ���
	// ����Ŭ������ ���Կ����ڰ� ����Ŭ������ ���Կ����ڸ� ȣ������ �����Ƿ�	
	// ��������� ����Ŭ������ ���Կ����ڸ� ȣ�����־�� �Ѵ�.
}