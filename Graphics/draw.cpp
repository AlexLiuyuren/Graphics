#include "gl/glut.h"
#include "common.h"
#include "draw.h"
#include "line.h"
#include "circle.h"
#include "ellipse.h"
#include "polygon.h"
#include "rectangle.h"
#include "bezier.h"
#include "board.h"
#include "point.h"
#include "bspline.h"
static int red = 255, green = 255, blue = 0;


void Draw::draw() {
	string input; 
	setColor(1, 1, 1);
	while (1) {
		cout << "Please input the graph name you want to paint.(e.g. line )" << endl;
		cout << "you can type help if you want to know all commands(These commands are different from the before.)" << endl;
		cin >> input;
		if (input == "help") {
			help();
		}
		else if (input == "setColor") {
			setColorHelp();
		}
		else if (input == "line") {
			Line l = Line::generateLine();
			board.shapes.push_back(l);
			l.draw();
		}
		else if(input == "circle"){
			Circle c = Circle::generateCircle();
			board.shapes.push_back(c);
			c.draw();
		}
		else if (input == "ellipse") {
			Ellipse e = Ellipse::generateEllipse();
			board.shapes.push_back(e);
			e.draw();
		}
		else if (input == "polygon") {
			Polygon p = Polygon::generatePolygon();
			board.shapes.push_back(p);
			p.draw();
		}
		else if (input == "rectangle") {
			Rectangle rec = Rectangle::generateRectangle();
			board.shapes.push_back(rec);
			rec.draw();
		}
		else if (input == "bezier") {
			Bezier bez = Bezier::generateBezier();
			board.shapes.push_back(bez);
			bez.draw();
		}
		else if (input == "bspline") {
			Bspline bsp = Bspline::generateBspline();
			board.shapes.push_back(bsp);
			bsp.draw();
		}
		else if (input == "exit") {
			return;
		}
		else if (input == "clear") {
			clear();
		}
		else {
			cout << "No such command!" << endl;
		}
	}
}

void Draw::help() {
	cout << "help：Show all commands" << endl;
	cout << "setColor: set color" << endl;
	cout << "exit: Exit from drawing" << endl;
	cout << "clear: Clear the Canvas" << endl;
	cout << "line: Draw a line" << endl;
	cout << "circle: Draw a circle" << endl;
	cout << "ellipse: Draw an ellipse" << endl;
	cout << "polygon: Draw a polygon" << endl;
	cout << "rectangle: Draw a rectangle" << endl;
	cout << "bezier: Draw a bezier curve" << endl;
	cout << "bspline: Draw a bspline curve" << endl;
	return;
}

void Draw::setColorHelp() {
	cout << "请分别输入r, g, b值 e.g: 255 255 0" << endl;
	int r, g, b;
	cin >> r >> g >> b;
	setColor(r, g, b);
	return;
}
void setColor(int r, int g, int b) {
	glColor3f(r, g, b);
}

void Draw::clear() {
	board.clear();
	glClear(GL_COLOR_BUFFER_BIT);
	glFlush();
}

void setColor(int c) {
	int r = (c >> 16) & 0xFF;
	int g = (c >> 8) & 0xFF;
	int b = c & 0xFF;
	setColor(r, g, b);
}

int getColor() {
	return (red << 16) | (green << 8) | blue;
}

int getColor(Point &p) {
	assert(p.valid());
	return board.color[p.x][p.y];
}