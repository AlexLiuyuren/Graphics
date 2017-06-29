#pragma once
#include "gl/glut.h"
#include "common.h"

class Point {
public:
	int x;
	int y;
	Point(int x, int y) : x(x), y(y) {};
	Point() {};
	void draw(int color = -1);
	Point add(int dx, int dy) const;
	Point rotate(const Point &p, double theta) const;
	Point scale(const Point &p, double frac) const;
	bool valid();
};

typedef std::vector<Point> Points;