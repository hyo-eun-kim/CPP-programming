#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string.h>
#include <stdlib.h>

using namespace std;

// C������ �����Ҵ�
char* MakeStrAdr1(int len) {

	// ��ȯ���� void �����Ͷ� char�� �����ͷ� ����ȯ
	char* str = (char*)malloc(sizeof(char) * len);
	return str;
}

char* MakeStrAdr2(int len) {
	char* str = new char[len];
	return str;
}

int main(void) {

	char* str1 = MakeStrAdr1(20);
	strcpy(str1, "I am so happy");
	cout << str1 << endl;
	free(str1);

	char* str2 = MakeStrAdr2(20);
	strcpy(str2, "I am so hungry");
	cout << str2 << endl;
	delete []str2;

	return 0;
}
