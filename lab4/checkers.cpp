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
#include "checker.h"
using namespace std;
checker::checker(string a, string b) : gamebase(8, 8, 0) {
	playerA = a;
	playerB = b;
	gamename = "Checker";
	long_string = 1;
	ifstream ifs(gamename);
	gp blk(black, "Alice", "X");
	gp wt(white, "Bob", "O");
	gp empty(no_color, "empty", " ");
	gp nope(no_color, "nope", " ");
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
				for (int i = 0;i < 64;++i) {
					if (i % 2 ==1) { v[i] = nope; }
				}
				for (int i = 0;i<2;++i) {
					v[0 + i * 2] = wt;
					v[16 + i * 2] = wt;
					v[32 + i * 2] = wt;
					v[48 + i * 2] = wt;
				}
				for (int i = 0;i<2;++i) {
					v[13 + i * 2] = blk;
					v[29 + i * 2] = blk;
					v[45 + i * 2] = blk;
					v[61 + i * 2] = blk;
				}
				v[9] = wt;
				v[25] = wt;
				v[41] = wt;
				v[57] = wt;
				v[6] = blk;
				v[22] = blk;
				v[38] = blk;
				v[54] = blk;
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
		for (int i = 0;i < 64;++i) {
			if (i % 2 == 1) { v[i] = nope; }
		}
		for (int i = 0;i<2;++i) {
			v[0 + i * 2] = wt;
			v[16 + i * 2] = wt;
			v[32 + i * 2] = wt;
			v[48 + i * 2] = wt;
		}
		for (int i = 0;i<2;++i) {
			v[13 + i * 2] = blk;
			v[29 + i * 2] = blk;
			v[45 + i * 2] = blk;
			v[61 + i * 2] = blk;
		}
		v[9] = wt;
		v[25] = wt;
		v[41] = wt;
		v[57] = wt;
		v[6] = blk;
		v[22] = blk;
		v[38] = blk;
		v[54] = blk;
	}



}
ostream &operator<<(ostream &out, const checker &a) {
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
void checker::print() {//print out the game board
	try
	{
		std::cout << *this << endl;
	}
	catch (results_code a) {
		throw a;
	}
}
void checker::turn() {// the turn method checks whose turn it is and check corresponding player has valid move or not
					  // if no valid move on the board. changes to the other player
					  //if there are valid move but the user keeps on typing invalid moves, prompt the user for a valid move
	gp blk(black, "Alice", "X");
	gp wt(white, "Bob", "O");
	gp empty(no_color, "empty", " ");
	gp nope(no_color, "nope", " ");
	unsigned int col = 0;
	unsigned int row = 0;
	bool hasvalidmove = true;
	if (whoseturn) {
			while (hasvalidmove) {
				try {
					cout << playerA << ", where do you want to start?" << endl;
					prompt(col, row);
				}
				catch (results_code quit_error) {//check if the user type quit or not
					throw quit_error;
				}
				int i = col * 8 + row;
				if (v[i].name_ == blk.name_) {//check if the user choose an empty space or not
					if (checkMe(i, blk)) {//check the space is a valid empty space with at least one neighbor
										  //is the opponent game piece, and the corresponding direction has the player's game piece at end
						v[i] = empty;				  //change the empty gp to player a's gp
					
						unsigned int coll = 0;
						unsigned int roww=0;
						second(coll, roww,i);
						if (!hasmove(i, blk))
						{
							hasvalidmove = false;
							whoseturn = !whoseturn;
						}//switch out of the while loop
						print();
					}
					else
					{
						//prompt for a valid move
						cout << "Choose a valid move." << endl;
					}
				}
				else {
					cout << "Choose an X or B square to move." << endl;
				}
			}

		}
	
	else {
		//a very similar game logic as described above but change the player a's method to b's method
			while (hasvalidmove) {
				try {
					cout << playerB << ", where do you want to put your coin?" << endl;
					prompt(col, row);
				}
				catch (results_code quit_error) {//check if the user type quit or not
					throw quit_error;
				}
				int i = col * 8 + row;
				if (v[i].name_ == wt.name_) {//check if the user choose an empty space or not
					if (checkMe(i, wt)) {//check the space is a valid empty space with at least one neighbor
										  //is the opponent game piece, and the corresponding direction has the player's game piece at end
						v[i] = empty;				  //change the empty gp to player a's gp

						unsigned int coll=0;
						unsigned int roww=0;
						second(coll, roww, i);
						if (!hasmove(i, wt))
						{
							hasvalidmove = false;
							whoseturn = !whoseturn;
						}//switch out of the while loop
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
bool checker::stalemate() {// check if the game stucked there or not. 
						   //return true if both (1) there are the same number of black pieces 
						   //and white pieces on the board and (2) either of the following is true: 
						   //(a) all squares are filled; or (b) there are no 
						   //remaining legal moves for either player; otherwise the method should return false.
	gp blk(black, "Alice", "X");
	gp wt(white, "Bob", "O");
	gp empty(no_color, "empty", " ");
	gp nope(no_color, "nope", " ");
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
	if ((validmovefora() == false && validmoveforb() == false)) {
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
bool checker::done() {
	gp nope(no_color, "nope", " ");
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
	if (pfora == 0) {
		cout << "winner is " << playerB << endl;
		return true;
	}
	else if (pforb == 0) {
		cout << "winner is " << playerA << endl;
		return true;
	}
	else if (validmovefora() == false) {
		cout << "winner is " << playerB << endl;
		return true;
	}
	else if (validmoveforb() == false) {
		cout << "winner is " << playerA << endl;
		return true;
	}
	else return false;
}
//check if there are valid moves on the board for player a
bool checker::validmovefora() {
	gp nope(no_color, "nope", " ");
	gp blk(black, "Alice", "X");
	gp wt(white, "Bob", "O");
	gp empty(no_color, "empty", " ");
	gp b(black, "Alice", "B");
	gp w(white, "Bob", "W");
	for (int i = 0;i < 8;++i) {
		for (int j = 0;j < 8;++j) {
			int index = 8 * i + j;
			if (v[index].name_ == blk.name_) {
				//if a game piece is blk, check its neighbors, if it has white neighbor and in that direction
				//with continguous white game pieces
				//there must be an empty at the end to let the player use
				//so that there are valid moves for player a
				if (checkaneibor(index, blk)) {
					return true;
				}
			}
		}
	}
	return false;
}
//check if there are valid moves on the board for player b
bool checker::validmoveforb() {
	gp nope(no_color, "nope", " ");
	gp blk(black, "Alice", "X");
	gp wt(white, "Bob", "O");
	gp empty(no_color, "empty", " ");
	gp b(black, "Alice", "B");
	gp w(white, "Bob", "W");
	for (int i = 0;i < 8;++i) {
		for (int j = 0;j < 8;++j) {
			int index = 8 * i + j;
			if (v[index].name_ == wt.name_) {
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
bool checker::hasmove(int index, gp use) {
	gp nope(no_color, "nope", " ");
	gp blk(black, "Alice", "X");
	gp wt(white, "Bob", "O");
	gp empty(no_color, "empty", " ");
	gp b(black, "Alice", "B");
	gp w(white, "Bob", "W");
	string enemy_name;
	if (use.name_ == blk.name_) {
		enemy_name = "Bob";
	}
	else enemy_name = "Alice";
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
	for (int m = ylow;m < yup + 1;++m) {
		for (int k = xlow;k < xup + 1;++k) {
			int neibor = 8 * m + k;
			if (v[neibor].name_ != nope.name_) {
				if (v[neibor].name_ == enemy_name) {
					if (checkneibor(index, neibor, use)) {
						return true;
					}
				}
				else if (v[neibor].name_ == empty.name_) {
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
bool checker::checkaneibor(int index, gp use) {
	gp blk(black, "Alice", "X");
	gp wt(white, "Bob", "O");
	gp empty(no_color, "empty", " ");
	gp b(black, "Alice", "B");
	gp w(white, "Bob", "W");
	gp nope(no_color, "nope", " ");
	string enemy_name;
	if (use.name_ == blk.name_) {
		enemy_name = "Bob";
	}
	else enemy_name = "Alice";
	
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
	for (int m = ylow;m < yup + 1;++m) {
		for (int k = xlow;k < xup + 1;++k) {
			int neibor = 8 * m + k;
			if (v[neibor].name_ != nope.name_) {
				if (v[neibor].name_ == enemy_name) {//check if the neighbor is enemy neighbor
					if (checkNeighbor(index, neibor, use)) {//check if in that direction there is an empty space at the end						  //then return true
						return true;
					}
				}
				else if (v[neibor].name_ == empty.name_) {
					return true;
				}
			}
		}
	}
	return false;
}
//check the neighbors recursively in a set direction to find if there is an empty space at the end or not
bool checker::checkneibor(int index, int neibor, gp use) {

	gp blk(black, "Alice", "X");
	gp wt(white, "Bob", "O");
	gp empty(no_color, "empty", " ");
	gp b(black, "Alice", "B");
	gp w(white, "Bob", "W");
	gp nope(no_color, "nope", " ");
	string enemy_name;
	if (use.name_ == blk.name_) {
		enemy_name = "Bob";
	}
	else enemy_name = "Alice";
	if ((v[neibor].op_ != empty.op_)) {
		return false;
	}

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
	int roww = index / 8;
	int coll = index % 8;
	int mix = (i + roww) / 2;
	int miy = (j + coll) / 2;
	int mid = miy * 8 + mix;
	int nextneibor = neibor + (neibor - index);
	int dif = abs(neibor - index);
	if (v[index].op_ == "O") {
		if (dif == 7 && index < neibor) {
			return false;
		}
		if (dif == 9 && index > neibor) {
			return false;
		}
		xlow = j;
		ylow = i;
	}
	if (v[index].op_ == "X") {
		if (dif == 7 && index > neibor) {
			return false;
		}
		if (dif == 9 && index < neibor) {
			return true;
		}
		xup = j;
		xlow = i;
	}
	if (dif == 7 || dif == 9) {
		return true;
	}

	for (int m = ylow;m < yup + 1;m += 2) {
			for (int k = xlow;k < xup + 1;k += 2) {
					if (nextneibor == m * 8 + k) {
						if (v[nextneibor].name_ != nope.name_) {
							if (v[nextneibor].op_ == empty.op_) {
								//if there is an empty at the end return true
								return true;
							}
							else return false;
						}
				}
				

		}
	}
	return false;
}
//check the space is a valid empty space with at least one neighbor
//is the opponent game piece, and the corresponding direction has the player's game piece at end
bool checker::checkMe(int index, gp use) {
	gp blk(black, "Alice", "X");
	gp wt(white, "Bob", "O");
	gp empty(no_color, "empty", " ");
	gp b(black, "Alice", "B");
	gp w(white, "Bob", "W");
	gp nope(no_color, "nope", " ");
	string enemy_name;
	if (use.name_ == blk.name_) {
		enemy_name = "Bob";
	}
	else enemy_name = "Alice";
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
	if (v[index].op_ == "O") {
		xlow = j;
		ylow = i;
	}
	if (v[index].op_ == "X") {
		xup = j;
		xlow = i;
	}
	for (int m = ylow;m < yup + 1;++m) {
		for (int k = xlow;k < xup + 1;++k) {
			int neibor = 8 * m + k;
			if (v[neibor].name_ != nope.name_) {
				if (v[neibor].name_ == enemy_name) {
					if (checkneibor(index, neibor, use)) {//check if the enemy space direction has the player's piece at end
						return true;
					}
				}
				if (v[neibor].name_ == empty.name_) {
					return true;
				}
			}
		}
	}
	return false;//if the change vector is added then return true, otherwise return false

}
// a method that check the corresponding direction to see if there is a continguous series of 
//enemy and a player's game piece at the end
bool checker::checkNeighbor(int index, int coor, gp use) {
	gp blk(black, "Alice", "X");
	gp wt(white, "Bob", "O");
	gp empty(no_color, "empty", " ");
	gp b(black, "Alice", "B");
	gp w(white, "Bob", "W");
	gp nope(no_color, "nope", " ");
	string enemy_name;
	if (use.name_ == blk.name_) {
		enemy_name = "Bob";
	}
	else enemy_name = "Alice";
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
	if (v[index].op_ == "O") {
		xlow = j;
		ylow = i;
	}
	if (v[index].op_ == "X") {
		xup = j;
		xlow = i;
	}
	int neibor = coor;
	if (v[index].op_ == "O") {
		xlow = j;
		ylow = i;
	}
	if (v[index].op_ == "X") {
		
		xup = j;
		xlow = i;
	}
	int nextneibor = coor + (coor - index);
	for (int m = ylow;m < yup + 1;++m) {
		for (int k = xlow;k < xup + 1;++k) {
			if (nextneibor == m * 8 + k) {
				if (v[nextneibor].name_ != nope.name_) {
					if (v[nextneibor].op_ == empty.op_) {
						return true;
					}
					else {
						return false;
					}
				}
			}
		}
	}
	return false;
}
void checker::second(unsigned col, unsigned row,int index) {
	gp blk(black, "Alice", "X");
	gp wt(white, "Bob", "O");
	gp empty(no_color, "empty", " ");
	gp b(black, "Alice", "B");
	gp w(white, "Bob", "W");
	gp use = w;
	int king = 0;
	string enemy_name;
	if (whoseturn) {
		use = b;
		enemy_name = "Bob";
		king = 7;
	}
	else enemy_name = "Alice";
	try {
		std::cout << "what's your end piece?" << endl;
		prompt(col, row);
	}
	catch (results_code quit_error) {// check for quit input
		throw quit_error;
	}
	int i = col * 8 + row;
	int coll = index / 8;
	int roww = index % 8;
	if (checkneibor(index,i,use)) {
		std::cout << "Target piece invalid." << endl;//check if the end piece is an almond or not
		return second(col, row,index);
	}
	
	
	
	int mix = (row + roww) / 2;
	int miy = (col + coll) / 2;

	int mid = miy * 5 + mix;
	if ((row == king)&&(v[mid].op_==v[index].op_))
	{
		v[i] = use;
	}
	else {
		v[i] = v[index];
	}
	v[index] = empty;
	//update the mid piece to be empty and the start be empty and the end be almond
	v[mid] = empty;
	//update the game board and print out the gameboard
	std::cout << *this << endl;
	return third(coll, roww,i);

}
void checker::third(unsigned coll, unsigned roww,int index) {
	gp blk(black, "Alice", "X");
	gp wt(white, "Bob", "O");
	gp empty(no_color, "empty", " ");
	gp b(black, "Alice", "B");
	gp w(white, "Bob", "W");
	gp use = w;
	int king = 0;
	string enemy_name;
	if (whoseturn) {
		use = b;
		enemy_name = "Bob";
		king = 7;
	}
	else enemy_name = "Alice";
	if (done() || stalemate()) {
		return;
	}
	std::cout << "The piece has been moved to " << coll << " " << roww << endl;
	std::cout << "Continue to move?Type Y or N" << endl;
	string ans;
	//check if the user want to continue move the same almond or not
	getline(cin, ans);
	if (ans == "Y") {
		// ask for the new end piece
		return second(coll, roww,index);
	}
	if (ans == "N") {
		return;
	}
	else {
		std::cout << "Please type Y or N in upper case." << endl;
		return third(coll, roww,index);
	}

}