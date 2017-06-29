#pragma once
#include "circle.h"
#include "point.h"
#include "common.h"
#include "shape.h"
using namespace std;

Circle Circle::generateCircle() {
	cout << "ÇëÊäÈëÔ²ÐÄ×ø±ê(x, y)ÓëÔ²°ë¾¶r" << endl;
	cout << "e.g.: 100 100 50" << endl;
	int x, y, r;
	cin >> x >> y >> r;
	Circle c(Point(x, y), r);
	c.points = c.border();
	c.name = "circle";
	return c;
}

Points Circle::border() {
	int xt = 0, yt = r;
	vector<Point> points;
	float pp = 1.25 - r;
	while (xt <= yt) {
		Point p1(xt + center.x, yt + center.y);
		Point p2(yt + center.x, xt + center.y);
		Point p3(-xt + center.x, yt + center.y);
		Point p4(-yt + center.x, xt + center.y);
		Point p5(xt + center.x, -yt + center.y);
		Point p6(yt + center.x, -xt + center.y);
		Point p7(-xt + center.x, -yt + center.y);
		Point p8(-yt + center.x, -xt + center.y);
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
	return points;
}