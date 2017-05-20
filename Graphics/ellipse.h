#pragma once
#include "gl/glut.h"
class Ellipse {
private:
	int x, y, rx, ry;
public:
	Ellipse(int x, int y, int rx, int ry) : x(x), y(y), rx(rx), ry(ry) {};
	Ellipse() {};
	static Ellipse generateEllipse();
	void drawEllipse();
};