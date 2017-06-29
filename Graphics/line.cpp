#include "line.h"
#include "point.h"
#include "common.h"

using namespace std;
 Line Line::generateLine() {
	cout << "Please input the coordinates of ends of line: x1 y1 x2 y2(should be integers)" << endl;
	cout << "Coordinates shouldn't exceed 320 320, which is the size of the screen." << endl;
	cout << "e.g.: 0 0 200 200" << endl;
	int x1, y1, x2, y2;
	cin >> x1 >> y1 >> x2 >> y2;
	Line l(Point(x1, y1), Point(x2, y2));
	l.points = l.border();
	l.name = "line";
	return l;
}
 Points Line::border() {
	 bool isSwap = abs(p2.x - p1.x) < abs(p2.y - p1.y);
	 int ax = p1.x, ay = p1.y, bx = p2.x, by = p2.y;
	 if (isSwap) {
		 swap(ax, ay);
		 swap(bx, by);
	 }
	 int dX = bx - ax;
	 int dY = by - ay;
	 int absDX = abs(dX);
	 int absDY = abs(dY);
	 int unitX = sign(dX);
	 int unitY = sign(dY);
	 int p = -absDX;
	 Points points;
	 for (int k = 0; k <= absDX; k++) {
		 if (isSwap) points.push_back(Point(ay, ax));
		 else points.push_back(Point(ax, ay));
		 ax += unitX;
		 p += 2 * absDY;
		 if (p > 0) {
			 ay += unitY;
			 p -= 2 * absDX;
		 }
	 }
	 return points;
 }
