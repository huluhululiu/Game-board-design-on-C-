#ifndef GAMEP_H
#define GAMEP_H

#include <vector>
#include <string>
#include <cstring>
#include <iostream>
using namespace std;

enum piece_color { red, black, white, brown, invalid_color, no_color };

enum piece_color stringtoenum(string v);
string enumtostring(enum piece_color colour);
void lower(string& cool);
struct gp {
	gp(enum piece_color a, string name, string op);
	piece_color color_;
	string name_;
	string op_;

};

#endif