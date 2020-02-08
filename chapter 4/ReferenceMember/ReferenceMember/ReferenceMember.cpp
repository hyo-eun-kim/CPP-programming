#include <iostream>
using namespace std;

// ��� �̴ϼȶ������� ����ϸ� ��������� ����� ���ÿ� �ʱ�ȭ�Ǵ� �Ͱ� �����ϴ�.
// ���� ����� ���ÿ� �ʱ�ȭ �Ǿ�� �ϴ� const ������ reference�� 
// ��� �̴ϼȶ������� ����ϸ� Ŭ������ ��������� ����� �� �ְ� �Ǵ� ���̴�.

// �Ʒ� �ڵ�� reference(������)�� Ŭ������ ��������� ����� �����̴�.
// �ڵ忡�� Ȯ���� �� �ֵ��� ��� �̴ϼȶ������� ���� �����ڸ� ����� ���ÿ� �ʱ�ȭ�ϰ� �ִ�.

class AAA {
public:
	AAA() {
		cout << "empty object" << endl;
	}
	void Show() {
		cout << "class AAA" << endl;
	}
};

class BBB {
private:
	AAA& ref;
	const int& num;
public:
	BBB(AAA& r, const int& n)
		: ref(r), num(n) {

	}
	void Show() {
		ref.Show();
		cout << "and" << endl;
		cout << "I ref num " << num << endl;
	}
};

int main(void) {

	AAA aaa;
	BBB bbb(aaa, 5);
	bbb.Show();

	return 0;
}