#pragma once
#include "point.h"
#include "shape.h"

class Bezier : public Shape {
	static const double STEP;

public:
	Points p;

	Point getBezierPoint(double t) const;

	Bezier(const Points &p);

	Points border();

	static Bezier generateBezier();
};

