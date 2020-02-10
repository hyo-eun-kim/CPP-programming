#include <iostream>
using namespace std;

class SoSimple {
private:
	int num1;
	mutable int num2;
public:
	SoSimple(int n1, int n2)
		:num1(n1), num2(n2){}
	void Show() {
		cout << num1 << ", " << num2 << endl;
	}
	void Copy() const{
		// mutable의 경우 const 함수 내에서도 값의 변경이 가능하다.
		// 하지만 이것은 const 개념을 무너트리기 때문에 최대한 제한적으로 사용하도록 한다.
		num2 = num1;
	}
};

int main(void) {
	SoSimple sp(1, 2);
	sp.Show();
	sp.Copy();
	sp.Show();

	return 0;
}