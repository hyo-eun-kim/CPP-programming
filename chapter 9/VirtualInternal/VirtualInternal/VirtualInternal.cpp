#include <iostream>
using namespace std;

// �����Լ��� ���ۿ���

class AAA {
private:
	int num;
public:
	virtual void Func1() {
		cout << "AAA::Func1()" << endl;
	}
};

class BBB : public AAA {
private:
	int num;
public: 
	virtual void Func1() {
		cout << "BBB::Func1()" << endl;
	}
};

// �����Լ�(virtual)�� Ŭ������ �ϳ� �̻� �����ϴ� ��� -> �����Լ� ���̺�(V-table)�� ���������.
// ����Լ��� ȣ���� �� �� V-table�� �����ϰ� �ȴ�.
// �� �� B Ŭ�������� �����Լ��� �������̵� �� ��� ����Ŭ����(A)�� �����Լ��� B Ŭ������ V-table�� ������� �ʴ´�.
// �Ʒ� �������� Ȯ���� �� �ֵ��� BBB Ŭ������ V-table���� AAA::Func1()�� ������ ����, �������̵� �� BBB::Func1()�� ������ �ִ�.
// ���� BBB ��ü�� �����ʹ� BBB::Func1()�� ȣ���ϴ� ���̴�.

int main(void) {
	AAA* a = new AAA();
	BBB* b = new BBB();

	a->Func1(); // AAA::Func1()
	b->Func1(); // BBB::Func1()

	return 0;
}