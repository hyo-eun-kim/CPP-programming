#include <iostream>
using namespace std;

class SoSimple {
private:
	int num;
public:
	// ������
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
	return simple; // simple ��ü�� ���纻(=�ӽð�ü)�� ��������鼭 ��ȯ 
}


int main(void) {
	SoSimple obj(7);
	SimpleFuncObj(obj).AddNum(30).Show(); // 37
	obj.Show(); // 7
	return 0;
}