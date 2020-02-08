#include <iostream>
using namespace std;

class SinivelCap {
public:
	void Take() const {
		cout << "Äà¹°ÀÌ ¸ØÃç¿ä" << endl;
	}
};

class SneezeCap {
public:
	void Take() const {
		cout << "ÀçÃ¤±â°¡ ¸ØÃç¿ä" << endl;
	}
};

class SnuffCap {
public:
	void Take() const {
		cout << "ÄÚ¸·ÈûÀÌ ¶Õ·Á¿ä" << endl;
	}
};

class ColdPatient {
public:
	void TakeSinivelCap(const SinivelCap& cap) const {
		cap.Take();
	}
	void TakeSneezeCap(const SneezeCap& cap) const {
		cap.Take();
	}
	void TakeSnuffCap(const SnuffCap& cap)const {
		cap.Take();
	}
};

int main(void) {

	SinivelCap sinivel;
	SneezeCap sneeze;
	SnuffCap snuff;

	ColdPatient hyoeun;
	hyoeun.TakeSinivelCap(sinivel);
	hyoeun.TakeSneezeCap(sneeze);
	hyoeun.TakeSnuffCap(snuff);
	
	return 0;
}