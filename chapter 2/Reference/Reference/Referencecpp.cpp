#include <iostream>
using namespace std;

int main(void) {

	// �̹� ����� ������ &�� ����ϸ� �� ������ �ּڰ��� ��ȯ�ϴ� ������������
	// ���� ����Ǵ� ������ &�� ����ϸ� reference�� ������ �ǹ��ϰ� �ȴ�.

	int num1 = 1020;
	int& num2 = num1; // num2�� num1�� reference
	// ��������� num1�̶� �̸� �پ��ִ� �޸𸮰����� num2��� �̸��� �ϳ� �� �ٰ� �� ���̴�.
	// �����ڴ� ������ ������θ� ������ �����ϴ�.

	num2 = 3040;
	cout << "VAL: " << num1 << endl; // 3040
	cout << "REF: " << num2 << endl; // 3040

	cout << "VAL: " << &num1 << endl; // 00AFF778
	cout << "REF: " << &num2 << endl; // 00AFF778

	return 0;
}