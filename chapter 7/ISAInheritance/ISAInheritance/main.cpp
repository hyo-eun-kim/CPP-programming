#define _CRT_SECURE_NO_WARNINGS
#include <cstring>
#include <iostream>
using namespace std;

class Computer {
private:
	char owner[50];
public:
	Computer(const char* name) {
		strcpy(owner, name);
	}
	void Calculate() {
		cout << "����մϴ�" << endl;
	}
};

class Notebook : public Computer {
private:
	int battery;
public:
	Notebook(const char* name, int battery_val)
		:Computer(name), battery(battery_val){}
	void Charging() {
		battery += 5;
	}
	void UseBattery() {
		battery -= 1;
	}
	int GetBattery() {
		return battery;
	}
	void Moving() {
		if (GetBattery() < 1) {
			cout << "������ �ʿ��մϴ�" << endl;
			return;
		}
		cout << "�̵��ϸ鼭 ";
		Calculate();
		UseBattery();
	}
};

class Tablet : public Notebook {
private:
	char* regstPenModel;
public:
	Tablet(const char* name, int battery_val, const char* model)
		:Notebook(name, battery_val) {
		regstPenModel = new char[strlen(model) + 1];
		strcpy(regstPenModel, model);
	}
	~Tablet() {
		delete[] regstPenModel;
	}
	void Write(const char* model) {
		if (GetBattery() < 1) {
			cout << "������ �ʿ��մϴ�" << endl;
			return;
		}
		if (strcmp(regstPenModel, model) != 0) {
			cout << "��ϵ� ���� �ƴմϴ�" << endl;
			return;
		}

		cout << "�ʱ��մϴ�" << endl;
		UseBattery();
	}
};


int main(void) {

	Tablet person1("juyeong", 4, "MA-995");

	person1.Calculate();
	person1.Moving(); // 3
	person1.Moving(); // 2
	person1.Write("MA-994");
	person1.Write("MA-995"); // 1
	person1.Moving(); // 0
	person1.Moving(); // �����ʿ�
	person1.Charging();

	return 0;
}