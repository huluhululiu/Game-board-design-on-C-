#include "stdafx.h"
#include "lab4.h"
#include "gamep.h"
#include "gamebase.h"
#include "gameb.h"
#include "almonds.h"
#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <iomanip>
using namespace std;
almondgame::almondgame() : gamebase(5, 5, 0) {
	whoseturn = true;
	gamename = "NineAlmonds";
	long_string = 1;
	gp alm(brown, "almond", "A");
	gp empty(no_color, "empty", " ");
	ifstream ifs(gamename);
	v.resize(25,empty);
	if (ifs.is_open()) {
		//
		string c;
		if (getline(ifs, c)) {
			if (c == gamename) {//if the first line is game name then read the following lines
				getline(ifs, c);
				istringstream iss(c);

				if(iss >> moves >> long_string>>whoseturn){
				string line;
				while (getline(ifs, line)) {
					istringstream iss(line);
					string color;
					string name;
					string op;
					unsigned int x;
					unsigned int y;
					if (iss >> color >> name >> op >> x >> y) {
						gp np(stringtoenum(color), name, op);
						v[5 * x + y] = np;
					}
				}
				}
				else throw readyes_extractno;
			}
			else if (c == "NO DATA") {//start a new game if no data stored
				for (int i = 0; i <5; ++i)
				{
					long_string = 1;
					for (int j = 0; j <5; ++j)
					{
						if (((i>=1) && (i <= 3)) && ((j>=1) && (j <= 3))) {
							v.push_back(alm);
						}
						else {
							v.push_back(empty);
						}

					}
				}
			}
			else {
				std::cout << "No valid lines in the file!" << endl;
				throw readyes_extractno;
			}
		}
	}
	else {//if there is no file to open, start a new game
		long_string=1;
		for (int i = 0; i <5; ++i)
		{
			for (int j = 0; j <5; ++j)
			{
				if (((i>=1) && (i <= 3)) && ((j>=1) && (j <= 3))) {
					v.push_back(alm);
				}
				else {
					v.push_back(empty);
				}

			}
		}
	}
	
	


}
ostream &operator<<(ostream &out, const almondgame &a) {
	try {
		int r = a.cols;
		int c = a.rows;
		printboard(out, a.long_string, a.v, r, c);
	}
	catch (results_code) {
		throw;
	}
	return out;
}
void almondgame::print() {
	try
	{
		std::cout << *this << endl;
	}
	catch (results_code) {
		throw;
	}
}
bool almondgame::done() {
	gp alm(brown, "almond", "A");
	gp empty(no_color, "empty", " ");
	int count = 0;
	int almo = 0;

	for (int i = 0;i<25;++i) {
		//check if only the central square is the almond and all the other squares are empty
		if ((i != 12) && (v[i].op_ == alm.op_)) {

			return false;
		}
		if ((i == 12) && (v[i].op_ != alm.op_)) {

			return false;
		}

	}
	return true;
}
bool almondgame::stalemate() {
	//check if there are still valid moves on the board
	gp alm(brown, "almond", "A");
	gp empty(no_color, "empty", " ");
	if (done()) {

		return false;
	}
	else {
		for (int m = 0;m < 5 * 5;++m) {
			if (v[m].op_ == alm.op_) {
				for (int n = 0;n < 5 * 5;++n) {
					if (v[n].op_ == empty.op_) {
						//check the coordinates of an almond and an empty square to see if the two can compose a valid move
						int y1 = m / 5;
						int x1 = m % 5;
						int y2 = n / 5;
						int x2 = n % 5;
						if (isvalidmove(x1, y1, x2, y2)) {

							return false;
						}
					}
				}
			}

		}
	}
	return true;
}

void almondgame::turn() {
	unsigned col;
	unsigned row;
	gp alm(brown, "almond", "A");
	gp empty(no_color, "empty", " ");
	try {
		cout << "what's your start piece?" << endl;
		prompt(col, row);
	}
	catch (results_code quit_error) {//check if the user type quit or not
		throw quit_error;
	}
	int i = col * 5 + row;
	if (i<0 || i>24 || v[i].op_ != alm.op_) {// check if the start piece is an almond or not
		cout << "Start piece invalid." << endl;
		return turn();
	}
	else return second(col, row);//ask for the end piece

}
void almondgame::second(unsigned col, unsigned row) {
	unsigned coll;
	unsigned roww;
	gp alm(brown, "almond", "A");
	gp empty(no_color, "empty", " ");
	if (done() || stalemate()) {
		return;// if the game board is done or stalemate, end of the game
	}
	try {
		cout << "what's your end piece?" << endl;
		prompt(coll, roww);
	}
	catch (results_code quit_error) {// check for quit input
		throw quit_error;
	}
	int i = coll * 5 + roww;
	if (i<0 || i>24 || v[i].op_ == alm.op_) {
		cout << "Target piece invalid." << endl;//check if the end piece is an almond or not
		return second(col, row);
	}
	if (!isvalidmove(row, col, roww, coll)) {
		cout << "Move is not successful!" << endl;//check if the move is valid with the start and end piece
		return turn();
	}
	int star = col * 5 + row;
	v[star] = empty;
	v[i] = alm;
	int mix = (row + roww) / 2;
	int miy = (col + coll) / 2;

	int mid = miy * 5 + mix;
	//update the mid piece to be empty and the start be empty and the end be almond
	v[mid] = empty;
	//update the game board and print out the gameboard
	cout << *this << endl;
	return third(coll, roww);

}
void almondgame::third(unsigned coll, unsigned roww) {
	gp alm(brown, "almond", "A");
	gp empty(no_color, "empty", " ");
	if (done() || stalemate()) {
		return;
	}
	cout << "The piece has been moved to " << coll << " " << roww << endl;
	cout << "Continue to move?Type Y or N" << endl;
	string ans;
	//check if the user want to continue move the same almond or not
	getline(cin, ans);
	if (ans == "Y") {
		// ask for the new end piece
		return second(coll, roww);
	}
	if (ans == "N") {
		return;
	}
	else {
		cout << "Please type Y or N in upper case." << endl;
		return third(coll, roww);
	}

}
//check if the move is valid or not
bool almondgame::isvalidmove(int x1, int y1, int x2, int y2) {
	gp alm(brown, "almond", "A");
	gp empty(no_color, "empty", " ");
	int start = y1 * 5 + x1;
	int end = y2 * 5 + x2;
	if ((v[start].op_ != alm.op_) || (v[end].op_ == alm.op_)) {
		return false;
	}
	else {
		int mix = (x1 + x2) / 2;
		int miy = (y1 + y2) / 2;
		int mid = miy * 5 + mix;
		if (v[mid].op_ != alm.op_) {
			return false;
		}
		if ((abs(x1 - x2) != 0) && (abs(y1 - y2) != 0)) {
			if ((abs(x1 - x2) != 2) || (abs(y1 - y2) != 2)) {
				return false;
			}
		}
		if ((abs(x1 - x2) > 2) || (abs(y1 - y2) > 2) || (abs(x1 - x2) == 1) || (abs(y1 - y2) == 1)) {
			return false;
		}

	}
	return true;
}

