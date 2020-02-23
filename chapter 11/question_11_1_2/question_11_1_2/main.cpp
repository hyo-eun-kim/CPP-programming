#include <cstring>
#include <iostream>
using namespace std;

class Book {
private:
	char* title;
	char* isbn;
	int price;
public:

	Book() {
		title = NULL;
		isbn = NULL;
		price = 0;
	}

	Book(const char* title, const char* isbn, int price)
		:price(price) {
		this->title = new char[strlen(title) + 1];
		strcpy_s(this->title, strlen(title)+1, title);

		this->isbn = new char[strlen(isbn) + 1];
		strcpy_s(this->isbn, strlen(isbn)+1, isbn);
	}

	Book(const Book& book) {
		
		cout << "*************** ����Ŭ������ ��������� ȣ�� ***************" << endl;
		title = new char[strlen(book.title) + 1];
		strcpy_s(title, strlen(book.title) + 1, book.title);

		isbn = new char[strlen(book.isbn) + 1];
		strcpy_s(isbn, strlen(book.isbn) + 1, book.isbn);

		price = book.price;
	}

	Book& operator=(const Book& book) {
		// �޸� ���� ����
		delete[] title;
		delete[] isbn;

		title = new char[strlen(book.title) + 1];
		strcpy_s(title, strlen(book.title) + 1, book.title);

		isbn = new char[strlen(book.isbn) + 1];
		strcpy_s(isbn, strlen(book.isbn) + 1, book.isbn);
		price = book.price;

		return *this;
	}

	void ChangeBookName(const char* bookTitle) {
		delete title;
		title = new char[strlen(bookTitle) + 1];
		strcpy_s(title, strlen(bookTitle) + 1, bookTitle);
	}

	void ShowBookInfo()const {
		cout << "����: " << title << endl;
		cout << "ISBN: " << isbn << endl;
		cout << "����: " << price << endl;
	}

	~Book() {
		delete[] title;
		delete[] isbn;
	}
};

class Ebook : public Book{
private:
	char* DRMKey;
public:

	Ebook() {
		DRMKey = NULL;
	}

	Ebook(const char* title, const char* isbn, int price, const char* DRMKey)
		:Book(title, isbn, price) {

		this->DRMKey= new char[strlen(DRMKey) + 1];
		strcpy_s(this->DRMKey, strlen(DRMKey)+1, DRMKey);
	}

	// ���������
	// ���⼭ ����Ŭ�������� �������� ��� �Ǵ°���?
	Ebook(const Ebook& ebook):Book(ebook) {
		cout << "*************** ����Ŭ������ ��������� ȣ�� ***************" << endl;
		// ������ Book�� ��������ڿ� ebook ��ü�� �Ѱ��־� ��������� ȣ��
		DRMKey = new char[strlen(ebook.DRMKey) + 1];
		strcpy_s(DRMKey, strlen(ebook.DRMKey) + 1, ebook.DRMKey);
	}

	// ���Կ����� �����ε�
	Ebook& operator=(const Ebook& ebook) {
		// ����Ŭ�������� ���Կ����ڸ� ������ ���, ����Ŭ������ ���Կ����� ȣ���� ������־�� ��
		Book::operator=(ebook); 

		delete[] DRMKey;
		DRMKey = new char[strlen(ebook.DRMKey) + 1];
		strcpy_s(DRMKey, strlen(ebook.DRMKey) + 1, ebook.DRMKey);

		return *this;
	}

	void ChangeDRMKey(const char* drmkey) {
		delete DRMKey;
		DRMKey = new char[strlen(drmkey) + 1];
		strcpy_s(DRMKey, strlen(drmkey) + 1, drmkey);
	}

	~Ebook() {
		delete[] DRMKey;
	}

	void ShowBookInfo() {
		Book::ShowBookInfo();
		cout << "����Ű: " << DRMKey << endl;
	}
};

int main(void) {

	Book book1("C++", "100-12345", 23000);
	Book book2 = book1; // ���������
	Book book3;

	book1.ChangeBookName("Python");
	book1.ShowBookInfo(); // Python
	book2.ShowBookInfo(); // C++

	book3 = book2; // ���Կ�����
	book2.ChangeBookName("Java");
	book2.ShowBookInfo(); // Java
	book3.ShowBookInfo(); // C++

	cout << "========================================================================" << endl;

	Ebook ebook1("C++", "100-12345", 23000, "aaa123bbb");
	Ebook ebook2 = ebook1;
	Ebook ebook3;

	ebook1.ShowBookInfo();
	ebook2.ShowBookInfo();

	ebook1.ChangeBookName("Python");
	ebook1.ShowBookInfo(); // python
	ebook2.ShowBookInfo(); // C++
	cout << "--------------------" << endl;

	ebook1.ChangeDRMKey("ccc78999");
	ebook1.ShowBookInfo(); // ccc78999
	ebook2.ShowBookInfo(); // aaa123bbb
	cout << "--------------------" << endl;

	ebook3 = ebook1;
	ebook1.ShowBookInfo(); // python
	ebook3.ShowBookInfo(); // python
	cout << "--------------------" << endl;

	ebook1.ChangeBookName("JAVA");
	ebook1.ShowBookInfo(); // JAVA
	ebook3.ShowBookInfo(); // python
	cout << "--------------------" << endl;

	ebook1.ChangeDRMKey("ddd0000");
	ebook1.ShowBookInfo(); // ddd0000
	ebook3.ShowBookInfo(); // ccc78999
	cout << "--------------------" << endl;

	return 0;

}