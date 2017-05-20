#pragma once
#include "gl/glut.h"
class Circle {
private:
	int x, y, r;
public:
	Circle(int x, int y, int r) : x(x), y(y), r(r){};
	static Circle generateCircle();
	void drawCircle();
};
