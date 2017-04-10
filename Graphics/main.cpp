#include <gl/glut.h>
#include "common.h"
#include "monitor.h"

void main(int argc, char **argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);
	glutInitWindowSize(WIDTH, HEIGHT);
	glutCreateWindow("My first work");
	gluOrtho2D(0, WIDTH, 0, HEIGHT);
	glutDisplayFunc(Monitor::monitor);
	glutMainLoop();
}