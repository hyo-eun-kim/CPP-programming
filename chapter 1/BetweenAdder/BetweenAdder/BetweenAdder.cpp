#include <iostream>

int main(void) {

	// 두 숫자를 입력받아 두 수 사이에 존재하는 정수들의 합을 계산하여 출력

	int val1, val2;
	std::cout << "두 개의 숫자입력: ";
	std::cin >> val1 >> val2; 
	// 스페이스, 탭, 엔터 입력을 기준으로 구분되어 저장
	// 첫 번째 입력은 val1에, 두 번째 입력은 val2에 저장된다

	int sum = 0;
	if (val1 < val2) 
	{
		for (int i = val1 + 1; i < val2; i++)
			sum += i;
	}
	else
	{
		for (int i = val2 + 1; i < val1; i++)
			sum += i;
	}

	std::cout << "두 수 사이의 정수 합: " << sum << std::endl;
	return 0;
}