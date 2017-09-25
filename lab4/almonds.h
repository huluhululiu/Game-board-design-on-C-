#ifndef ALMONDS_H
#define ALMONDS_H

#include <vector>
#include <string>
#include "gamep.h"
#include "gamebase.h"
#include <iostream>
#include "gameb.h"

//using namespace std;

class almondgame :public gamebase {
	friend ostream &operator<<(ostream &out, const almondgame &a);
public:
	almondgame();
	virtual void print() override;
	virtual bool done();
	virtual bool stalemate();
	virtual void turn();
	void second(unsigned col, unsigned row);
	void third(unsigned coll, unsigned roww);
	bool isvalidmove(int x1, int y1, int x2, int y2);
};

ostream &operator<<(ostream &out, const almondgame &a);
#endif
