#include "rectangle.h"

Rectangle::Rectangle(const Points &p, bool isFilled)
	: Rectangle(p[0], p[1], isFilled) { }

Rectangle::Rectangle(const Point &p1, const Point &p2, bool isFilled)
	: Polygon(Points(), isFilled) {
	p.push_back(Point(min(p1.x, p2.x), min(p1.y, p2.y)));
	p.push_back(Point(min(p1.x, p2.x), max(p1.y, p2.y)));
	p.push_back(Point(max(p1.x, p2.x), max(p1.y, p2.y)));
	p.push_back(Point(max(p1.x, p2.x), min(p1.y, p2.y)));
}

Rectangle Rectangle::generateRectangle() {
	cout << "请输入任意两个对角顶点的坐标与是否填充(true 或 false) e.g: 50 50 200 200 true" << endl;
	int x1, y1, x2, y2;
	string fill;
	bool isfill;
	cin >> x1 >> y1 >> x2 >> y2 >> fill;
	fill == "true" ? isfill = true : isfill = false;
	Rectangle re = Rectangle(Point(x1, y1), Point(x2, y2), isfill);
	re.getPoints();
	return re;
}