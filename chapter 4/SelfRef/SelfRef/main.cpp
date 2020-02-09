#include <iostream>
using namespace std;

class SelfRef {
private:
	int num;
public:
	SelfRef(int num) {
		this->num = num;
		cout << "��ü����" << endl;
	}
	// �ڱ��ڽ��� ������ �� �ִ� �������� ��ȯ
	SelfRef& Adder(int value) {
		num += value;
		return *this;
	}

	// �ڱ��ڽ��� ������ �� �ִ� �������� ��ȯ
	SelfRef& ShowTwoNumber(void) {
		cout << num << endl;
		return *this;
	}

};

int main(void) {
	SelfRef obj(3);
	SelfRef& ref = obj.Adder(2); // SelfRef�� ��ü obj�� ������ ref

	obj.ShowTwoNumber(); // 5
	ref.ShowTwoNumber(); // 5

	ref.Adder(1).ShowTwoNumber().Adder(2).ShowTwoNumber();
	return 0;

}