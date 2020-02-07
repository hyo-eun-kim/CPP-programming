#include <iostream>

using namespace std;
int val = 100;

void SimpleFunc(int* val){
	*val += 3;
	::val += 5; // 전역변수 val 지칭
	
}

int main(void) {

	int val = 10;
	SimpleFunc(&val);

	cout << val << endl; // 13 (지역변수)
	cout << ::val << endl; // 105 (전역변수)
	
}