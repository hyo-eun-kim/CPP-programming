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

	virtual int GetPay() const = 0;
	virtual void ShowSalaryInfo() const = 0;
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
		:Employee(name), workTime(0), payPerHour(pay) {}

	void AddWorkTime(int time) {
		workTime += time;
	}
	int GetPay() const {
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
		:PermanentWorker(name, salary), salesResult(0), bonusRatio(ratio) {}

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


namespace RISK_LEVEL {
	enum {
		RISK_A, RISK_B, RISK_C
	};
}

class ForeignSalesWorker : public SalesWorker {
private:
	const int riskLevel;
public:
	ForeignSalesWorker(const char* name, int salary, double ratio, int level)
		:SalesWorker(name, salary, ratio), riskLevel(level) {}

	// 오버라이딩
	int GetPay() const {
		switch (riskLevel) {
		case 0:
			return SalesWorker::GetPay() * 1.3;
		case 1:
			return SalesWorker::GetPay() * 1.2;
		case 2:
			return SalesWorker::GetPay() * 1.1;
		default:
			return 0;
		}

	}

	// 오버라이딩
	void ShowSalaryInfo() const {
		SalesWorker::ShowSalaryInfo();
		cout << "risk pay: " << GetPay() - SalesWorker::GetPay() << endl;
		cout << "sum: " << GetPay() << endl << endl;
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

		for (int i = 0; i < empNum; i++) {
			empList[i]->ShowSalaryInfo();
		}

	}

	void ShowTotalSalaryInfo() const {
		int sum = 0;

		for (int i = 0; i < empNum; i++) {
			sum += empList[i]->GetPay();
		}

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

	ForeignSalesWorker* fseller1 = new ForeignSalesWorker("Hong", 1000, 0.1, RISK_LEVEL::RISK_A);
	fseller1->AddSalesResult(7000);
	handler.AddEmployee(fseller1);


	ForeignSalesWorker* fseller2 = new ForeignSalesWorker("Yoon", 1000, 0.1, RISK_LEVEL::RISK_B);
	fseller2->AddSalesResult(7000);
	handler.AddEmployee(fseller2);


	ForeignSalesWorker* fseller3 = new ForeignSalesWorker("Hong", 1000, 0.1, RISK_LEVEL::RISK_C);
	fseller3->AddSalesResult(7000);
	handler.AddEmployee(fseller3);

	handler.ShowAllSalaryInfo();
	handler.ShowTotalSalaryInfo();


	return 0;
}