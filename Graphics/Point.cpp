#include "point.h"
void Point::drawPoint() {
	glBegin(GL_POINTS);
	glVertex2i(x, y);
	glEnd();
	glFlush();
	return;
}