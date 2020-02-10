#include <iostream>
using namespace std;

class SoSimple {
private:
	int num;
public:
	SoSimple(int num) :num(num) {};

	void ShowData(void) const {
		cout << "num: " << num << endl;
	}

	SoSimple& AddNum(int val) {
		num += val;
		return *this;
	}

};

int main(void) {
	const SoSimple obj(7);
	obj.ShowData();
	return 0;
}