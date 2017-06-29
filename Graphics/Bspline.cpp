#include "line.h"
#include "bspline.h"

double uu[13] = { 0, 50, 100, 200, 250, 280, 300, 320, 360, 400, 500, 600, 640 };

Bspline::Bspline(const Points &p) : p(p) { }

Point Bspline::getBsplinePoint(double u) const {
	double t[12][5];
	double x = 0, y = 0;
	for (int i = 0; i < 12; i++)
		if ((u >= uu[i]) && (u < uu[i + 1])) t[i][1] = 1;
		else t[i][1] = 0;

		for (int k = 2; k <= 4; k++) {
			for (int i = 0; i <= 12 - k; i++) {
				t[i][k] = (u - uu[i]) / (uu[i + k - 1] - uu[i]) * t[i][k - 1] +
					(uu[i + k] - u) / (uu[i + k] - uu[i + 1]) * t[i + 1][k - 1];
			}
		}
		for (int i = 0; i < 9; i++) {
			x += t[i][4] * p[i].x;
			y += t[i][4] * p[i].y;
		}
		return Point((int)x, (int)y);
}

const double Bspline::STEP = 0.001;

Points Bspline::border() {
	Point p0 = getBsplinePoint(uu[3]);
	Points pp0;
	for (double t = uu[3]; t <= uu[9]; t += STEP) {
		Point p(getBsplinePoint(t));
		Points lineborder = Line(p0, p).border();
		pp0.insert(pp0.end(), lineborder.begin(), lineborder.end());
		p0 = p;
	}
	return pp0;
}

Bspline Bspline::generateBspline() {
	cout << "由于输入控制顶点坐标较为麻烦，我省略的输入功能，默认9个控制顶点, 3次B样条曲线" << endl;
	cout << "9个控制顶点分别为" << endl;
	cout <<"(50, 50), (60, 55), (65, 57), (80, 80), (100, 90), (130, 100), (160, 120), (180, 140), (200, 160)" << endl;
	Point p1 = Point(50, 50);
	Point p2 = Point(60, 55);
	Point p3 = Point(65, 57);
	Point p4 = Point(80, 80);
	Point p5 = Point(100, 90);
	Point p6 = Point(130, 100);
	Point p7 = Point(160, 120);
	Point p8 = Point(180, 140);
	Point p9 = Point(200, 160);
	Points p;
	p.push_back(p1);
	p.push_back(p2);
	p.push_back(p3);
	p.push_back(p4);
	p.push_back(p5);
	p.push_back(p6);
	p.push_back(p7);
	p.push_back(p8);
	p.push_back(p9);
	Bspline bspline(p);
	bspline.name = "bspline";
	bspline.points = bspline.border();
	return bspline;
}