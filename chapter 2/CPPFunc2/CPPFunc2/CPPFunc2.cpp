#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

// rand, srand, time 함수를 이용해 0이상 100미만의 난수를 10개 생성하는 예제

int main(void) {

	
	srand(time(NULL));
	
	for (int i = 0; i < 10; i++) {
		cout << rand()%100 << endl;
	}
	
	return 0;
}