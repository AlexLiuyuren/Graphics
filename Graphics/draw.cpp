#include "gl/glut.h"
#include "common.h"
#include "draw.h"
#include "line.h"
#include "circle.h"
#include "ellipse.h"

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
		else if (input == "line") {
			Line l = Line::generateLine();
			l.drawLine();
		}
		else if(input == "circle"){
			Circle c = Circle::generateCircle();
			c.drawCircle();
		}
		else if (input == "ellipse") {
			Ellipse e = Ellipse::generateEllipse();
			e.drawEllipse();
		}
		else if (input == "exit") {
			cout << "welcome to Graph Painter, please type help if you don't know commands." << endl;
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
	cout << "help£ºShow all commands" << endl;
	cout << "exit: Exit from drawing" << endl;
	cout << "clear: Clear the Canvas" << endl;
	cout << "line: Draw a line" << endl;
	cout << "circle: Draw a circle" << endl;
	cout << "ellipse: Draw an ellipse" << endl;
	return;
}

void Draw::setColor(float r, float g, float b) {
	glColor3f(r, g, b);
}

void Draw::clear() {
	glClear(GL_COLOR_BUFFER_BIT);
	glFlush();
}