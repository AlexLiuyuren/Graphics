#include "monitor.h"
#include "draw.h"
#include "gl/glut.h"
#include "transform.h"
#include "bmp.h"
#include "cut.h"
void Monitor::monitor(void) {
	glClear(GL_COLOR_BUFFER_BIT);
	glFlush();
	while (1) {
		welcome();
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
	else if (command == "transform") {
		Transform tt;
		tt.transform();
	}
	else if (command == "import") {
		cmdImport();
	}
	else if (command == "export") {
		cmdExport();
	}
	else if (command == "cut") {
		cmdCut();
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
	cout << "transform: tansform shapes" << endl;
	cout << "cut: cut shapes" << endl;
	cout << "import: import a .bmp picture" << endl;
	cout << "export: export a .bmp picture" << endl;
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