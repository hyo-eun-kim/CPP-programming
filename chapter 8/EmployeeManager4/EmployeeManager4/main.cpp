#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
using namespace std;

// 멤버함수로 가상함수를 하나 이상 가지는 클래스를 추상 클래스라고 한다.
// 추상클래스는 객체 생성이 불가능하다.
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

	// 가상함수에 0을 대입하는 기호는
	// 실제 0을 대입하는 것이 아니라, 몸체를 정의하지 않았음을 컴파일러에게 알려주는 역할
	// 가상함수는 포인터연산을 포인터의 타입에 따라 결정하는 것이 아니라
	// 포인터가 가리키는 객체의 타입에 따라 결정한다!
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


	// 정규직
	handler.AddEmployee(new PermanentWorker("LEE", 1500));
	handler.AddEmployee(new PermanentWorker("JIN", 2000));

	// 비정규직
	TemporaryWorker* alba = new TemporaryWorker("Jung", 700);
	alba->AddWorkTime(10);
	//alba->ShowSalaryInfo(); // 7000
	handler.AddEmployee(alba);

	// 정규직 중 영업직
	SalesWorker* seller = new SalesWorker("Hong", 1000, 0.1);
	seller->AddSalesResult(1000);
	//seller->ShowSalaryInfo();
	handler.AddEmployee(seller); // 1000+1000*0.1 = 1100

	handler.ShowAllSalaryInfo();
	handler.ShowTotalSalaryInfo();



	return 0;

	
}