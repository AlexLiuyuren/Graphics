#include "point.h"
#include "draw.h"
#include "board.h"
//void Point::draw() const {
//	glBegin(GL_POINTS);
//	glVertex2i(x, y);
//	glEnd();
//	glFlush();
//	return;
//}
void Point::draw(int color) {
	if (!valid()) return;
	if (color < 0) color = getColor();
	setColor(color);
	board.color[x][y] = color;
	glBegin(GL_POINTS);
	glVertex2i(x, y);
	glEnd();
	glFlush();
	return;
}
Point Point::add(int dx, int dy) const {
	return Point(x + dx, y + dy);
}

Point Point::rotate(const Point &p, double theta) const {
	int x = this->x - p.x;
	int y = this->y - p.y;
	int dx = (int)round(x * cos(theta) + y * sin(theta));
	int dy = (int)round(-x * sin(theta) + y * cos(theta));
	return p.add(dx, dy);
}

Point Point::scale(const Point &p, double frac) const {
	int dx = (int)round((x - p.x) * frac);
	int dy = (int)round((y - p.y) * frac);
	return p.add(dx, dy);
}

bool Point::valid() {
	return ((x >= 0) && (x < WIDTH)
		&& (y >= 0) && (y < HEIGHT));
}