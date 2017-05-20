#include "circle.h"
#include "point.h"
#include "common.h"

using namespace std;

Circle Circle::generateCircle() {
	cout << "ÇëÊäÈëÔ²ÐÄ×ø±ê(x, y)ÓëÔ²°ë¾¶r" << endl;
	cout << "e.g.: 100 100 50" << endl;
	int x, y, r;
	cin >> x >> y >> r;
	Circle c(x, y, r);
	return c;
}

void Circle::drawCircle() {
	int xt = 0, yt = r;
	vector<Point> points;
	float pp = 1.25 - r;
	while (xt <= yt) {
		Point p1(xt + x, yt + y);
		Point p2(yt + x, xt + y);
		Point p3(-xt + x, yt + y);
		Point p4(-yt + x, xt + y);
		Point p5(xt + x, -yt + y);
		Point p6(yt + x, -xt + y);
		Point p7(-xt + x, -yt + y);
		Point p8(-yt + x, -xt + y);
		points.push_back(p1);
		points.push_back(p2);
		points.push_back(p3);
		points.push_back(p4);
		points.push_back(p5);
		points.push_back(p6);
		points.push_back(p7);
		points.push_back(p8);
		if (pp < 0) {
			xt++;
			pp += 2 * xt + 1;
		}
		else {
			xt++;
			yt--;
			pp += 2 * xt + 1 - 2 * yt;
		}
	}
	for (auto val : points) {
		val.drawPoint();
	}
	return;
}