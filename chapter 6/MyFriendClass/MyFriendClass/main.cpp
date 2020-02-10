#define _CRT_SECURE_NO_WARNINGS
#include <cstring>
#include <iostream>
using namespace std;

class Girl {
private:
	friend class Boy; // 이제 Girl 클래스 내부에서 Boy의 private 멤버변수 접근 가능
	char phNum[20];
public:
	Girl(const char* num) {
		strcpy(phNum, num);
		cout << "Girl 생성" << endl;
	}
	void ShowYourFriendInfo(const Boy& frn);
};

class Boy {
private:
	int height;
public:
	Boy(int h) :height(h) {
		cout << "Boy 생성" << endl;
	};
	void ShowYourFriendInfo(const Girl& frn);
	friend class Girl; // Boy 클래스 내에서 Girl 클래스의 멤버변수 접근 가능
};

// Boy 클래스의 height 멤버변수의 존재에 대해서 알아야 하므로
// Boy 클래스 선언 뒤에 함수 정의
void Girl::ShowYourFriendInfo(const Boy& frn) {
	cout << "His Height: " << frn.height << endl;
}

// Girl 클래스의 phNum 멤버변수의 존재에 대해서 알아야 하므로
// Girl 클래스 선언 뒤에 함수 정의
void Boy::ShowYourFriendInfo(const Girl& frn) {
	cout << "Her PhoneNum: " << frn.phNum << endl;
}

int main(void) {
	Girl girl("010-1111-2222");
	Boy boy(178);

	girl.ShowYourFriendInfo(boy);
	boy.ShowYourFriendInfo(girl);

	return 0;
}