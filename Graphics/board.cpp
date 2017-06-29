#include "board.h"
#include "color.h"
#include "gl/glut.h"
Board board;
void Board::showShapes() {
	int size = shapes.size();
	if (size == 0) {
		cout << "no shapes" << endl;
	}
	else {
		for (int i = 0; i < size; i++) {
			cout << i << ": " << shapes[i].name << endl;
		}
	}
	return;
}

void Board::flush() {
	glClear(GL_COLOR_BUFFER_BIT);
	glFlush();
	int size = shapes.size();
	for (int i = 0; i < size; i++) {
		shapes[i].draw();
	}
	return;
}

void Board::clear() {
	shapes.clear();
	memset(color, COLOR_BACKGROUND, sizeof(color));
	return;
}