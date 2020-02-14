#include <iostream>
using namespace std;

class A {
private:
	int height;
public:
	A(int h) :height(h){}

	int GetHeight() const{
		return height;
	}
};

class B : public A {
private:
	int weight;
public:
	B(int h, int w) :A(h), weight(w) {};

	int GetHeight() const {
		return 1;
	}
};

class Control {
private:
	A* people[100];
	int cnt;
public:
	Control():cnt(0){}

	void Add(A* person) {
		people[cnt++] = person;
	}

	void SumHeight() {
		int sum = 0;
		for(int i=0; i<cnt;i++){
			sum += people[i]->GetHeight();
		}
		
		cout << "sum: " << sum << endl;
	}

	~Control() {
		for (int i = 0; i < cnt; i++) {
			delete people[i];
		}
	}


};

int main(void) {

	Control control;

	control.Add(new A(10));
	control.Add(new B(20, 30));

	control.SumHeight(); // 무조건 A 클래스의 GetHeight() 호출 
						 // 포인터연산의 기준은 포인터 타입!

}