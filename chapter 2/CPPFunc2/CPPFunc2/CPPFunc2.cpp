#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

// rand, srand, time �Լ��� �̿��� 0�̻� 100�̸��� ������ 10�� �����ϴ� ����

int main(void) {

	
	srand(time(NULL));
	
	for (int i = 0; i < 10; i++) {
		cout << rand()%100 << endl;
	}
	
	return 0;
}