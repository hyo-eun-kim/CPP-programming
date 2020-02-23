#include <iostream>
using namespace std;

class First {
private:
	int num1, num2;
public:
	First(int n1=0, int n2=0)
		:num1(n1), num2(n2){}

	void ShowData() {
		cout << num1 << ", " << num2 << endl;
	}
};

class Second {
private:
	int num3, num4;
public:
	Second(int n3=0, int n4=0)
		:num3(n3), num4(n4){}
	void ShowData() {
		cout << num3 << ", " << num4 << endl;
	}
	// 대입연산자 오버로딩
	Second& operator=(Second& sec) {
		num3 = sec.num3;
		num4 = sec.num4;
		return *this;
	}
};

int main() {
	First first1(10, 20);
	First first2;

	first2 = first1;	// first2.operator=(first1); default 대입연산자
	first1.ShowData();	// 10, 20
	first2.ShowData();	// 10, 20

	Second second1(35, 40);
	Second second2;
	second2 = second1; // second2.operator=(second1); 오버라이딩된 대입연산자
	second1.ShowData();// 35, 40
	second2.ShowData();// 35, 40
}