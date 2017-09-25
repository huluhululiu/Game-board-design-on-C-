

#ifndef GAMEPIECE_H
#define GAMEPIECE_H
#include <vector>
#include <string>
#include <cstring>
#include <iostream>
//#include "stdafx.h"											//don't include this in header files
using namespace std;
enum piece_color { red,black,white,invalid_color, no_color };
// Function prototypes
int usage(char * program_name);
enum piece_color stringtoenum(string v);
struct gp {
	gp(enum piece_color a,string name,string op);
	piece_color color_;
	string name_;
	string op_;

};

#endif