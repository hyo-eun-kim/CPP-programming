#include <iostream>
using namespace std;

int main(void) {
	int num = 10;
	int i = 0;

	cout << "true: " << true << endl; // 1
	cout << "false: " << false << endl; // 0

	while (true) {
		cout << i++ << endl; // 0 1 2 3 4 5 6 7 8 9 10
		if (i > num)
			break;
		cout << endl;
	}

	cout << "sizeof 1: " << sizeof(1) << endl; // 4 bytes
	cout << "sizeof 0: " << sizeof(0) << endl; // 4 bytes
	cout << "sizeof true: " << sizeof(true) << endl; // 1 byte
	cout << "sizeof false: " << sizeof(false) << endl; // 1 byte

	// ���⼭ �����ؾ� �� ���� true�� 1�� �ƴϸ�, fale ���� 0�� �ƴϴ�.
	// ������ ���� ǥ���ϱ� ���� 1��, ������ ǥ���ϱ� ���� 9�� ����߱� ������
	// ����ϴ� ��쿡 ������ ���·� ����ȯ�� �Ǿ� 1�� 0���� ��µǴ� ���̴�.

	return 0;
}