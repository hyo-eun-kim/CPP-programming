#include <iostream>
using namespace std;

// Ŭ������ ����Լ��� ��ü ���� �����ұ�? -> NO
// �Ʒ��� �����ڵ带 ���� ��� �����ϴ� �� ������ �� �ִ�.

// ���⼭�� �Լ������͸� ����Ͽ� ����ü ������ ����ü �ܺο� �����ϴ� �Լ��� �����Ͽ�����
// Ŭ������ ����Լ��� ��� �ܺο� �����ϰ�, ��ü�� �� �Լ��� �ּҸ� �̿��� �Լ��� �����ϴ� ��!

typedef struct Data {
	int num;
	void(*ShowData)(struct Data*);
	void(*Add)(struct Data*, int val);
}Data;

void ShowData(struct Data* data) {
	cout << data->num << endl;
}

void Add(Data* data, int val) {
	data->num += val;
}

int main(void) {

	Data data1 = { 10, ShowData, Add };
	Data data2 = { 12, ShowData, Add };

	data1.Add(&data1, 5);
	data1.ShowData(&data1);

	data2.Add(&data2, 8);
	data2.ShowData(&data2);

	return 0;
}