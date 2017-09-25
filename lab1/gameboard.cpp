#include "stdafx.h"
#include "gameb.h"
#include "gamepiece.h"
//#include <ctype.h>
#include <iostream>
#include <string>   // For standard C++ strings.
#include <sstream>  // For standard string streams.
#include <cstring>  // For C-style string functions
#include <vector>
#include <fstream>
#include "lab1.h"
using namespace std;
int readdim(ifstream& v, unsigned int& a, unsigned int& b) {
		//read the dimension of the game board. two numbers, a and b. return read yes but extract
	//no if the get line info is not desired.return bad file when file is unreadable
		string local;
		if (getline(v, local)) {
			if (!local.empty()) {
				istringstream iss(local);
				if (iss >> a >> b) {
					return success;
				}
				else return readyes_extractno;
			}
			else return readyes_extractno;
		}
		else return file_open_failed;


}
int readgame(ifstream &v, vector<gp> & piece,unsigned int hori, unsigned int verti) {
	// read the game pieces by color, name, output string, and its coordinates.
	//if color or dimensions is not within our range, we can ignore the piece.
	string line;
	int n = 0;
	while (getline(v, line)) {
		
		istringstream iss(line);
		
		string color;
		string name; 
		string op;
		unsigned int x;
		unsigned int y;
		if (iss>>color>>name>>op>>x>>y)
		{
			lower(color);
			if ((x < hori)&& (y < verti)&&(stringtoenum(color)<3))
			{
				lower(op);
				gp np(stringtoenum(color), name, op);
				piece[hori*y + x] = np;
				++n;
			}

		}
	}
	if (n > 0) return success;
	else {
		
		return file_open_failed;
	}
}
int printboard(const vector<gp> & piece, unsigned int x, unsigned int y) {
	// print out every game pieces after we check the vector size of pieces is within the range of
	// the dimensions we read previously
	if (piece.size() <= x*y) {
		for ( int i = y-1;i >= 0;--i) {
			for (unsigned int j = 0;j < x;++j) {
				
				cout << piece[x*i+j].op_;
			}
			cout << "\n";
		}
		return success;
	}
	return unmatchvector_dim;
}
int adjacent(const vector<gp> & piece, unsigned int x, unsigned int y) {
	//print out the neighbors
	string r[] = { "red","black","white","\0","\0","\0" };
	if (piece.size() <= x*y) {
		for (int i = y - 1;i >= 0;--i) {
			for (unsigned int j = 0;j < x;++j) {
				if (piece[x * i + j].color_ != no_color) {
					cout << j << ", " << i << " " << r[piece[x * i + j].color_] << " " << piece[x*i + j].name_ << ": ";
					if (i == y - 1) {
						if (j == 0) {
							if (piece[x * i + (j + 1)].color_ != no_color)cout << (j + 1) << ", " << i << " " << r[piece[x * i + (j + 1)].color_] << " " << piece[x * i + (j + 1)].name_ << "; ";
							if (piece[x * (i - 1) + j].color_ != no_color)cout << j << ", " << (i - 1) << " " << r[piece[x * (i - 1) + j].color_] << " " << piece[x * (i - 1) + j].name_ << "; ";
							if (piece[x * (i - 1) + (j + 1)].color_ != no_color)cout << j + 1 << ", " << (i - 1) << " " << r[piece[x * (i - 1) + (j + 1)].color_] << " " << piece[x * (i - 1) + (j + 1)].name_ << "; ";
							cout << "\n";
						}
						else if (j == x - 1) {
							if (piece[x * (i - 1) + j].color_ != no_color)cout << j << ", " << (i - 1) << " " << r[piece[x * (i - 1) + j].color_] << " " << piece[x * (i - 1) + j].name_ << "; ";
							if (piece[x * (i - 1) + (j - 1)].color_ != no_color)cout << (j - 1) << ", " << (i - 1) << " " << r[piece[x * (i - 1) + (j - 1)].color_] << " " << piece[x * (i - 1) + (j - 1)].name_ << "; ";
							if (piece[x * i + (j - 1)].color_ != no_color)cout << (j - 1) << ", " << i << " " << r[piece[x * i + (j - 1)].color_] << " " << piece[x * i + (j - 1)].name_ << "; ";
							cout << "\n";
						}
						else {
							if (piece[x * i + (j - 1)].color_ != no_color)cout << (j - 1) << ", " << i << " " << r[piece[x * i + (j - 1)].color_] << " " << piece[x * i + (j - 1)].name_ << "; ";
							if (piece[x * i + (j + 1)].color_ != no_color)cout << (j + 1) << ", " << i << " " << r[piece[x * i + (j + 1)].color_] << " " << piece[x * i + (j + 1)].name_ << "; ";
							if (piece[x * (i - 1) + (j - 1)].color_ != no_color)cout << (j - 1) << ", " << (i - 1) << " " << r[piece[x * (i - 1) + (j - 1)].color_] << " " << piece[x * (i - 1) + (j - 1)].name_ << "; ";
							if (piece[x * (i - 1) + j].color_ != no_color)cout << j << ", " << (i - 1) << " " << r[piece[x * (i - 1) + j].color_] << " " << piece[x * (i - 1) + j].name_ << "; ";
							if (piece[x * (i - 1) + (j + 1)].color_ != no_color)cout << j + 1 << ", " << (i - 1) << " " << r[piece[x * (i - 1) + (j + 1)].color_] << " " << piece[x * (i - 1) + (j + 1)].name_ << "; ";
							cout << "\n";
						}
					}
					if (i == 0) {
						if (j == 0) {
							if (piece[x * (i + 1) + j + 1].color_ != no_color)cout << (j + 1) << ", " << (i + 1) << " " << r[piece[x * (i + 1) + j + 1].color_] << " " << piece[x * (i + 1) + j + 1].name_ << "; ";
							if (piece[x * i + j + 1].color_ != no_color)cout << (j + 1) << ", " << i << " " << r[piece[x * i + j + 1].color_] << " " << piece[x * i + j + 1].name_ << "; ";
							if (piece[x * (i + 1) + j].color_ != no_color)cout << j << ", " << (i + 1) << " " << r[piece[x * (i + 1) + j].color_] << " " << piece[x * (i + 1) + j].name_ << "; ";
							cout << "\n";
						}
						else if (j == x - 1) {
							if (piece[x * (i + 1) + j].color_ != no_color)cout << j << ", " << (i + 1) << " " << r[piece[x * (i + 1) + j].color_] << " " << piece[x * (i + 1) + j].name_ << "; ";
							if (piece[x * (i + 1) + j - 1].color_ != no_color)cout << (j - 1) << ", " << (i + 1) << " " << r[piece[x * (i + 1) + j - 1].color_] << " " << piece[x * (i + 1) + j - 1].name_ << "; ";
							if (piece[x * i + j - 1].color_ != no_color)cout << (j - 1) << ", " << i << " " << r[piece[x * i + j - 1].color_] << " " << piece[x * i + j - 1].name_ << "; ";
							cout << "\n";
						}

						else {

							if (piece[x * i + j + 1].color_ != no_color)cout << (j + 1) << ", " << i << " " << r[piece[x * i + j + 1].color_] << " " << piece[x * i + j + 1].name_ << "; ";
							if (piece[x * (i + 1) + j].color_ != no_color)cout << j << ", " << (i + 1) << " " << r[piece[x * (i + 1) + j].color_] << " " << piece[x * (i + 1) + j].name_ << "; ";
							if (piece[x * (i + 1) + j + 1].color_ != no_color)cout << (j + 1) << ", " << (i + 1) << " " << r[piece[x * (i + 1) + j + 1].color_] << " " << piece[x * (i + 1) + j + 1].name_ << "; ";
							if (piece[x * (i + 1) + j - 1].color_ != no_color)cout << (j - 1) << ", " << (i + 1) << " " << r[piece[x * (i + 1) + j - 1].color_] << " " << piece[x * (i + 1) + j - 1].name_ << "; ";
							if (piece[x * i + j - 1].color_ != no_color)cout << (j - 1) << ", " << i << " " << r[piece[x * i + j - 1].color_] << " " << piece[x * i + j - 1].name_ << "; ";
							cout << "\n";
						}
					}
					if ((j == 0)&&(i!=0)&&(i!=y-1)) {
						
							if (piece[x * i + j + 1].color_ != no_color)cout << (j + 1) << ", " << i << " " << r[piece[x * i + j + 1].color_] << " " << piece[x * i + j + 1].name_ << "; ";
							if (piece[x * (i + 1) + j].color_ != no_color)cout << j << ", " << (i + 1) << " " << r[piece[x * (i + 1) + j].color_] << " " << piece[x * (i + 1) + j].name_ << "; ";
							if (piece[x * (i - 1) + j].color_ != no_color)cout << j << ", " << (i - 1) << " " << r[piece[x * (i - 1) + j].color_] << " " << piece[x * (i - 1) + j].name_ << "; ";
							if (piece[x * (i + 1) + j + 1].color_ != no_color)cout << (j + 1) << ", " << (i + 1) << " " << r[piece[x * (i + 1) + j + 1].color_] << " " << piece[x * (i + 1) + j + 1].name_ << "; ";
							if (piece[x * (i - 1) + (j + 1)].color_ != no_color)cout << j + 1 << ", " << (i - 1) << " " << r[piece[x * (i - 1) + (j + 1)].color_] << " " << piece[x * (i - 1) + (j + 1)].name_ << ";";
							cout << "\n";
					}
					if (j == x - 1&&i != 0 && i != y - 1) {
						

							if (piece[x * (i + 1) + j].color_ != no_color)cout << j << ", " << (i + 1) << " " << r[piece[x * (i + 1) + j].color_] << " " << piece[x * (i + 1) + j].name_ << "; ";
							if (piece[x * (i - 1) + (j - 1)].color_ != no_color)cout << (j - 1) << ", " << (i - 1) << " " << r[piece[x * (i - 1) + (j - 1)].color_] << " " << piece[x * (i - 1) + (j - 1)].name_ << "; ";
							if (piece[x * (i - 1) + j].color_ != no_color)cout << j << ", " << (i - 1) << " " << r[piece[x * (i - 1) + j].color_] << " " << piece[x * (i - 1) + j].name_ << "; ";
							if (piece[x * (i + 1) + j - 1].color_ != no_color)cout << (j - 1) << ", " << (i + 1) << " " << r[piece[x * (i + 1) + j - 1].color_] << " " << piece[x * (i + 1) + j - 1].name_ << "; ";
							if (piece[x * i + j - 1].color_ != no_color)cout << (j - 1) << ", " << i << " " << r[piece[x * i + j - 1].color_] << " " << piece[x * i + j - 1].name_ << "; ";
							cout << "\n";
					}
					if ((j != x - 1) && (j != 0) && (i != 0) && (i != y - 1)) {
						if (piece[x * i + (j + 1)].color_ != no_color)cout << (j + 1) << ", " << i << " " << r[piece[x * i + (j + 1)].color_] << " " << piece[x * i + (j + 1)].name_ << "; ";
						if (piece[x * (i - 1) + j].color_ != no_color)cout << j << ", " << (i - 1) << " " << r[piece[x * (i - 1) + j].color_] << " " << piece[x * (i - 1) + j].name_ << "; ";
						if (piece[x * (i - 1) + (j + 1)].color_ != no_color)cout << j + 1 << ", " << (i - 1) << " " << r[piece[x * (i - 1) + (j + 1)].color_] << " " << piece[x * (i - 1) + (j + 1)].name_ << "; ";
						if (piece[x * (i - 1) + (j - 1)].color_ != no_color)cout << (j - 1) << ", " << (i - 1) << " " << r[piece[x * (i - 1) + (j - 1)].color_] << " " << piece[x * (i - 1) + (j - 1)].name_ << "; ";
						if (piece[x * i + (j - 1)].color_ != no_color)cout << (j - 1) << ", " << i << " " << r[piece[x * i + (j - 1)].color_] << " " << piece[x * i + (j - 1)].name_ << "; ";
						if (piece[x * (i + 1) + j + 1].color_ != no_color)cout << (j + 1) << ", " << (i + 1) << " " << r[piece[x * (i + 1) + j + 1].color_] << " " << piece[x * (i + 1) + j + 1].name_ << "; ";
						if (piece[x * (i + 1) + j].color_ != no_color)cout << j << ", " << (i + 1) << " " << r[piece[x * (i + 1) + j].color_] << " " << piece[x * (i + 1) + j].name_ << "; ";
						if (piece[x * (i + 1) + j - 1].color_ != no_color)cout << (j - 1) << ", " << (i + 1) << " " << r[piece[x * (i + 1) + j - 1].color_] << " " << piece[x * (i + 1) + j - 1].name_ << "; ";
						cout << "\n";
					}
				}
				
			}
			
		}
		return success;
	}
	return unmatchvector_dim;
}