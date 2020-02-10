#define _CRT_SECURE_NO_WARNINGS
#include <cstring>
#include <iostream>
using namespace std;

class PermanentWorker {
private:
	char name[100];
	int salary;
public:
	PermanentWorker(const char* name, int salary) {
		strcpy(this->name, name);
		this->salary = salary;
	}
	int GetPay() const {
		return salary;
	}
	void ShowSalary() const {
		cout << "name: " << name << endl;
		cout << "salary: " << salary << endl << endl;
	}
};

class EmployeeHandler {
private:
	PermanentWorker* empList[50];
	int empNum;
public:
	EmployeeHandler() {
		empNum = 0;
	}
	void AddEmployee(PermanentWorker* worker) {
		empList[empNum++] = worker;
	}
	void ShowAllSalaryInfo() {
		for (int i = 0; i < empNum; i++) {
			empList[i]->ShowSalary();
		}
	}
	void ShowTotalSalary() {
		int total = 0;
		for (int i = 0; i < empNum; i++) {
			total += empList[i]->GetPay();
		}
		cout << "Total Salary: " << total << endl;
	}
	~EmployeeHandler() {
		for (int i = 0; i < empNum; i++) {
			delete empList[i];
		}
	}
};

int main(void) {

	EmployeeHandler handler;

	handler.AddEmployee(new PermanentWorker("KIM", 1000));
	handler.AddEmployee(new PermanentWorker("LEE", 1500));
	handler.AddEmployee(new PermanentWorker("JUN", 2000));

	handler.ShowAllSalaryInfo();
	handler.ShowTotalSalary();
}