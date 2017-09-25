#include "stdafx.h"
#include "lab4.h"
#include "gamebase.h"
#include "gameb.h"
#include "gamep.h"
#include "magicsq.h"
#include <ctype.h>
#include <iostream>
#include <string>   // For standard C++ strings.
#include <sstream>  // For standard string streams.
#include <cstring>  // For C-style string functions
#include <vector>
#include <fstream>

using namespace std;

ostream& printboard(ostream& out, int long_string, const vector<gp> &v, unsigned int x, unsigned int y) {
	// print out every pieces of game piece and the game board and the x and y axes
	unsigned int index = 0;
	ostringstream display;
	display << left;
	cout << endl;
	//if (v.size() == x*y) {
		for (unsigned int m = 0; m < x; ++m)
		{
			int t = x - 1 - m;
			display << t;
			display.width(long_string);
			display << "";
			for (unsigned int i = 0;i < y;++i) {
				index = (i*y + t);
				display.width(long_string + 1);
				display << v[index].op_;
			}

			display << '\n';
		}
		//use the long_string as the game piece's long string length and separate each game piece with the string length
		display << "X";
		display.width(long_string);
		display << "";
		for (unsigned int m = 0;m < x;++m) {

			display.width(long_string + 1);
			display << m;
		}
		// print out the game display
		out << display.str() << endl;
		return out;
	/*}
	else {
		throw unmatchvector_dim;
	}*/
}

