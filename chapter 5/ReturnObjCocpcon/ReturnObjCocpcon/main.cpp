#include <iostream>
using namespace std;

class SoSimple {
private:
	int num;
public:
	// 생성자
	SoSimple(int num) :num(num) {
	};

	SoSimple& AddNum(int val) {
		num += val;
		return *this;
	}

	void Show() const {
		cout << "num: " << num << endl;
	}
};

SoSimple SimpleFuncObj(SoSimple simple) {
	return simple; // simple 객체의 복사본(=임시객체)이 만들어지면서 반환 
}


int main(void) {
	SoSimple obj(7);
	SimpleFuncObj(obj).AddNum(30).Show(); // 37
	obj.Show(); // 7
	return 0;
}