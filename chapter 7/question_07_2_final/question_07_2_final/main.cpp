#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
using namespace std;


// 책을 의미하는 Book 클래스
// 전자책을 의미하는 Ebook 클래스
// Ebook은 Book의 일종 (Ebook is a Book)


class Book {
private:
	char* title;
	char* isbn;
	int price;
public:
	Book(const char* title, const char* isbn, int price)
		:price(price) {
		this->title = new char[strlen(title) + 1];
		this->isbn = new char[strlen(isbn) + 1];

		strcpy(this->title, title);
		strcpy(this->isbn, isbn);
	}

	void ShowBookInfo() {
		cout << "제목: " << title << endl;
		cout << "ISBN: " << isbn << endl;
		cout << "가격: " << price << endl;
	}

	~Book() {
		delete[] title;
		delete[] isbn;
	}
};

class Ebook : public Book {
private:
	char* DRMKey; // 보안관련 키
public:
	Ebook(const char* title, const char* isbn, int price, const char* DBMKey)
		:Book(title, isbn, price) {
		this->DRMKey = new char[strlen(DBMKey) + 1];
		strcpy(this->DRMKey, DBMKey);
	}

	void ShowEbookInfo() {
		ShowBookInfo();
		cout << "인증키: " << DRMKey << endl;
	}

	~Ebook() {
		delete[] DRMKey;
	}
};

int main(void) {

	Book book("좋은 C++", "555-12345-890-0", 20000);
	book.ShowBookInfo();

	cout << endl;

	Ebook ebook("좋은 C++ ebook", "555-12345-890-1", 10000, "fdx9w0i8kiw");
	ebook.ShowEbookInfo();

	return 0;

}