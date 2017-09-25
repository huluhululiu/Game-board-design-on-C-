// lab3.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include "gameb.h"
#include "lab4.h"
#include "gamep.h"
#include "gamebase.h"
#include "almonds.h"
#include "magicsq.h"
#include "checker.h"
using namespace std;
int main(int argc, char*argv[])
{
	try {
		
		gamebase::gamestart(argc, argv);
		//if none of the game could be start, it means the command is wrong 
		if (gamebase::instance() == nullptr) {
			throw isanullptr;
		}
		int res = gamebase::instance()->play();
		return res;
	}
	// print out the bad alloc with usage message or any other results code and its corresponding error message
	catch (bad_alloc) {
		return usage(argv[program_name], badalloca);
	}
	catch (results_code a) {
		return usage(argv[program_name], a);
	}


}

int usage(char * program_name, int error_value)// print out the program's usage when argument number is false or other error happens
{
	if (error_value == bad_argc) {
		cout << "Wrong argument number!" << endl;
		cout << "Usage: " << program_name << endl
			<< "Purpose: play the games"
			<< endl;
		cout << "Type " << program_name << " NineAlmonds or ";
		cout << program_name << " MagicSquare or ";
		cout << program_name << " Reversi /Player A's name/ /Player B's name/ to start the game " << endl;
		return bad_argc;
	}
	else if (error_value == bad_command_line) {
		cout << "Wrong command!" << endl;
		cout << "Usage: " << program_name << endl
			<< "Purpose: play the games"
			<< endl;
		cout << "Type " << program_name << " NineAlmonds or ";
		cout << program_name << " MagicSquare or ";
		cout<<program_name<<" Reversi /Player A's name/ /Player B's name/ to start the game " << endl;
		return bad_command_line;
	}
	
	else if (error_value == badalloca) {
		cout << "Bad Allocation error" << endl;
		return badalloca;
	}
	else if ((error_value == toomanyargc)|| (error_value == toofewargc)) {
		cout << "Type two players' names please." << endl;
		return error_value;
	}
	else return error_value;
}