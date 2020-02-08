#include <iostream>
using namespace std;

typedef struct Interchange {
	int change;
	int apple;
} Interchange;

class FruitSeller {
private:
	int APPLE_PRICE;
	int myApple;
	int myMoney;
public:
	bool Init(int price, int apple, int money) {
		if ((price < 0) || (apple < 0) || (money < 0)) {
			cout << "������ ������ϴ�." << endl;
			return false;
		}
		else {
			APPLE_PRICE = price;
			myApple = apple;
			myMoney = money;
			return true;
		}
		
	}
	Interchange SaleApple(int price) {
		Interchange interchange;
		int apple = price / APPLE_PRICE;
		int change = price - (APPLE_PRICE * apple);
		myMoney += (APPLE_PRICE * apple);
		myApple -= apple;

		interchange.change = change;
		interchange.apple = apple;
		return interchange;
	}

	void Show() const{
		cout << "[�ǸŻ�] ���: " << myApple << endl;
		cout << "[�ǸŻ�] ����: " << myMoney << endl;
		cout << endl;
	}
};

class FruitBuyer {
private:
	int myApple;
	int myMoney;
public:
	bool Init(int apple, int money) {
		if ((apple < 0) || (money < 0)) {
			cout << "������ ������ϴ�." << endl;
			return false;
		}
		else {
			myApple = apple;
			myMoney = money;
			return true;
		}
	}

	void BuyApple(FruitSeller& seller, int money) {
		Interchange interchange;
		interchange = seller.SaleApple(money);
		myApple += interchange.apple;
		myMoney -= money;
		myMoney += interchange.change;
	}

	void Show() const{
		cout << "[������] ���: " << myApple << endl;
		cout << "[������] ����: " << myMoney << endl;
		cout << endl;
	}

};

int main(void) {

	FruitSeller changhun;
	FruitBuyer hyoeun;


	if (!changhun.Init(1000, -20, 15000)) {
		cout << "�����߻�" << endl; // �����߻� ���
	};

	if (!changhun.Init(1000, 20, 15000)) {
		cout << "�����߻�" << endl; // �����߻� ��� X
	};

	if (!hyoeun.Init(0, 20000)) {
		cout << "�����߻�" << endl; // �����߻� ��� X
	}

	hyoeun.BuyApple(changhun, 2500);
	changhun.Show(); // ��� 18 �� 17000
	hyoeun.Show(); // ��� 2 �� 18000

	hyoeun.BuyApple(changhun, 3700);
	changhun.Show(); // ��� 15 �� 20000
	hyoeun.Show(); // ��� 5 �� 15000

	return 0;
}