#include "stdafx.h"
#include "lab4.h"
#include "gamep.h"
#include "gamebase.h"
#include "magicsq.h"
#include "gameb.h"
#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <iomanip>
#include <algorithm>
#include <set>
using namespace std;
//the constructor for the magic square game with default setting a=3 and b=1
magicsquare::magicsquare(int a, int b) : gamebase(a, a, b - 1) {
	whoseturn = true;
	gamename = "magicsquare";
	gp empty(no_color, "empty", " ");
	long_string = 0;
	startnumber = b;
	//push back the empty game pieces into the game board
	for (int i = b - 1;i < a*a + b - 1;++i) {
		nums.insert(i + 1);
	}
	for (int i = 0; i < a; ++i)
	{
		for (int j = 0; j < a; ++j)
		{
			v.push_back(empty);
		}
	}
	ifstream ifs(gamename);
	if (ifs.is_open()) {
		string c;
		if (getline(ifs, c)) {
			if (c == gamename) {
				getline(ifs, c);
				istringstream iss1(c);
				if (iss1 >> moves >> long_string >> whoseturn) {
					string line;
					while (getline(ifs, line)) {

						istringstream iss(line);
						string color;
						string name;
						string op;
						unsigned int x;
						unsigned int y;
						if (iss >> color >> name >> op >> x >> y)
						{
							gp np(stringtoenum(color), name, op);
							v[a*x + y] = np;
							int number = stringtonum(op);
							int gap = number - startnumber;
							nums.erase(number);
						}
					}
				}
				else throw readyes_extractno;
			}

			else if (c == "NO DATA") {
				for (int i = 0; i < a; ++i)
				{
					for (int j = 0; j < a; ++j)
					{
						v[a*i + j] = empty;
					}
				}
				
			}
			else {
				cout << "No valid lines in the file." << endl;
				throw readyes_extractno;
			}
		}
	}
	else {
		for (int i = 0; i < a; ++i)
		{
			for (int j = 0; j < a; ++j)
			{
				v[a*i+j]=empty;
			}
		}
	
	}
	//pushback the numbers starting with start number into the vector of integer
	
}

ostream &operator<<(ostream &out, const magicsquare &a)
{
	try {
		printboard(out, a.long_string, a.v, a.cols, a.rows);
		//print out the available gamepieces
		printpiece(a.nums);
	}
	catch (results_code) {
		throw;
	}

	return out;
}
void printpiece(set<int> nums)
{
	ostringstream oss;
	cout << "Available pieces: ";
	//print out available game pieces
	for (int i : nums) {
			cout << i << " ";
	}
}
void magicsquare::print() {
	try
	{
		std::cout << *this << endl;
	}
	catch (results_code) {
		throw;
	}
}
bool magicsquare::done() {
	for (unsigned int i = 0;i < cols*rows;++i) {
		if (v[i].op_ == " ")
		{
			return false;
		}
	}
	//the magic sum is set corresponding to different game board size and start number value
	int sum = (1 + cols*cols)*cols / 2 + cols*(startnumber - 1);
	//check the row sums
	for (unsigned int i = 0; i < rows;i++) {
		int rowsum = 0;
		for (unsigned int j = 0;j < rows;j++) {
			rowsum += stringtonum(v[i*rows + j].op_);

		}
		if (rowsum != sum) return false;
	}
	//check the col sums
	for (unsigned int i = 0; i < cols;i++) {
		int colsum = 0;
		for (unsigned int j = 0;j < rows;j++) {
			colsum += stringtonum(v[i + rows* j].op_);
		}
		if (colsum != sum) return false;
	}
	//check the diagonal sums one is left sum, the other is right sum
	int diasuml = 0;
	int diasumr = 0;
	for (unsigned int i = 0; i < cols;i++) {
		diasuml += stringtonum(v[i*rows + i].op_);
	}
	if (diasuml != sum) return false;
	for (unsigned int i = 0; i < cols;i++) {
		diasumr += stringtonum(v[i*rows + rows - i - 1].op_);
	}
	if (diasumr != sum) return false;
	return true;


}
bool magicsquare::stalemate() {
	//check for stale mate, if any game piece is empty, return false
	for (unsigned int i = 0;i < cols*rows;++i) {
		if (v[i].op_ == " ")
		{
			return false;
		}
	}
	//else if done is not satisfied, return the reverse result of done()
	return (!done());
}
void magicsquare::prompt(unsigned &a) {
	cout << "Please enter an available piece number or quit.\n" << endl;
	string r;
	int inputnum = 0;
	getline(cin, r);
	//check for user's input and check if it is quit or not
	if (r == "quit")
	{
		throw quit_error;
	}
	istringstream iss(r);
	// then convert the user's input into an integer
	if (!(iss >> inputnum))
	{
		//cout << "aww" << endl;
		cout << "This piece number is invalid." << endl;
		return prompt(a);
	}
	int k = rows*cols;
	//check the integer is within the game piece range and check if that game piece is still available or not
	if ((inputnum >= startnumber) && (inputnum <= k + startnumber - 1)&& find(nums.begin(), nums.end(), inputnum) != nums.end()) {
		a = inputnum;
		nums.erase(inputnum);
	}
	else {
		cout << "This piece number is invalid." << endl;
		return prompt(a);
	}
}
int magicsquare::stringtonum(string a) {
	int value;
	istringstream iss(a);
	if (!(iss >> value)) {
		throw notanum;
	}
	return value;
}
//check which game piece number the user what to play with, if that game number is not valid, 
//ask for a new valid game piece number, if valid, then ask for a coordinate
void magicsquare::turn() {
	unsigned int piece = 0;
	try {
		cout << "Which piece do you want to move?" << endl;
		prompt(piece);

	}
	catch (results_code quit_error) {//check if the user type quit or not
		throw quit_error;
	}
	return nextmove(piece);
}
//prompt the user for an input of coordinates and update the coordinates to move the game piece
void magicsquare::nextmove(int piece) {
	unsigned int x = 0;
	unsigned int y = 0;
	cout << "Where do you want to move that game piece to on the game board?\n" << endl;
	cout << "Enter the coordinates" << endl;
	try {
		gamebase::prompt(y, x);
	}
	catch (results_code quit_error) {//check if the user type quit or not
		throw quit_error;
	}
	unsigned index = y*rows + x;
	//check if that place on the game board contains a game piece or not
	if (contain(v[index]))
	{
		cout << "Invalid coordinate. Select another coordinate\n" << endl;
		return nextmove(piece);
	}
	//convert the piece number into a string and update the long string length if the new game piece has a length that
	//is longer than the original long_string
	string game_p = to_string(piece);
	if (int(game_p.size()) > long_string)
	{
		long_string = game_p.size();
	}
	//make a new gamepiece with no color, but with an output and a name that is the same as the game piece number
	gp newnum = gp(no_color, game_p, game_p);
	//update the game board and set the new game piece onto the board
	v[index] = newnum;
	//remove the game piece number from available pieces
	magicsquare::print();

}
//check if the game board contains that game piece or not
bool magicsquare::contain(gp a) {
	return !(a.op_ == " ");
}
