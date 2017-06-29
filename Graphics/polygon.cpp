#include "common.h"
#include "point.h"
#include "line.h"
#include "polygon.h"
#include "shape.h"

Polygon::Polygon(const Points &points, bool isFilled) : isFilled(isFilled) {
	if (points.size() == 2) {
		const Point &p1 = points[0];
		const Point &p2 = points[1];
		p.push_back(Point(min(p1.x, p2.x), min(p1.y, p2.y)));
		p.push_back(Point(min(p1.x, p2.x), max(p1.y, p2.y)));
		p.push_back(Point(max(p1.x, p2.x), max(p1.y, p2.y)));
		p.push_back(Point(max(p1.x, p2.x), min(p1.y, p2.y)));
	}
	else {
		p = points;
	}
}

typedef struct NET {
	double y, dY, maxX;

	NET(const Line &l) {
		Point p1 = l.p1, p2 = l.p2;
		y = p1.y;
		maxX = p2.x;
		dY = double(p2.y - p1.y) / (p2.x - p1.x);
	}

	NET next() const {
		NET net(*this);
		net.y += net.dY;
		return net;
	}
} AET;
typedef vector<NET> NETs;
typedef vector<AET> AETs;

Lines Polygon::borderLines() {
	Lines lines;
	auto p0 = p.begin();
	for (auto p1 = ++p.begin(); p1 != p.end(); p1++) {
		lines.push_back(Line(*p0, *p1));
		p0 = p1;
	}
	lines.push_back(Line(*p0, *p.begin()));
	return lines;
}

Points Polygon::border(){
	Points res;
	Lines lines = borderLines();
	NETs nets[WIDTH];
	int minX = WIDTH, maxX = 0;
	for (Line &l : lines) {
		if (l.p1.x == l.p2.x) continue;
		if (l.p1.x > l.p2.x) swap(l.p1, l.p2);
		minX = min(minX, l.p1.x);
		maxX = max(maxX, l.p2.x);
		NET net(l);
		nets[l.p1.x].push_back(net);
	}
	AETs aets;
	for (int x = minX; x <= maxX; x++) {
		AETs newAets;
		for (AET &aet : aets) {
			if (x < aet.maxX) {
				newAets.push_back(aet.next());
			}
		}
		for (NET &net : nets[x]) newAets.push_back(net);
		aets = newAets;
		for (AET &aet : aets) {
			res.push_back(Point(x, (int)round(aet.y)));
		}
	}
	return res;
}

Points Polygon::innerPoints() {
	Points res;
	vector<int> yIndex[WIDTH];
	Points points = border();
	for (Point &p : points) {
		res.push_back(p);
		yIndex[p.x].push_back(p.y);
	}
	Lines lines = borderLines();
	for (Line &l : lines) {
		points = l.border();
		for (Point &p : points) {
			res.push_back(p);
		}
	}
	for (int x = 0; x < WIDTH; x++) {
		sort(yIndex[x].begin(), yIndex[x].end());
		for (int i = 0; i < yIndex[x].size(); i += 2) {
			for (int y = yIndex[x][i]; y <= yIndex[x][i + 1]; y++) {
				res.push_back(Point(x, y));
			}
		}
	}
	return res;
}

void Polygon::getPoints() {
	Lines lines = borderLines();
	for (Line &l : lines) {
		Points pp = l.border();
		points.insert(points.end(), pp.begin(), pp.end());
	}
	if (isFilled) {
		Points pp = innerPoints();
		points.insert(points.end(), pp.begin(), pp.end());
	}
}

Polygon Polygon::generatePolygon() {
	cout << "请输多边形顶点个数 e.g: 3" << endl;
	int pnum;
	cin >> pnum;
	Points p;
	cout << "请依次输入多边形顶点坐标与是否填充(false 或 true) e.g.: 50 50 50 100 100 100 false(表示三个顶点坐标分别为(50, 50), (50, 100), (100, 100))" << endl;
	int x, y;
	string fill;
	bool isfill;
	for (int i = 0; i < pnum; i++) {
		cin >> x >> y;
		p.push_back(Point(x, y));
	}
	cin >> fill;
	fill == "true" ? isfill = true : isfill = false;
	Polygon po = Polygon(p, isfill);
	po.getPoints();
	return po;
}