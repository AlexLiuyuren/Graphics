#include "monitor.h"
#include "draw.h"
#include "gl/glut.h"

void Monitor::monitor(void) {
	glClear(GL_COLOR_BUFFER_BIT);
	glFlush();
	welcome();
	while (1) {
		string command;
		cin >> command;
		commandFactory(command);
	}
	return;
}

void Monitor::commandFactory(string command) {
	if (command == "help") {
		help();
	}
	else if (command == "draw") {
		Draw dd;
		dd.draw();
	}
	else if (command == "clear") {
		clear();
	}
	else if (command == "exit") {
		myExit();
	}
	else {
		cout << "No such command, please input again." << endl;
	}
}
void Monitor::welcome() {
	cout << "welcome to Graph Painter, please type help if you don't know commands." << endl;
	return;
}

void Monitor::help() {
	cout << "help: Show all commands" << endl;
	cout << "draw: Draw graphs" << endl;
	cout << "clear: Clear the command line window" << endl;
	cout << "exit: Exit program" << endl;
	return;
}
void Monitor::clear() {
	system("cls");
}

void Monitor::myExit() {
	exit(0);
}