#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cmath>
#include <cstring>
#include <cstdio>

// C++에서 C언어의 표준함수 호출하기 (.h를 빼고 앞에 C를 붙여라!)
// #include <stdio.h> -> #include <cstdio>
// #include <string.h> -> #include <cstring>

int main(void) {
	char str1[] = "Result";
	char str2[30];

	strcpy(str2, str1);
	printf("%s: %f \n", str1, sin(0.14));
	printf("%s: %f \n", str2, abs(-1.25));
	
	return 0;
}