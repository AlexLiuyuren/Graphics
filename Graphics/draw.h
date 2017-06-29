#pragma once
#include "Point.h"
using namespace std;
class Draw {
public:
	void draw();
	void help();
	void setColorHelp();
	void clear();
};
void setColor(int r, int g, int b);
void setColor(int color);
int getColor();
int getColor(Point& p);