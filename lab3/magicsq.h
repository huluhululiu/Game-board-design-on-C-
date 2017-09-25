#ifndef MAGICSQ_H
#define MAGICSQ_H

#include <vector>
#include <string>
#include "gamep.h"
#include "gamebase.h"
#include <iostream>
#include "gameb.h"

using namespace std;

class magicsquare :public gamebase {
	friend ostream &operator<<(ostream &out, const magicsquare &a);
public:
	
	//a default constructor of magic square that has a default size of 3 and start number of 1
	magicsquare(int a=3, int b = 1);
	virtual void print() override;
	virtual bool done();
	virtual bool stalemate();
	virtual void turn();
	virtual void prompt(unsigned &a);
	bool contain(gp a);
	void nextmove(int piece);
	int stringtonum(string m);
	
private:
	vector<int> nums;
	int startnumber;
};

void printpiece(vector<int> nums);
#endif