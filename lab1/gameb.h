#ifndef GAMEB_H
#define GAMEB_H
#include "gamepiece.h"
#include "gameb.h"
#include "lab1.h"
#include <vector>
#include <string>
#include <cstring>
#include <iostream>
#include <fstream>
using namespace std;

int readdim(ifstream& v,unsigned int& a,unsigned int& b);
int readgame(ifstream &v, vector<gp> & a, unsigned int hori, unsigned int verti);
int printboard(const vector<gp> & piece, unsigned int x, unsigned int y);
int adjacent(const vector<gp> & piece, unsigned int x, unsigned int y);
#endif
