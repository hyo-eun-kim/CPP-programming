#include <iostream>


namespace mystd {
	using namespace std;

	class ostream {
	public:

		void operator<<(const char* str) {
			printf("%s", str);
		}

		void operator<<(char ch) {
			printf("%c", ch);
		}

		void operator<<(int num) {
			printf("%d", num);
		}

		void operator<<(double e) {
			printf("%g", e);
		}

		// 함수포인터
		void operator<<(ostream&(*p)(ostream& obj)) {
			p(*this);
		}
	};

	ostream& endl(ostream& obj) {
		cout << "\n"; // obj.operator<<("\n"); 실행과 동일
		fflush(stdout); // 버퍼를 지운다
		return obj;
	}

	// ostream 클래스의 cout 객체
	ostream cout;

}

int main(void) {

	using mystd::cout; // namespace mystd 안의 class ostream의 cout 객체
	using mystd::endl; // namespace mystd 안의 endl 전역함수

	cout << "Simple String";
	cout << endl;
	cout << 3.14;
	cout << endl;
	cout << 123;
	cout << endl;

	endl(cout);

}