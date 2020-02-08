#include <iostream>
using namespace std;

class SinivelCap {
public:
	void Take() const {
		cout << "콧물이 멈춰요" << endl;
	}
};

class SneezeCap {
public:
	void Take() const {
		cout << "재채기가 멈춰요" << endl;
	}
};

class SnuffCap {
public:
	void Take() const {
		cout << "코막힘이 뚫려요" << endl;
	}
};

// 관련있는 변수와 함수를 하나의 클래스 안에 묶는 것 -> 캡슐화
// 캡슐화는 어려운 개념이다. 왜냐하면 캡슐화의 범위를 결정하는 일이 쉽지 않기 때문이다.

class Cold {
private:
	SinivelCap sinivel;
	SneezeCap sneeze;
	SnuffCap snuff;
public:
	void Take() const {
		sinivel.Take();
		sneeze.Take();
		snuff.Take();
	}
};

class ColdPatient {
public:
	void TakeMedicine(Cold& cold) const{
		cold.Take();
	}
};

int main(void) {

	Cold medicine;
	ColdPatient hyoeun;
	hyoeun.TakeMedicine(medicine);

	return 0;
}