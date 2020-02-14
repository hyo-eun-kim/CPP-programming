#include <iostream>
using namespace std;

class BaseOne {
private:
	int num;
public:
	void SimpleFuncOne() {
		cout << "BaseOne" << endl;
	}
};

class BaseTwo {
private:
	int num;
public:
	void SimpleFuncTwo() {
		cout << "BaseTwo" << endl;
	}
};

// �� �� �̻��� Ŭ������ ����ϴ� -> ���߻��
class Derived : public BaseOne, public BaseTwo{
private:
	int num;
public:
	void SimpleFunc() {
		SimpleFuncOne(); // BaseOneŬ������ ����Լ�
		SimpleFuncTwo(); // BaseTwoŬ������ ����Լ�
	}
};

int main() {
	Derived obj;
	obj.SimpleFunc();

	return 0;
}