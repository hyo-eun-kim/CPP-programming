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

class PermanentWorker : public Employee {
private:
	int salary;
public:
	PermanentWorker(const char* name, int salary)
		:Employee(name), salary(salary) {}

	int GetPay() const {
		return salary;
	}

	void ShowSalaryInfo() const {
		ShowYourName();
		cout << "salary: " << salary << endl;
	}
};

class TemporaryWorker : public Employee {
private:
	int workTime;
	int payPerHour;
public:
	TemporaryWorker(const char* name, int pay)
		:Employee(name), workTime(0), payPerHour(pay){}

	void AddWorkTime(int time) {
		workTime += time;
	}
	int GetPay() const{
		return workTime * payPerHour;
	}
	void ShowSalaryInfo() const {
		ShowYourName();
		cout << "salary: " << GetPay() << endl;
	}
};

class SalesWorker : public PermanentWorker {
private:
	int salesResult;
	double bonusRatio;
public:
	SalesWorker(const char* name, int salary, double ratio)
		:PermanentWorker(name, salary), salesResult(0), bonusRatio(ratio){}

	void AddSalesResult(int sales) {
		salesResult += sales;
	}

	// 오버라이딩
	int GetPay() const {
		return PermanentWorker::GetPay() + (int)(salesResult * bonusRatio);
	}

	// 오버라이딩
	void ShowSalaryInfo() const {
		ShowYourName();
		cout << "salary: " << GetPay() << endl;
	}

};


class EmployeeHandler {
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


	// 정규직
	handler.AddEmployee(new PermanentWorker("LEE", 1500));
	handler.AddEmployee(new PermanentWorker("JIN", 2000));

	// 비정규직
	TemporaryWorker* alba = new TemporaryWorker("Jung", 700);
	alba->AddWorkTime(10);
	alba->ShowSalaryInfo(); // 7000
	handler.AddEmployee(alba);

	// 정규직 중 영업직
	SalesWorker* seller = new SalesWorker("Hong", 1000, 0.1);
	seller->AddSalesResult(1000);
	seller->ShowSalaryInfo();
	handler.AddEmployee(seller); // 1000+1000*0.1 = 1100

	handler.ShowAllSalaryInfo();
	handler.ShowTotalSalaryInfo();

	return 0;
}