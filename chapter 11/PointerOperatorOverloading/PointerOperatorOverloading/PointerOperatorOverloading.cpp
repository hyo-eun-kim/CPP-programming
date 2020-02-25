#include <iostream>
using namespace std;


class Number {
private:
	int num;
public:
	Number(int n = 0) :num(n) {};

	void ShowData() {
		cout << num << endl;
	}

	Number& operator*() {
		return *this;
	}

	Number* operator->() {
		return this;
	}
};

int main(void) {
	Number num(20); // �Ҹ��� ȣ�� + ��ü ����
	num.ShowData(); // num ��ü�� ����Լ��� ����

	// *�� ��ü�� ����
	// ->�� ��ü�� ����� ����


	// ������ �����ε��� ���� num�� ��� ��ü�ӿ��� �ұ��ϰ� �����ͺ���ó�� ����
	(*num) = 30;		// �ڱ��ڽ��� ������ �� �ִ� ������ ��ȯ
	num->ShowData();	// num->()�� �ڱ��ڽ��� �ּҰ� ��ȯ
	(*num).ShowData();	// *num�� �ڱ��ڽ��� ������ �� �ִ� ������ ��ȯ
	return 0;
}