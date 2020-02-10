#include <iostream>
using namespace std;

class SoSimple {
private:
	int num;
public:
	// ������
	SoSimple(int n) :num(n) {};

	void SimpleFunc() {
		cout << "SimpleFunc: " << num << endl;
	}

	// const Ű���带 ���̴� �͵� �Լ� �����ε� �� �ϳ�!
	// (+������ ������Ÿ���̳� ������ ���� �ٲٴ� ���� ����)
	void SimpleFunc() const {
		cout << "const SimpleFunc: " << num << endl;
	}
};

// const ��ü�� �ޱ� ������ const ����Լ��� ȣ���ϰ� �ȴ�.
void YourFunc(const SoSimple& obj) {
	obj.SimpleFunc();
}

int main(void) {

	SoSimple obj1(2);
	const SoSimple obj2(7); // const ��ü

	obj1.SimpleFunc(); // �׳� ����Լ� ȣ��
	obj2.SimpleFunc(); // const ����Լ� ȣ��

	YourFunc(obj1); // const ����Լ� ȣ��
	YourFunc(obj2); // const ����Լ� ȣ��

	return 0;
}