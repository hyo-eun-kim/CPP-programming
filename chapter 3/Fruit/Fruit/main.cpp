#include <iostream>
using namespace std;

typedef struct Deal {
	int change;
	int apple;
} Deal;


class FruitSeller {
private:
	int APPLE_PRICE;
	int myApple;
	int myMoney;
public:
	void Init(int price, int apple, int money) {
		APPLE_PRICE = price;
		myApple = apple;
		myMoney = money;
	}
	Deal saleApple(int money) {
		Deal deal;
		int num = money / APPLE_PRICE;

		myApple -= num;
		myMoney += (num * APPLE_PRICE);
		deal.apple = num;
		deal.change = (money - (APPLE_PRICE * num));
		return deal;
	}
	void showResult() {
		cout << "[seller] ���� ���: " << myApple << endl;
		cout << "[seller] �Ǹ� ����: " << myMoney << endl;
		cout << endl;
	}
};

class FruitBuyer {
private:
	int myApple;
	int myMoney;
public:
	void Init(int apple, int money) {
		myApple = apple;
		myMoney = money;
	}
	void buyApple(FruitSeller& seller, int money) {
		Deal deal;
		deal = seller.saleApple(money);
		myApple += deal.apple;
		myMoney -= money;
		myMoney += deal.change;
	}
	void showResult() {
		cout << "[buyer] ���� ���: " << myApple << endl;
		cout << "[buyer] ���� �ܵ�: " << myMoney << endl;
		cout << endl;
	}
};

int main(void) {

	FruitBuyer* hyojin = new FruitBuyer;
	FruitSeller* hyoeun = new FruitSeller;

	hyoeun->Init(500, 20, 10000);
	hyojin->Init(0, 10000);

	hyojin->buyApple(*hyoeun, 1700); 
	hyojin->showResult(); // ��� 3�� �ܵ� 8500
	hyoeun->showResult(); // ��� 17�� �ܵ� 11500

	hyojin->buyApple(*hyoeun, 2300);
	hyojin->showResult(); // ��� 7�� �ܵ� 6500
	hyoeun->showResult(); // ��� 13�� �ܵ� 13500

	return 0;
}