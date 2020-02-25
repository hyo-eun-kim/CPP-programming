#include <iostream>
using namespace std;

class SortRule {
public:
	virtual bool operator()(int num1, int num2) const = 0; // 가상함수
};

class DescendingSort : public SortRule {
public:
	bool operator()(int num1, int num2) const {
		if (num1 < num2) {
			return true;
		}
		else {
			return false;
		}
	}
};

class AscendingSort :public SortRule {
public:
	bool operator()(int num1, int num2)const {
		if (num1 > num2) {
			return true;
		}
		else {
			return false;
		}
	}
};

class DataSort {
private:
	int* arr;
	int idx;
	const int MAX_LEN;
public:
	DataSort(int arrlen) :MAX_LEN(arrlen), idx(0) {
		arr = new int[arrlen];
	}
	~DataSort() {
		delete arr;
	}

	void AddData(int num) {
		if (idx < MAX_LEN) {
			arr[idx++] = num;
		}
	}

	void SortData(const SortRule& sort){
		for (int i = 0; i < idx - 1; i++) {
			for (int j = 0; j < idx-1-i; j++) {
				if (sort(arr[j], arr[j + 1])) {
					int tmp = arr[j];
					arr[j] = arr[j + 1];
					arr[j + 1] = tmp;
				}
			}
		}
	}
	
	void ShowAllData() {
		for (int i = 0; i < idx; i++) {
			cout << arr[i] << " ";
		}
		cout << endl;
	}

};

int main(void) {

	DataSort data(5);

	data.AddData(40);
	data.AddData(30);
	data.AddData(50);
	data.AddData(20);
	data.AddData(10);

	data.ShowAllData();

	AscendingSort ascending;
	data.SortData(ascending);
	data.ShowAllData();

	data.SortData(DescendingSort());
	data.ShowAllData();

	return 0;
}