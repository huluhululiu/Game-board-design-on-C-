#include "stdafx.h"
#include <ctype.h>
#include<iostream>
#include <string>   // For standard C++ strings.
#include <sstream>  // For standard string streams.
#include <cstring>  // For C-style string functions
#include <vector>
#include <fstream>
#include "gameb.h"
#include "gamep.h"
#include "gamebase.h"
//#include "lab2h.h"
using namespace std;

gp::gp(enum piece_color a, string name, string op)
	: color_(a), name_(name), op_(op) {}
//convert a string of color to a enum type of the color so that we can recognize valid and invalid
//colors
enum piece_color stringtoenum(string v) {
	if (v == "red") return red;
	if (v == "black") return black;
	if (v == "white") return white;
	int i = 0;
	int m = 0;
	int n = v.size();
	while (v[i]) {
		if (isspace(v[i])) m++;
		++i;
	}
	if (m == n) return no_color;
	else return invalid_color;
}
//convert a string of color to a enum type of the color so that we can recognize valid and invalid
//colors

string enumtostring(enum piece_color colour) {
	if (colour == red) return "red";
	if (colour == black) return "black";
	if (colour == white) return "white";
	if (colour == brown) return "brown";
	else return "nocolor";
}
void lower(string& cool) {// convert all uppercase in a string to lower
	int i = 0;

	while (cool[i]) {
		if (isalpha(cool[i])) {
			if (isupper(cool[i])) cool[i] = tolower(cool[i]);
		}
		++i;
	}
}