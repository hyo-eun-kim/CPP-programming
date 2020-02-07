#include <iostream>


// 함수 오버로딩
// 함수명 동일하나, 매개변수의 정보(수, 자료형)가 다른 경우
// (단, return type은 동일해야 한다.

void swap(int* num1, int* num2) {
	int tmp;
	tmp = *num1;
	*num1 = *num2;
	*num2 = tmp;
}

void swap(char* ch1, char* ch2) {
	char tmp;
	tmp = *ch1;
	*ch1 = *ch2;
	*ch1 = tmp;
}

void swap(double* num1, double* num2) {
	double tmp;
	tmp = *num1;
	*num1 = *num2;
	*num2 = tmp;
}



int main(void) {
	
	int num1 = 20, num2 = 30;
	swap(&num1, &num2);
	std::cout << num1 << " " << num2 << std::endl;

	char ch1 = 'A', ch2 = 'Z';
	swap(&ch1, &ch2);
	std::cout << ch1 << ' ' << ch2 << std::endl;

	double dbl1 = 1.111, dbl2 = 5.555;
	swap(&dbl1, &dbl2);
	std::cout << dbl1 << ' ' << dbl2 << std::endl;

	return 0;
}