#pragma once
#include "gl/glut.h"
class Point {
private:
	int x;
	int y;
public:
	Point(int x, int y) : x(x), y(y) {};
	Point() {};
	void drawPoint();
};
