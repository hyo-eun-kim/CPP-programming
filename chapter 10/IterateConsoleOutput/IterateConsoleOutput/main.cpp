#include <iostream>

namespace mystd {

	class ostream {
	public:
		ostream& operator<<(const char* str) {
			printf("%s", str);
			return *this;
		}

		ostream& operator<<(char ch) {
			printf("%c", ch);
			return *this;
		}

		ostream& operator<<(int n) {
			printf("%d", n);
			return *this;
		}
		
		ostream& operator<<(double d) {
			printf("%lf", d);
			return *this;
		}

		void operator<<(ostream& (*p)(ostream& obj)) {
			p(*this);
		}
	};

	ostream& endl(ostream& obj) {
		obj << "\n";
		fflush(stdout);
		return obj;
	}

	ostream cout;
}

int main(void) {

	using mystd::cout;
	using mystd::endl;

	cout << 3.14 << " " << 123 << endl;
	cout << "Hello " << 20200218 << endl;

	return 0;
}