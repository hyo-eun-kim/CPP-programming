#include <iostream>
using namespace std;

class SelfRef {
private:
	int num;
public:
	SelfRef(int num) {
		this->num = num;
		cout << "객체생성" << endl;
	}
	// 자기자신을 참조할 수 있는 참조정보 반환
	SelfRef& Adder(int value) {
		num += value;
		return *this;
	}

	// 자기자신을 참조할 수 있는 참조정보 반환
	SelfRef& ShowTwoNumber(void) {
		cout << num << endl;
		return *this;
	}

};

int main(void) {
	SelfRef obj(3);
	SelfRef& ref = obj.Adder(2); // SelfRef의 객체 obj의 참조자 ref

	obj.ShowTwoNumber(); // 5
	ref.ShowTwoNumber(); // 5

	ref.Adder(1).ShowTwoNumber().Adder(2).ShowTwoNumber();
	return 0;

}