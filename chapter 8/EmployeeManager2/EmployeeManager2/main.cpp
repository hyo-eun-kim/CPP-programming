#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
using namespace std;

class Employee {
private:
	char name[100];
public:
	Employee(const char* name) {
		strcpy(this->name, name);
	}

	void ShowYourName() const {
		cout << "name: " << name << endl;
	}
};

class PermanentWorker : public Employee{
private:
	int salary;
public:
	PermanentWorker(const char* name, int salary)
		:Employee(name), salary(salary){}

	int GetPay() const {
		return salary;
	}

	void ShowSalaryInfo() const {
		ShowYourName();
		cout << "salary: " << salary << endl;
	}
};

class EmployeeHandler{
private:
	Employee* empList[50];
	int empNum;
public:
	EmployeeHandler() {
		empNum = 0;
	}

	void AddEmployee(Employee* employee) {
		empList[empNum++] = employee;
	}

	void ShowAllSalaryInfo() const {
		int sum = 0;
		/*
		for (int i = 0; i < empNum; i++) {
			empList[i]->ShowSalaryInfo();
		}
		*/
	}

	void ShowTotalSalaryInfo() const {
		int sum = 0;
		/*
		for (int i = 0; i < empNum; i++) {
			sum += empList[i]->GetPay();
		}
		*/

		cout << "salary sum: " << sum << endl;
	}
	~EmployeeHandler() {
		for (int i = 0; i < empNum; i++) {
			delete empList[i];
		}
	}
};


int main(void) {

	EmployeeHandler handler;

	handler.AddEmployee(new PermanentWorker("LEE", 1500));
	handler.AddEmployee(new PermanentWorker("JIN", 2000));

	handler.ShowAllSalaryInfo();
	handler.ShowTotalSalaryInfo();

	return 0;
}