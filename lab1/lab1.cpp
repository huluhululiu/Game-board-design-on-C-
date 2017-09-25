// lab1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "lab1.h"
#include "gameb.h"
#include "gamepiece.h"
#include<iostream>
#include <string>   // For standard C++ strings.
#include <sstream>  // For standard string streams.
#include <cstring>  // For C-style string functions
#include <vector>
#include <fstream>
#include <ctype.h>
using namespace std;
int main(int argc, char*argv[])
{
	if (argc != expected_argc) {// read the argument numbers, if it is not 2,we can send the usage info
		return usage(argv[program_name]);
	}
	else {
		unsigned int hori;// the corresponding coordinate info
		unsigned int verti;
		ifstream ifs(argv[1]);// read the input file
		int value=readdim(ifs, hori, verti);//read the dimension of the game board
		while ((value == readyes_extractno)&&(value!=success)) {
			value=readdim(ifs, hori, verti); //if we can extract information from the board but can't
			//find any dimensions, we should read again and again before we report it is a bad file.
		}
		
		if (value == success) {
			vector<gp> piece;//build a new empty vector of the game piece
			gp emptysquare(no_color, " ", " ");
			for (int i = 0;i < hori*verti;++i) {
				piece.push_back(emptysquare);// build empty game pieces without any color and stuff them into the vector
			}
			int v = readgame(ifs, piece, hori, verti);// see if we can read the game pieces from the file successfully
			if (v == file_open_failed) {
				cout << "No valid game pieces." << endl;
				return v;			// if none of the game piece is valid, we can send out the message to user.
			}
			else {
				int m = printboard(piece, hori, verti);
				adjacent(piece, hori, verti);  // if successfully read the game pieces, even only one, we can print it out to 
				//the board, for the extracredit, we can even print out its neighbors.
				return m;
			}
		}
		if (value == file_open_failed) {
			cout << "Can't open bad file." << endl;// if the file can't be opened, we can send the message
			return file_open_failed;
		}
	}
}
void lower(string& cool) {// convert all uppercase in a string to lower
	int i = 0;
	
	while (cool[i]) {
		if (isalpha(cool[i])) {
			if (isupper(cool[i])) cool[i] = tolower(cool[i]);
		}
		++i;
	}
}
int usage(char * program_name)// print out the program's usage when argument number is false.
{

	cout << "Usage: " << program_name << " <input_file_name>" << endl
		<< "Purpose: Read the chess file and print out the game board"
		<< endl;
	return bad_command_line;
}
