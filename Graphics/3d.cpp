#include "common.h"
#include "gl/glut.h"
int angleX;
int angleY;

static void display() {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	glPushMatrix();
	glRotated(angleX, 1, 0, 0);
	glRotated(angleY, 0, 1, 0);

	glBegin(GL_POLYGON);
	glColor3d(1, 1, 1);
	glVertex3i(50, 50, 50);
	glColor3d(1, 1, 0);
	glVertex3i(50, -50, 50);
	glColor3d(1, 0, 0);
	glVertex3i(-50, -50, 50);
	glColor3d(1, 0, 1);
	glVertex3i(-50, 50, 50);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3d(0, 1, 1);
	glVertex3i(50, 50, -50);
	glColor3d(0, 1, 0);
	glVertex3f(50, -50, -50);
	glColor3d(0, 0, 0);
	glVertex3i(-50, -50, -50);
	glColor3d(0, 0, 1);
	glVertex3i(-50, 50, -50);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3d(0, 1, 1);
	glVertex3i(50, 50, -50);
	glColor3d(1, 1, 1);
	glVertex3i(50, 50, 50);
	glColor3d(1, 0, 1);
	glVertex3i(-50, 50, 50);
	glColor3d(0, 0, 1);
	glVertex3i(-50, 50, -50);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3d(0, 1, 0);
	glVertex3i(50, -50, -50);
	glColor3d(1, 1, 0);
	glVertex3i(50, -50, 50);
	glColor3d(1, 0, 0);
	glVertex3i(-50, -50, 50);
	glColor3d(0, 0, 0);
	glVertex3i(-50, -50, -50);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3d(1, 1, 1);
	glVertex3i(50, 50, 50);
	glColor3d(0, 1, 1);
	glVertex3i(50, 50, -50);
	glColor3d(0, 1, 0);
	glVertex3i(50, -50, -50);
	glColor3d(1, 1, 0);
	glVertex3i(50, -50, 50);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3d(1, 0, 1);
	glVertex3i(-50, 50, 50);
	glColor3d(0, 0, 1);
	glVertex3i(-50, 50, -50);
	glColor3d(0, 0, 0);
	glVertex3i(-50, -50, -50);
	glColor3d(1, 0, 0);
	glVertex3i(-50, -50, 50);
	glEnd();
	glPopMatrix();

	glutSwapBuffers();
}

void reshape(int w, int h) {
	GLdouble aspect = (GLdouble)w / h;
	GLdouble nRange = 100;

	glViewport(0, 0, w, h);

	glMatrixMode(GL_PROJECTION); //将当前矩阵指定为投影模式  
	glLoadIdentity();

	//设置三维投影区  

	if (w <= h) {
		glOrtho(-nRange, nRange, -nRange * aspect, nRange * aspect, -nRange, nRange);
	}
	else {
		glOrtho(-nRange, nRange, -nRange / aspect, nRange / aspect, -nRange, nRange);
	}
}

void key_board(GLint key, GLint x, GLint y) {
	if (key == GLUT_KEY_UP) angleX -= 5;
	if (key == GLUT_KEY_DOWN) angleX += 5;
	if (key == GLUT_KEY_LEFT) angleY -= 5;
	if (key == GLUT_KEY_RIGHT) angleY += 5;
	angleX %= 360;
	angleY %= 360;
	glutPostRedisplay();
}

void init() {
	angleX = 45;
	angleY = 315;

	glClearColor(0, 0, 0, 1);

	glEnable(GL_DEPTH_TEST);
	glEnable(GL_DITHER);
	glShadeModel(GL_SMOOTH);
}

void main3D(int argc, char *argv[]) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(HEIGHT, HEIGHT);
	glutCreateWindow("Graphics-3D");

	glutReshapeFunc(reshape);
	glutDisplayFunc(display);
	glutSpecialFunc(key_board);

	init();

	glutMainLoop();
}
