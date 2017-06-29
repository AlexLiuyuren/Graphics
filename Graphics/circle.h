#pragma once
#include "gl/glut.h"
#include "shape.h"
#include "point.h"
class Circle : public Shape{
	
public:
	Point center;
	int r;
	Circle(Point c, int r): center(c), r(r){};
	static Circle generateCircle();
	Points border();
};
