#include <queue>

#include "common.h"
#include "mouse.h"
#include "draw.h"

static int DX[] = { -1, 1, 0, 0 };
static int DY[] = { 0, 0, -1, 1 };

static void fill() {
	int oldColor = getColor(points[0]);
	int color = getColor();
	if (oldColor == color) return;
	queue<Point> q;
	q.push(points[0]);
	int cnt = 0;
	while (!q.empty()) {
		cnt++;
		Point p = q.front();
		q.pop();
		for (int k = 0; k < 4; k++) {
			Point p2(p.x + DX[k], p.y + DY[k]);
			if (p2.valid() && (getColor(p2) == oldColor)) {
				q.push(p2);
				p2.draw();
			}
		}
	}
	printf("%d\n", cnt);
	glFlush();
}

void cmdFill() {
	puts("Please click one points");
	nextEvent(1, fill);
}