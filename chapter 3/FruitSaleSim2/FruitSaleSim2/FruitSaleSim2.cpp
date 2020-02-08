#include <iostream>
using namespace std;

struct Exchange {
	int exchange;
	int apple;
};

class FruitSeller {
private:
	int APPLE_PRICE;
	int myApple;
	int myMoney;
public:
	FruitSeller(int price, int money, int apple) {
		APPLE_PRICE = price;
		myMoney = money;
		myApple = apple;
	}
	Exchange SaleApple(int money) {
		int apple = money / APPLE_PRICE;
		myApple -= apple;
		myMoney += (apple * APPLE_PRICE);

		Exchange exchange = { money - apple * APPLE_PRICE, apple };
		return exchange;
	}
	void Show() const{
		cout << "[판매자] 사과: " << myApple << endl;
		cout << "[판매자] 현금: " << myMoney << endl;
		cout << endl;
	}
};

class FruitBuyer {
private:
	int myApple;
	int myMoney;
public:
	FruitBuyer(int money, int apple=0) {
		myMoney = money;
		myApple = apple;
	}
	void BuyApple(FruitSeller& seller, int money) {
		Exchange exchange;
		exchange = seller.SaleApple(money);
		myApple += exchange.apple;
		myMoney -= money;
		myMoney += exchange.exchange;
	}
	void Show() const{
		cout << "[구매자] 사과: " << myApple << endl;
		cout << "[구매자] 현금: " << myMoney << endl;
		cout << endl;
	}
};

int main(void) {

	FruitSeller seller(1000, 0, 20);
	FruitBuyer buyer(5000);

	buyer.BuyApple(seller, 2000);

	seller.Show();
	buyer.Show();

	return 0;
}