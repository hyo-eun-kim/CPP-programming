#include <iostream>
using namespace std;

class BaseOne {
private:
	int num;
public:
	void SimpleFunc() {
		cout << "BaseOne" << endl;
	}
};

class BaseTwo {
private:
	int num;
public:
	void SimpleFunc() {
		cout << "BaseTwo" << endl;
	}
};

// �� �� �̻��� Ŭ������ ����ϴ� -> ���߻��
// �� �� ����Ŭ������ ����Լ����� �����ϴٸ�? 
// ��� Ŭ������ �Լ����� ��ȣ���� (ambiguous) 
// ���� ��� Ŭ������ ����Լ����� ������־�� �Ѵ�.

class Derived : public BaseOne, public BaseTwo {
private:
	int num;
public:
	void Func() {
		// SimpleFunc(); // ��� Ŭ������ �Լ����� �ν����� ����

		BaseOne::SimpleFunc(); // BaseOneŬ������ ����Լ�
		BaseTwo::SimpleFunc(); // BaseTwoŬ������ ����Լ�
	}
};

int main() {
	Derived obj;
	obj.Func();

	return 0;
}