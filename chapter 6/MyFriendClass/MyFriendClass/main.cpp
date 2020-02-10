#define _CRT_SECURE_NO_WARNINGS
#include <cstring>
#include <iostream>
using namespace std;

class Girl {
private:
	friend class Boy; // ���� Girl Ŭ���� ���ο��� Boy�� private ������� ���� ����
	char phNum[20];
public:
	Girl(const char* num) {
		strcpy(phNum, num);
		cout << "Girl ����" << endl;
	}
	void ShowYourFriendInfo(const Boy& frn);
};

class Boy {
private:
	int height;
public:
	Boy(int h) :height(h) {
		cout << "Boy ����" << endl;
	};
	void ShowYourFriendInfo(const Girl& frn);
	friend class Girl; // Boy Ŭ���� ������ Girl Ŭ������ ������� ���� ����
};

// Boy Ŭ������ height ��������� ���翡 ���ؼ� �˾ƾ� �ϹǷ�
// Boy Ŭ���� ���� �ڿ� �Լ� ����
void Girl::ShowYourFriendInfo(const Boy& frn) {
	cout << "His Height: " << frn.height << endl;
}

// Girl Ŭ������ phNum ��������� ���翡 ���ؼ� �˾ƾ� �ϹǷ�
// Girl Ŭ���� ���� �ڿ� �Լ� ����
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