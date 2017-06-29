#include "common.h"
#include "line.h"
#include "bezier.h"

Point Bezier::getBezierPoint(double t) const {
	vector<double> fact(2, 1);
	double x = 0, y = 0;
	int n = (int)p.size() - 1;
	for (int i = 2; i <= n; i++) fact.push_back(*fact.rbegin() * i);
	for (int i = 0; i <= n; i++) {
		double factor = pow(t, i) * pow(1 - t, n - i);
		factor *= fact[n] / fact[n - i] / fact[i];
		x += factor * p[i].x;
		y += factor * p[i].y;
	}
	return Point((int)round(x), (int)round(y));
}

Bezier::Bezier(const Points &p) : p(p) { }

const double Bezier::STEP = 0.001;

Points Bezier::border() {
	Point p0 = p[0];
	Points po;
	for (double t = 0; t < 1; t += STEP) {
		Point p = getBezierPoint(t);
		Points pp = Line(p, p0).border();
		po.insert(po.end(), pp.begin(), pp.end());
		p0 = p;
	}
	return po;
}

Bezier Bezier::generateBezier() {
	cout << "请输控制控制顶点个数n e.g: 4" << endl;
	int pnum;
	cin >> pnum;
	Points p;
	cout << "请依次输入控制顶点坐标(e.g.: 50 50 60 100 80 120 90 150 (表示四个顶点坐标分别为(50, 50), (60, 100), (80, 120), (90, 150))" << endl;
	int x, y;
	for (int i = 0; i < pnum; i++) {
		cin >> x >> y;
		p.push_back(Point(x, y));
	}
	Bezier bez = Bezier(p);
	bez.name = "bezier";
	bez.points = bez.border();
	return bez;
}