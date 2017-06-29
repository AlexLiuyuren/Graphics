#pragma once
#include "common.h"
#include "point.h"

using namespace std;

class Shape {
public:
	string name;
	Points points;
	virtual Points border();

	virtual void draw(int color = -1);
};

extern vector<Shape *> shapes;