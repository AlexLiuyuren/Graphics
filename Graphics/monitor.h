#pragma once
#include "common.h"
using namespace std;

class Monitor {
public:
	static void monitor(void);
	static void commandFactory(string cmd);
	static void welcome();
	static void help();
	static void clear();
	static void myExit();
};