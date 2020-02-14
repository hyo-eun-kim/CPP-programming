#include <iostream>
using namespace std;

class First {
private:
public:
	void FirstFunc() {
		cout << "FirstFunc()" << endl;
	}
	virtual void SimpleFunc() {
		cout << "First's SimpleFunc" << endl;
	}
};

class Second : public First {
private:
public:
	void SecondFunc() {
		cout << "SecondFunc()" << endl;
	}
	virtual void SimpleFunc() {
		cout << "Second's SimpleFunc" << endl;
	}
};

class Third : public Second{
private:
public:
	void ThirdFunc() {
		cout << "ThirdFunc()" << endl;
	}
	virtual void SimpleFunc() {
		cout << "Third's SimpleFunc" << endl;
	}
};


int main(void) {

	Third obj;
	obj.FirstFunc();	// ThirdŬ������ FirstŬ������ �������
	obj.SecondFunc();	// ThirdŬ������ SecondŬ������ �������
	obj.ThirdFunc();	// ThirdŬ������ ����Լ�
	obj.SimpleFunc();	// �����ǵ� �����Լ�

	Second& sref = obj;
	sref.FirstFunc();	
	sref.SecondFunc();
	sref.SimpleFunc();	// SimpleFunc()�� �����Լ��̱� ������ ���������� ���� �Լ��� ȣ���ϴ� �� �ƴ϶�
						// sref�� � ��ü�� �����ϰ� �ִ��Ŀ� ���� �Լ� ȣ��!
	
	First& fref = obj;
	fref.FirstFunc();	// SecondŬ����, ThirdŬ������ ������� ���� �Ұ�! (First�� reference�̱� ������)
	fref.SimpleFunc();	// SImpleFunc�� �����Լ��̱� ������ �����ϰ� �ִ� ThirdŬ���� ��ü�� ��������� ���� ����!
}