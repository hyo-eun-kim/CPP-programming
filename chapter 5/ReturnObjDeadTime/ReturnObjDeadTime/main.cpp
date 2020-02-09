#include <iostream>
using namespace std;

class SoSimple {
private:
	int num;
public:
	SoSimple(int num) :num(num) {
		cout << "New Object: " << this << endl;
	}
	
	SoSimple(const SoSimple& copy) :num(copy.num) {
		cout << "New Copy Object: " << this << endl;
	}

	~SoSimple() {
		cout << "Destroy Obj: " << this << endl;
	}
};

SoSimple SimpleFuncObj(SoSimple obj) {
	cout << "Parm ADR: " << &obj << endl;
	return obj;
}

int main(void) {
	SoSimple obj(7); // New Object
	SimpleFuncObj(obj); // New Copy Object
	// Destroy

	cout << endl;
	SoSimple tempRef = SimpleFuncObj(obj); // New Copy Object
	cout << "Return Obj" << &tempRef << endl;
	return 0;
}