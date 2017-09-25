#ifndef GAMEBASE_H
#define GAMEBASE_H

#include <vector>
#include <string>
#include <iostream>
#include <memory>
#include "gameb.h"
#include "gamep.h"
using namespace std;
class gamebase {
public:
	gamebase(int, int, int);
	static void gamestart(int argc, char* argv[]);
	virtual void print() = 0;
	virtual bool done() = 0;
	virtual bool stalemate() = 0;;
	virtual void prompt(unsigned & col, unsigned & row);
	virtual void turn() = 0;
	virtual int play();
	virtual void savegame();
	static shared_ptr<gamebase> instance();
protected:
	unsigned int cols;
	unsigned int rows;
	vector<gp> v;
	int moves;
	unsigned int long_string;
	string gamename;
	static shared_ptr<gamebase> ptrgbase;
	bool whoseturn;//true for alice, false for bob,true for the other two games
};

#endif
