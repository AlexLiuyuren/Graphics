#include "ellipse.h"
#include "point.h"
#include "common.h"

using namespace std;

Ellipse Ellipse::generateEllipse() {
	cout << "ÇëÊäÈëÍÖÔ²Ô²ÐÄ×ø±ê(x, y)ÓëÍÖÔ²°ë¾¶rx, ry" << endl;
	cout << "e.g.: 200 200 50 100" << endl;
	int x, y, rx, ry;
	cin >> x >> y >> rx >> ry;
	Ellipse e(Point(x, y), rx, ry);
	e.points = e.border();
	e.name = "ellipse";
	return e;
}

Points Ellipse::border(){
	Points points;
	double p1 = ry * ry - rx * rx * ry + (double)rx * rx / 4.0;
	int xt = 0, yt = ry;
	int xold = xt, yold = yt;
	while (ry * ry * xt < rx * rx * yt) {
		xold = xt;
		yold = yt;
		Point po1(xt + center.x, yt + center.y);
		Point po2(-xt + center.x, yt + center.y);
		Point po3(xt + center.x, -yt + center.y);
		Point po4(-xt + center.x, -yt + center.y);
		points.push_back(po1);
		points.push_back(po2);
		points.push_back(po3);
		points.push_back(po4);
		if (p1 < 0) {
			xt++;
			p1 += 2 * ry * ry * xt + ry * ry;
		}
		else {
			xt++;
			yt--;
			p1 += 2 * ry * ry * xt - 2 * rx * rx * yt + ry * ry;
		}
	}
	double p2 = ry * ry * (xold + 0.5) * (xold + 0.5) + rx * rx * (yold - 1) * (yold - 1) - rx * rx * ry * ry;
	xt = xold; yt = yold;
	while (yt >= 0) {
		if (p2 > 0) {
			yt--;
			p2 += -2 * rx * rx * yt + rx * rx;
		}
		else {
			xt++;
			yt--;
			p2 += 2 * ry * ry * xt - 2 * rx * rx * yt + rx * rx;
		}
		Point po1(xt + center.x, yt + center.y);
		Point po2(-xt + center.x, yt + center.y);
		Point po3(xt + center.x, -yt + center.y);
		Point po4(-xt + center.x, -yt + center.y);
		points.push_back(po1);
		points.push_back(po2);
		points.push_back(po3);
		points.push_back(po4);
	}
	return points;
}