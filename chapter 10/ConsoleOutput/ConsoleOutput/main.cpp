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

		// �Լ�������
		void operator<<(ostream&(*p)(ostream& obj)) {
			p(*this);
		}
	};

	ostream& endl(ostream& obj) {
		cout << "\n"; // obj.operator<<("\n"); ����� ����
		fflush(stdout); // ���۸� �����
		return obj;
	}

	// ostream Ŭ������ cout ��ü
	ostream cout;

}

int main(void) {

	using mystd::cout; // namespace mystd ���� class ostream�� cout ��ü
	using mystd::endl; // namespace mystd ���� endl �����Լ�

	cout << "Simple String";
	cout << endl;
	cout << 3.14;
	cout << endl;
	cout << 123;
	cout << endl;

	endl(cout);

}