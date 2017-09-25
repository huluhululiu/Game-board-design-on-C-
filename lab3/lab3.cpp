// lab3.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include "gameb.h"
#include "lab3.h"
#include "gamep.h"
#include "gamebase.h"
#include "magicsq.h"
using namespace std;
int main(int argc, char*argv[])
{
	try {
		gamebase *m = gamebase::gamestart(argc, argv);
		//if none of the game could be start, it means the command is wrong 
		if (m == nullptr) {
			return usage(argv[program_name], bad_command_line);
		}
		int res = m->play();
		return res;
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
		cout << program_name << " MagicSquare to start the game " << endl;
		return bad_argc;
	}
	else if (error_value == bad_command_line) {
		cout << "Wrong command!" << endl;
		cout << "Usage: " << program_name << endl
			<< "Purpose: play the games"
			<< endl;
		cout << "Type " << program_name << " NineAlmonds or " ;
			cout<<program_name<<" MagicSquare to start the game " << endl;
		return bad_command_line;
	}
	else if (error_value == wrong_game_size) {
		cout << "Wrong game dimensions!" << endl;
		cout << "Usage: " << program_name << endl
			<< "Purpose: play the games"
			<< endl;
		cout << "Type " << program_name << " NineAlmonds or ";
		cout << program_name << " MagicSquare to start the game " << endl;
		cout << "After the MagicSquare, please tyep an integer that is no less than 1" << endl;
		return wrong_game_size;
	}
	else return error_value;
}