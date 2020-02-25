#include <iostream>
using namespace std;

class Number {
private:
	int num;
public:
	Number(int n=0) :num(n) {
		cout << "Constructor" << endl;
	};

	void operator=(const Number& number) {
		cout << "operator=()" << endl;
		num = number.num;
	}

	void Show() {
		cout << num << endl;
	}
};

int main() {
	Number num;
	num = 30;
	num.Show();
	return 0;
}