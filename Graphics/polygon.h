#pragma once
#include "common.h"
#include "point.h"
#include "line.h"
#include "shape.h"
typedef std::vector<Line> Lines;

class Polygon : public Shape {
public:
	Points p;
	bool isFilled;

	Polygon(const Points &p, bool isFilled = false);

	Points border();

	Points innerPoints();

	Lines borderLines();

	static Polygon generatePolygon();

	void getPoints();

};

