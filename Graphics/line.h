#pragma once
#include "gl/glut.h"
#include "point.h"
#include "shape.h"

class Line : public Shape{
public:
	Point p1, p2;
	Line(Point p1, Point p2) : p1(p1), p2(p2) {};
	static Line generateLine();
	Points border();
};
