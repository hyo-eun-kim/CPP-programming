#include <iostream>

using namespace std;
int val = 100;

void SimpleFunc(int* val){
	*val += 3;
	::val += 5; // �������� val ��Ī
	
}

int main(void) {

	int val = 10;
	SimpleFunc(&val);

	cout << val << endl; // 13 (��������)
	cout << ::val << endl; // 105 (��������)
	
}