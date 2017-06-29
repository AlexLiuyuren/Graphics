#pragma once
#include "gl/glut.h"
#include "shape.h"
class Ellipse : public Shape{
public:
	Point center;
	int rx, ry;
	Ellipse(Point c, int rx, int ry) : center(c), rx(rx), ry(ry) {};
	Ellipse() {};
	Points border();
	static Ellipse generateEllipse();
};