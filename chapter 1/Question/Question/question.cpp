#include <iostream>

int q1(void);
int q2(void);
int q3(void);
int q4(void);

int main(void) {

	q1();
	q2();
	q3();
	q4();

	return 0;
}

int q1(void) {

	// 사용자로부터 5개의 정수를 입력받아서 그 합을 출력

	int sum = 0, input;
	for (int i = 0; i < 5; i++) {
		std::cout << i+1 << "번째 정수 입력: ";
		std::cin >> input;
		sum += input;
	}

	std::cout << "합계: " << sum << std::endl;

	return 0;
}

int q2(void) {

	// 사용자로부터 이름과 전화번호를 문자열의 형태로 입력 받아
	// 입력받은 데이터를 그대로 출력하는 프로그램

	char name[100];
	char phone[100];

	std::cout << "이름과 전화번호를 입력해주세요 > ";
	std::cin >> name >> phone;

	std::cout << name << "님의 핸드폰 전화번호는 " << phone << "입니다. " << std::endl;
	return 0;
}

int q3(void) {

	// 숫자 하나를 입력받아서 그 숫자에 해당하는 구구단 출력

	int num;
	std::cout << "몇 단을 출력할까요? ";
	std::cin >> num;

	for (int i = 1; i <= 9; i++) {
		std::cout << num << " * " << i << " = " << num * i << std::endl;
	}

	return 0;
}

int q4(void) {

	// 매달 50만원의 기본 급여와 물품 판매 가격의 12%에 해당하는 돈을 지급
	int sales;
	std::cout << "판매 금액을 만원 단위로 입력(-1 to end): ";
	std::cin >> sales;
	if (sales != -1){
		while (sales != -1) {
			std::cout << "이번 달 급여: " << 50 + sales * 0.12 << "만원" << std::endl;
			std::cout << "판매 금액을 만원 단위로 입력(-1 to end): ";
			std::cin >> sales;
		}
	}
	std::cout << "프로그램을 종료합니다." << std::endl;

	return 0;
}