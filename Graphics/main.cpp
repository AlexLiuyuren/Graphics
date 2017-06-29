#include <gl/glut.h>
#include "common.h"
#include "monitor.h"
#include "stdio.h"
#include "3d.h"
void main2D(int argc, char **argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);
	glutInitWindowSize(WIDTH, HEIGHT);
	glutCreateWindow("GraphPainter");
	gluOrtho2D(0, WIDTH, 0, HEIGHT);
	glutDisplayFunc(Monitor::monitor);
	glutMainLoop();
}

int main(int argc, char **argv) {
	string op;
	puts("please choose mode:");
	puts("1 - 2D");
	puts("2 - 3D");
	puts("0 - exit");
	cin >> op;
	switch (op[0] - '0') {
	case 0:
		return 0;
	case 1:
		main2D(argc, argv);
		break;
	case 2:
		main3D(argc, argv);
		break;
	default:
		puts("Input incorrect");
		main(argc, argv);
	}
	return 0;
}