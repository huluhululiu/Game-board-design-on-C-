#include "stdafx.h"
#include <vector>
#include <string>
#include <iostream>
#include <iomanip>
#include <sstream>
#include "gameb.h"
#include "gamep.h"
#include "gamebase.h"
#include "lab3.h"
#include "magicsq.h"
using namespace std;
gamebase::gamebase(int cols, int rows,int moves)
	: cols(cols), rows(rows), moves(0) {}

gamebase* gamebase::gamestart(int argc, char* argv[]) {
	// have to first make sure argv[file_name] exists --cw
	if (argc < 2) {
		throw bad_argc;
	}
	//END
	if ((argc != expected_argc)&& (string(argv[file_name]) != "MagicSquare")) {
		throw bad_argc;
	}
	else if ((argc > magic_custom) ||(argc< expected_argc)&& (string(argv[file_name]) == "MagicSquare")) {
		throw bad_argc;
	}
	//still have to allow ninealmondsgame --cw
	else if (argc != expected_argc && string(argv[file_name]) == "NineAlmonds") {
		throw bad_argc;
	}
	//end
	else {
		if((string(argv[file_name]) == "MagicSquare")&&(argc==expected_argc)) {		
					//check the game to see if it is magic square default game	
					magicsquare* mygame = new magicsquare();
					return mygame;
		}
		//still have to allow ninealmondsgame --cw
		else if ((string(argv[file_name]) == "NineAlmonds") && (argc == expected_argc)) {
			//check the game to see if it is magic square default game	
			almondgame* mygame = new almondgame();
			return mygame;
		}
		//still have to allow ninealmondsgame --cw
		else if ((string(argv[file_name]) == "MagicSquare") && (argc ==magic_default)) {
		//	check the game to see if it is magic square and has only one integer after it
			int size;
			istringstream isn((argv[expected_argc]));
			if (isn >> size) {
				if (size >= 1) {
					magicsquare* mygame = new magicsquare(size);
					return mygame;
				}
				else {
					//throw the wrong game size error if size is less than 1
					throw wrong_game_size;
				}
			}
			else {
				gamebase *mygame = nullptr;
				return mygame;
			}
		}
		else if ((string(argv[file_name]) == "MagicSquare") && (argc == magic_custom)) {
			//if there are 4 arguments check if size is valid or not and start the game with start number
			int size;
			int startnum;
			string a = string(argv[expected_argc]);
			istringstream iq(a);
			istringstream isn((argv[magic_default]));
			if ((iq >> size) && (isn >> startnum))
			{
				if (size >= 1) {
					magicsquare* mygame = new magicsquare(size, startnum);
					return mygame;
				}
				else {
					//throw the wrong game size error if size is less than 1
					throw wrong_game_size;
				}
			}
			else {
				gamebase *mygame = nullptr;
				return mygame;
			}
		}
		else{
			gamebase *mygame = nullptr;
			return mygame;
		}
	}
}


//prompt user for a valid input of col and row
void gamebase::prompt(unsigned &col, unsigned &row) {
	// Initial message the prompt user type
	cout << "Position #,# or quit." << endl;

	string r;
	getline(cin, r);
	if (r == "quit")
		throw quit_error;
	auto position = r.find(',');
	if (position != string::npos)
		r.replace(r.find(','), 1, " ");
	string space(" ");
	if (r.size() == 3 && r.find(space) == 1)
	{//remove the comma and replace it with the space
		istringstream iss(r);
		iss >> col;
		iss >> row;
		// check to see if the coordinates are out of range or not
		if ((col < 0 || col > (rows-1)) || (row < 0 || row > (cols-1)))
		{

			cout << "Out of range coordinates" << endl;
			return prompt(col, row);
		}
	}
	else
	{
		//invalid input and ask the user to type again
		cout << "Invalid input, enter in the correct form" << endl;
		return prompt(col, row);
	}
}

//play the game base
int gamebase::play() {
	int moves = 0;
	print();
	//call the subclass print method

	while ((!done()) && (!stalemate())) {
		try {
			turn();
			++moves;
		}
		catch (results_code quit_error) {
			cout << "You quit the game and you have played " << moves << " moves" << endl;
			return quit_error;
		}
	}
	//if stalemate, return stucked there
	if (stalemate()) {
		cout << "No valid moves left on the game board. You lost the game:(" << endl;
		cout << "You have played " << moves << " moves" << endl;
		return stuckedthere;
	}
	//if successfully play the game, return success
	if (done()) {
		cout << "You won the game!!!!" << endl;
		cout << "You have played " << moves << " moves" << endl;
		return success;
	}
	return success;
}


