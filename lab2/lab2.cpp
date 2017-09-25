// lab2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "lab2h.h"
#include "gamp.h"
#include "gameb.h"
#include <iostream>
#include <vector>
#include <string>
#include <sstream>
using namespace std;

int main(int argc, char*argv[])
{
	if (argc != expected_argc) {
		return usage(argv[program_name],bad_argc);
	}
	if (string(argv[file_name]) != "NineAlmonds") {
		return usage(argv[program_name], bad_command_line);
	}
	else {
		vector<gp> v;
		almondgame mygame=almondgame();
	
		int res=mygame.play();
		return res;
	}
	
	
}
int usage(char * program_name, int error_value)// print out the program's usage when argument number is false.
{
	if (error_value == bad_argc) {
		cout << "Wrong argument number!" << endl;
		cout << "Usage: " << program_name << endl
			<< "Purpose: play the almond game"
			<< endl;
		cout << "Type " << program_name << " " << " NineAlmonds to start the game " << endl;
		return bad_argc;
	}
	if (error_value == bad_command_line) {
		cout << "Wrong command!" << endl;
		cout << "Usage: " << program_name << endl
			<< "Purpose: play the almond game"
			<< endl;
		cout << "Type " << program_name << " " << " NineAlmonds to start the game " << endl;
		return bad_command_line;
	}

}

