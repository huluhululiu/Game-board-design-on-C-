#include "stdafx.h"
#include "lab4.h"
#include "gamep.h"
#include "gamebase.h"
#include "gameb.h"
#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <iomanip>
#include "rever.h"
using namespace std;
reversi::reversi(string a,string b) : gamebase(8, 8, 0) {
	playerA = a;
	playerB = b;
	gamename = "Reversi";
	long_string = 1;
	ifstream ifs(gamename);
	gp blk(black, "Alice", "X");
	gp wt(white, "Bob", "O");
	gp empty(no_color, "empty", " ");
	v.resize(64, empty);
	if (ifs.is_open()) {//check if the file is opened or not
		string c;
		if (getline(ifs, c)) {
			if (c == gamename) {
				getline(ifs, c);
				istringstream iss(c);
				if (iss >> moves >> long_string >> whoseturn) {//extract the moves, long string and whose turn it is 
					string line;
					while (getline(ifs, line)) {//extract all the game pieces
						istringstream iss(line);
						string color;
						string name;
						string op;
						unsigned int x;
						unsigned int y;
						if (iss >> color >> name >> op >> x >> y) {
							gp np(stringtoenum(color), name, op);
							v[8 * x + y] = np;
						}
					}
				}
				else throw readyes_extractno;
			}
			else if (c == "NO DATA") {//if there is no data, start a new game
				v[3 * 8 + 4] = wt;
				v[4 * 8 + 3] = wt;
				v[4 * 8 + 4] = blk;
				v[3 * 8 + 3] = blk;
				long_string = 1;
			}
			// throw the error of read the file yes but extract information no. 
			else {
				cout << "No valid lines in the file!" << endl;
				throw readyes_extractno;
			}
		}
	}
	else {
		//if there is no file available in the folder start a new game
		long_string = 1;
		v[3 * 8 + 4] = wt;
		v[4 * 8 + 3] = wt;
		v[4 * 8 + 4] = blk;
		v[3 * 8 + 3] = blk;
	}



}
ostream &operator<<(ostream &out, const reversi &a) {
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
void reversi::print() {//print out the game board
	try
	{
		std::cout << *this << endl;
	}
	catch (results_code a) {
		throw a;
	}
}
void reversi::turn() {// the turn method checks whose turn it is and check corresponding player has valid move or not
	// if no valid move on the board. changes to the other player
	//if there are valid move but the user keeps on typing invalid moves, prompt the user for a valid move
	gp blk(black, "Alice", "X");
	gp wt(white, "Bob", "O");
	gp empty(no_color, "empty", " ");
	unsigned int col = 0;
	unsigned int row = 0;
	bool hasvalidmove = true;
	if (whoseturn) {
		if (!validmovefora()) {
			cout << playerA << ", you do not have a valid place to put your coin for this round." << endl;
			whoseturn = !whoseturn;
			++moves;
			return turn();
		}
		else {
			while (hasvalidmove) {
				try {
					cout << playerA << ", where do you want to put your coin?" << endl;
					prompt(col, row);
				}
				catch (results_code quit_error) {//check if the user type quit or not
					throw quit_error;
				}
				int i = col * 8 + row;
				vector<int> change;
				if (v[i].op_ == empty.op_) {//check if the user choose an empty space or not
					if (checkMe(i, change)) {//check the space is a valid empty space with at least one neighbor
						//is the opponent game piece, and the corresponding direction has the player's game piece at end
						v[i] = blk;//change the empty gp to player a's gp
						hasvalidmove = false;//switch out of the while loop
						for (int m : change) {
							v[m] = blk;//change all the corresponding gp within the vector of index between to blk
						}
						whoseturn = !whoseturn;
						print();
					}
					else
					{
						//prompt for a valid move
						cout << "Choose a valid move." << endl;
					}
				}
				else {
					cout << "Choose an empty square to move." << endl;
				}
			}
			
		}
	}
	else {
		//a very similar game logic as described above but change the player a's method to b's method
		if (!validmoveforb()) {
			cout << playerB << ", you do not have a valid place to put your coin for this round." << endl;
			whoseturn = !whoseturn;
			++moves;
			return turn();
		}
		else {
			while (hasvalidmove) {
				try {
					cout << playerB << ", where do you want to put your coin?" << endl;
					prompt(col, row);
				}
				catch (results_code quit_error) {//check if the user type quit or not
					throw quit_error;
				}
				int i = col * 8 + row;
				vector<int> change;
				if (v[i].op_ == empty.op_) {
					if (checkMe(i, change)) {
						v[i] = wt;
						hasvalidmove = false;
						for (int m : change) {
							v[m] = wt;
						}
						whoseturn = !whoseturn;
						print();
					}
					else
					{
						cout << "Choose a valid move." << endl;
					}
				}
				else {
					cout << "Choose an empty square to move." << endl;
				}

			}
		}
	}
}
bool reversi::stalemate() {// check if the game stucked there or not. 
	//return true if both (1) there are the same number of black pieces 
	//and white pieces on the board and (2) either of the following is true: 
	//(a) all squares are filled; or (b) there are no 
	//remaining legal moves for either player; otherwise the method should return false.
	gp blk(black, "Alice", "X");
	gp wt(white, "Bob", "O");
	gp empty(no_color, "empty", " ");
	int pfora = 0;
	int pforb = 0;
	int blank = 0;
	for (int i = 0;i < 8;++i) {
		for (int j = 0;j < 8;++j) {
			if (v[i * 8 + j].op_ == blk.op_) {
				++pfora;
			}
			else if (v[i * 8 + j].op_ == wt.op_) {
				++pforb;
			}
			else ++blank;
		}
	}
	if ((pfora == pforb) && ((blank == 0) || (validmovefora() == false && validmoveforb() == false))) {
		cout << "game stucked" << endl;
		return true;
	}
	else return false;
}
//done() method return true if either
//(1) all pieces on the board are of the same color, or 
//(2) there are more pieces of one color than another color on the board and either of the following is true: 
//(a)all squares are filled; or (b)there are no remaining legal moves for either player
//otherwise return false
bool reversi::done() {
	gp blk(black, "Alice", "X");
	gp wt(white, "Bob", "O");
	gp empty(no_color, "empty", " ");
	int pfora = 0;
	int pforb = 0;
	int blank = 0;
	string winner;
	if (!whoseturn) winner = playerA;
	else winner = playerB;
	for (int i = 0;i < 8;++i) {
		for (int j = 0;j < 8;++j) {
			if (v[i * 8 + j].op_ == blk.op_) {
				++pfora;
			}
			else if (v[i * 8 + j].op_ == wt.op_) {
				++pforb;
			}
			else ++blank;
		}
	}
	if (pfora == 64 || pforb == 64) {
		cout << winner << "!!!" << endl;
		return true;
	}
	else if (blank == 0 || (validmovefora() == false && validmoveforb() == false)) {
		if (pfora != pforb) { 
			cout << winner << "!!!" << endl;
			return true; 
		}
		else return false;
	}
	else return false;
}
//check if there are valid moves on the board for player a
bool reversi::validmovefora() {
	gp blk(black, "Alice", "X");
	gp wt(white, "Bob", "O");
	gp empty(no_color, "empty", " ");
	for (int i = 0;i < 8;++i) {
		for (int j = 0;j < 8;++j) {
			int index = 8 * i + j;
			if (v[index].op_ == blk.op_) {
				//if a game piece is blk, check its neighbors, if it has white neighbor and in that direction
				//with continguous white game pieces
				//there must be an empty at the end to let the player use
				//so that there are valid moves for player a
				if (checkaneibor(index,blk)) {
					return true;
				}
			}
		}
	}
	return false;
}
//check if there are valid moves on the board for player b
bool reversi::validmoveforb() {
	gp blk(black, "Alice", "X");
	gp wt(white, "Bob", "O");
	gp empty(no_color, "empty", " ");
	for (int i = 0;i < 8;++i) {
		for (int j = 0;j < 8;++j) {
			int index = 8 * i + j;
			if (v[index].op_ == wt.op_) {
				//if a game piece is wt, check its neighbors, if it has blk neighbor and in that direction
				//with continguous blk game pieces
				//there must be an empty at the end to let the player use
				//so that there are valid moves for player b
				if (checkaneibor(index, wt)) {
					return true;
				}
			}
		}
	}
	return false;
}
//used in checking valid moves for players 
//if a game piece is wt/blk, check its neighbors, if it has blk/wt neighbor and in that direction
//with continguous blk/wt game pieces
//there must be an empty at the end to let the player use
//so that there are valid moves for player b/a
bool reversi::checkaneibor(int index,gp use) {
	string enemy_op;
	if (use.op_ == "X") {
		enemy_op = "O";
	}
	else {
		enemy_op = "X";
	}
	gp blk(black, "Alice", "X");
	gp wt(white, "Bob", "O");
	gp empty(no_color, "empty", " ");
	int i = index / 8;
	int j = index % 8;
	int xup, xlow, yup, ylow;
	if (i == 0) {
		ylow = i;
		yup = i + 1;
	}
	else if (i == 7) {
		ylow = i - 1;
		yup = i;
	}
	else {
		yup = i + 1;
		ylow = i - 1;
	}
	if (j == 0) {
		xup = j + 1;
		xlow = j;
	}
	else if (j == 7) {
		xup = j;
		xlow = j - 1;
	}
	else {
		xup = j + 1;
		xlow = j - 1;
	}
	// get the corresponding neighbor boundary data for a game piece
	for (int m = ylow;m < yup+1;++m) {
		for (int k = xlow;k < xup+1;++k) {
			int neibor = 8 * m + k;
			if(v[neibor].op_ == enemy_op) {//check if the neighbor is enemy neighbor
				if (checkneibor(index, neibor,use)) {//check if in that direction there is an empty space at the end
					//then return true
					return true;
				}
			}
		}
	}
	return false;
}
//check the neighbors recursively in a set direction to find if there is an empty space at the end or not
bool reversi::checkneibor(int index, int neibor,gp use) {
	string enemy_op;
	if (use.op_ == "X") {
		enemy_op = "O";
	}
	else {
		enemy_op = "X";
	}
	gp blk(black, "Alice", "X");
	gp wt(white, "Bob", "O");
	gp empty(no_color, "empty", " ");
	int i = neibor / 8;
	int j = neibor % 8;
	int xup, xlow, yup, ylow;
	if (i == 0) {
		ylow = i;
		yup = i + 1;
	}
	else if (i == 7) {
		ylow = i - 1;
		yup = i;
	}
	else {
		yup = i + 1;
		ylow = i - 1;
	}
	if (j == 0) {
		xup = j + 1;
		xlow = j;
	}
	else if (j == 7) {
		xup = j;
		xlow = j - 1;
	}
	else {
		xup = j + 1;
		xlow = j - 1;
	}
	int nextneibor = neibor + (neibor - index);
	for (int m = ylow;m < yup+1;++m) {
		for (int k = xlow;k < xup+1;++k) {
			if (nextneibor == m * 8 + k) {
				if (v[nextneibor].op_ == enemy_op) {
					//recursively check the neighbor in that direction if the next neighbor is still enemy
					return checkneibor(neibor, nextneibor, use);
				}
				else if (v[nextneibor].op_ == empty.op_) {
					//if there is an empty at the end return true
					return true;
				}
				else return false;
			}
		}
	}
	return false;
}
//check the space is a valid empty space with at least one neighbor
//is the opponent game piece, and the corresponding direction has the player's game piece at end
bool reversi::checkMe(int index, vector<int>& change) {
	gp blk(black, "Alice", "X");
	gp wt(white, "Bob", "O");
	gp empty(no_color, "empty", " ");
	int i = index / 8;
	int j = index % 8;
	gp use = empty;
	if (whoseturn) use = blk;
	else use = wt;
	int xup, xlow, yup, ylow;
	if (i == 0) {
		ylow = i;
		yup = i + 1;
	}
	else if (i == 7) {
		ylow = i - 1;
		yup = i;
	}
	else {
		yup = i + 1;
		ylow = i - 1;
	}
	if (j == 0) {
		xup = j + 1;
		xlow = j;
	}
	else if (j == 7) {
		xup = j;
		xlow = j - 1;
	}
	else {
		xup = j + 1;
		xlow = j - 1;
	}
	string enemy_op;
	if (use.op_ == "X") {
		enemy_op = "O";
	}
	else {
		enemy_op = "X";
	}
	for (int m = ylow;m < yup+1;++m) {
		for (int k = xlow;k < xup+1;++k) {
			int neibor = 8 * m + k;
			if (v[neibor].op_== enemy_op) {
				if (checkNeighbor(index, neibor,use)) {//check if the enemy space direction has the player's piece at end
					
					int a = neibor;
					while (v[neibor].op_ ==enemy_op) {
						//add the satisfied enemy game index to the vector of int 
						change.push_back(neibor);
						neibor += a - index;
					}
				}
			}
		}
	}
	return !change.empty();//if the change vector is added then return true, otherwise return false

}
// a method that check the corresponding direction to see if there is a continguous series of 
//enemy and a player's game piece at the end
bool reversi::checkNeighbor(int index, int coor, gp use) {
	gp blk(black, "Alice", "X");
	gp wt(white, "Bob", "O");
	gp empty(no_color, "empty", " ");
	gp enemy = empty;
	if (use.op_ == blk.op_) enemy = wt;
	else enemy = blk;
	int i = coor / 8;
	int j = coor % 8;
	int xup, xlow, yup, ylow;
	if (i == 0) {
		ylow = i;
		yup = i + 1;
	}
	else if (i == 7) {
		ylow = i - 1;
		yup = i;
	}
	else {
		yup = i + 1;
		ylow = i - 1;
	}
	if (j == 0) {
		xup = j + 1;
		xlow = j;
	}
	else if (j == 7) {
		xup = j;
		xlow = j - 1;
	}
	else {
		xup = j + 1;
		xlow = j - 1;
	}
	int nextneibor = coor + (coor - index);
	for (int m = ylow;m < yup + 1;++m) {
		for (int k = xlow;k < xup + 1;++k) {
			if (nextneibor == m * 8 + k) {
				if (v[nextneibor].op_ == enemy.op_) {
					return checkNeighbor(coor, nextneibor, use);
				}
				else if (v[nextneibor].op_ == use.op_) {
					return true;
				}
				else {
					return false;
				}
			}
		}
	}
	return false;
}
