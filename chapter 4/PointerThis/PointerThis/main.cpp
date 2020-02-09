#include <iostream>
using namespace std;

class Simple {
private:
	int num;
public:
	Simple(int myNum)
		:num(myNum) {
		cout << "num=" << num << ", ";
		cout << "address=" << this << endl;
	};
	Simple* GetThisPointer(){
		return this;
	}
	void ShowSimpleData() const{
		cout << num << endl;
	}
};



int main(void) {
	Simple sim1(100);
	Simple* ptr1 = sim1.GetThisPointer();
	cout << ptr1 << ", ";
	ptr1->ShowSimpleData();

	Simple sim2(200);
	Simple* ptr2 = sim2.GetThisPointer();
	cout << ptr2 << ", ";
	ptr2->ShowSimpleData();

	return 0;
}