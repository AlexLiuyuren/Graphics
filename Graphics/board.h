#pragma once
#include "common.h"
#include "shape.h"
class Board {
public:
	vector<Shape> shapes;
	int color[WIDTH][HEIGHT];
	void showShapes();
	void flush();
	void clear();
};

extern Board board;