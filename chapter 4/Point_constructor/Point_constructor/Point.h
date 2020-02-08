#pragma once

class Point {
private:
	int x;
	int y;
public:
	Point(const int xpos, const int ypos);
	int GetX() const;
	int GetY() const;
	bool SetX(int xpos);
	bool SetY(int ypos);
};