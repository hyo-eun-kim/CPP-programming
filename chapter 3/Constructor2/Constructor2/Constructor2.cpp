#include <iostream>
using namespace std;

// 인자없이 생성자를 호출할 때 괄호를 쓰지 않는 지에 대한 코드

class SimpleClass {
private:
	int num1;
	int num2;
public:
	// 생성자 (constructor)
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