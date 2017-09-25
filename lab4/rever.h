#ifndef REVER_H
#define REVER_H

#include <vector>
#include <string>
#include "gamep.h"
#include "gamebase.h"
#include <iostream>
#include "gameb.h"

using namespace std;

class reversi :public gamebase {
	friend ostream &operator<<(ostream &out, const reversi &a);
public:

	//a default constructor of magic square that has a default size of 3 and start number of 1
	reversi(string a="Alice",string b="Bob");
	virtual void print() override;
	virtual bool done();
	virtual bool stalemate();
	virtual void turn();
	bool validmovefora();
	bool validmoveforb();
	bool checkNeighbor(int index, int coor,gp use);
	bool checkMe(int index, vector<int>& change);
	bool checkaneibor(int index,gp use);
	bool checkneibor(int index, int neibor,gp use);
private:
	string playerA;
	string playerB;
};

#endif
