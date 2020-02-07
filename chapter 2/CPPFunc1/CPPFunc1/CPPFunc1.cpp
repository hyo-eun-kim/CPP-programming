#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
using namespace std;

int main(void) {

	char name1[] = "hyoeun";

	for (int i = 0; i < strlen(name1); i++) {
		cout << name1[i] << endl;
	}
	
	char name2[10];
	
	strcpy(name2, "hyow");
	strcat(name2, "on");
	
	if (strcmp(name1, name2) == 0) {
		cout << "Same!" << endl;
	}
	else {
		cout << "Different!" << endl;
	}

	return 0;
}