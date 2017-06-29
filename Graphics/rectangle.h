#pragma once
#include "shape.h"
#include "polygon.h"

class Rectangle : public Polygon {
public:
	Rectangle(const Points &p, bool isFilled = false);
	Rectangle(const Point &p1, const Point &p2, bool isFilled = false);
	static Rectangle generateRectangle();
};