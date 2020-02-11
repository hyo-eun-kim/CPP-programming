#include <iostream>
using namespace std;

class Person {
public:
	void Sleep() {
		cout << "Sleep" << endl;
	}
};

class Student : public Person {
public:
	void Study() {
		cout << "Study" << endl;
	}
};

class HighSchoolStudent : public Student {
public:
	void Exam() {
		cout << "Su-neung" << endl;
	}
};

int main(void) {

	Person* person1 = new HighSchoolStudent();
	Person* person2 = new Student;
	Student* person3 = new HighSchoolStudent;

	person1->Sleep(); // 왜 Sleep만 가능?
	person2->Sleep(); // 왜 Sleep만 가능?
	person3->Sleep(); 
	person3->Study();

	return 0;
}