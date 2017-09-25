#include "stdafx.h"
#include "gamp.h"
#include "gameb.h"
#include "lab2h.h"
#include <ctype.h>
#include <iostream>
#include <string>   // For standard C++ strings.
#include <sstream>  // For standard string streams.
#include <cstring>  // For C-style string functions
#include <vector>
#include <fstream>

using namespace std;

int printboard(const vector<gp>  piece, unsigned int x, unsigned int y) {
	// print out every pieces of game piece and the game board and the x and y axes

	cout << endl;
	for (unsigned int m = 0; m <x; ++m)
	{
		int t = 4 - m;
		cout << t << " ";
		for (unsigned int i = 0;i < y;++i) {

			cout << piece[i * 5 + t].op_ << " ";
		}

		cout << endl;
	}
	cout << "X";
	for (unsigned int m = 0;m < x;++m) {
		cout << " " << m;
	}
	cout << endl;
	return success;

}