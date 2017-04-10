#pragma once
#include "gl/glut.h"
class Line {
private:
	int x1, y1, x2, y2;
public:
	Line(int x1, int y1, int x2, int y2) : x1(x1), y1(y1), x2(x2), y2(y2) {};
	static Line generateLine();
	void drawLine();
};
