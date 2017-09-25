#ifndef LAB2H_H
#define LAB2H_H

#include <vector>
#include <string>
#include "gamp.h"
#include <iostream>
#include "gameb.h"

using namespace std;

class almondgame{
	friend ostream &operator<<(ostream &out, const almondgame &a);
public:
	almondgame();
	~almondgame() {}
	almondgame(vector<gp> v, unsigned int cols, unsigned int rows);
	bool done();
	bool stalemate();
	void prompt(unsigned & col, unsigned & row);
	void turn();
	void second(unsigned col, unsigned row);
	void third(unsigned coll, unsigned roww);
	int play();
	bool isvalidmove(int x1,int y1,int x2,int y2);
private:
	unsigned int cols;
	unsigned int rows;
	vector<gp> v;
	int moves;

};
enum ins { program_name = 0, file_name = 1, expected_argc = 2 };
enum results_code {
	success, file_open_failed, bad_command_line, unknown_exception = -1, readyes_extractno = -3
	, unmatchvector_dim,quit_error,stuckedthere, bad_argc,
};

// Function prototypes
int usage(char * program_name, int error_value);
ostream &operator<<(ostream &out, const almondgame &a);
#endif