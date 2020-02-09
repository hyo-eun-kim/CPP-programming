#include <iostream>
using namespace std;

class SoSimple {
private:
	int num;
public:
	SoSimple(int num) :num(num) {};
	SoSimple(const SoSimple& copy) :num(copy.num) {
		cout << "called SoSimple(const SoSimple& copy)" << endl;
	};
	void Show() const {
		cout << "num: " << num << endl;
	}
};

int main(void) {

	SoSimple sp1(7);
	SoSimple sp2 = sp1; // 매개변수에 객체 전달되며 복사생성자 호출
	sp2.Show();

	return 0;
}