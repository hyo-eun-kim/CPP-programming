#include <iostream>
using namespace std;

// 클래스의 멤버함수는 객체 내에 존재할까? -> NO
// 아래의 예제코드를 보면 어떻게 존재하는 지 이해할 수 있다.

// 여기서는 함수포인터를 사용하여 구조체 변수가 구조체 외부에 존재하는 함수에 접근하였듯이
// 클래스의 멤버함수는 멤버 외부에 존재하고, 객체는 그 함수의 주소를 이용해 함수에 접근하는 것!

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