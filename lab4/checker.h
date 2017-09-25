#ifndef CHECKER_H
#define CHECKER_H

#include <vector>
#include <string>
#include "gamep.h"
#include "gamebase.h"
#include <iostream>
#include "gameb.h"

using namespace std;

class checker :public gamebase {
	friend ostream &operator<<(ostream &out, const checker &a);
public:

	//a default constructor of magic square that has a default size of 3 and start number of 1
	checker(string a = "Alice", string b = "Bob");
	virtual void print() override;
	virtual bool done();
	virtual bool stalemate();
	virtual void turn();
	bool validmovefora();
	bool validmoveforb();
	bool checkNeighbor(int index, int coor, gp use);
	bool checkMe(int index, gp use);
	bool checkaneibor(int index, gp use);
	bool checkneibor(int index, int neibor, gp use);
	bool hasmove(int i, gp use);
	void second(unsigned col, unsigned row,int index);
	void third(unsigned coll, unsigned roww,int index);
private:
	string playerA;
	string playerB;
};

#endif
