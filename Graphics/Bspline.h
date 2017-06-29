#pragma once
#include "common.h"
#include "shape.h"

class Bspline : public Shape {
	static const double STEP;

public:
	Points p;

	Point getBsplinePoint(double t) const;

	Bspline(const Points &p);

	Points border();

	static Bspline generateBspline();
};