#include "common.h"
#include "color.h"
#include "polygon.h"
#include "rectangle.h"

static void cutInside() {
	Polygon polygon = Polygon::generatePolygon();
	polygon.draw(COLOR_BACKGROUND);
	glFlush();
}

static void cutOutside() {
	Polygon polygon = Polygon::generatePolygon();
	Points ps = polygon.border();
	polygon.draw(COLOR_BACKGROUND);
	vector<int> yIndex[WIDTH];
	for (Point &p : ps) {
		yIndex[p.x].push_back(p.y);
	}
	for (int x = 0; x < WIDTH; x++) {
		yIndex[x].push_back(0);
		yIndex[x].push_back(HEIGHT - 1);
		sort(yIndex[x].begin(), yIndex[x].end());
		for (int i = 0; i < yIndex[x].size(); i += 2) {
			for (int y = yIndex[x][i]; y <= yIndex[x][i + 1]; y++) {
				Point(x, y).draw(COLOR_BACKGROUND);
			}
		}
	}
	glFlush();
}


void cmdCut() {
	cout << "inside: cut inside" << endl;
	cout << "outside: cut outside" << endl;
	puts("cancel: exit");
	string op;
	cin >> op;
	if (op == "inside") {
		cutInside();
	}
	else if (op == "outside") {
		cutOutside();
	}
	else if (op == "cancel") {
	}
	else {
		cout << "Input error" << endl;
		cmdCut();
	}
	return;
}
