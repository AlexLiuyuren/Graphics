#include "common.h"
#include "Point.h"
#include "shape.h"

vector<Shape *> shapes;

Points Shape::border() {
	return Points();
}

void Shape::draw(int color)  {
	for (auto it = points.begin(); it != points.end(); it++) {
		it->draw(color);
	}
}