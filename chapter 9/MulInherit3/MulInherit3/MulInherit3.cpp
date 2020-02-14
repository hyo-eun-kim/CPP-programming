#include <iostream>
using namespace std;

class Base {
private:
	int age;
public:
	Base() {
		age = 0;
		cout << "기본생성자" << endl;
	}
	Base(int age):age(age){
		cout << "Base Consructor" << endl;
	}
	void getAge() {
		cout << "age: " << age << endl;
	}
};

class Middle1 : public Base {
private:
	int grade;
public:
	Middle1(int age, int grade) :Base(age), grade(grade) {
		cout << "Middle1 Contructor" << endl;
	}
	void getInfo1() {
		getAge();
		cout << "grade: " << grade << endl;
	}
};

class Middle2 : public Base {
private:
	int sex;
public:
	Middle2(int age, int sex):Base(age), sex(sex) {
		cout << "Middle2 Constructor" << endl;
	}
	void getInfo2() {
		getAge();
		cout << "sex: " << sex << endl;
	}
};

class Derived : public Middle1, public Middle2 {
private:
	int num;
public:
	Derived(int age, int grade, int sex, int num)
		:Middle1(age, grade), Middle2(age, sex), num(num){
		cout << "Derived Constructor" << endl;
	}

	void SimpleFunc() {
		getInfo1();
		getInfo2();
		Middle1::getAge();
		Middle2::getAge();

		cout << "num: " << num << endl;
	}

};

int main(void) {

	Derived obj(20, 5, 1, 2020);
	obj.SimpleFunc();


	return 0;
}