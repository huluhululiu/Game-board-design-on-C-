#include "stdafx.h"
#include <vector>
#include <string>
#include <iostream>
#include <memory>
#include <iomanip>
#include <sstream>
#include "almonds.h"
#include "gameb.h"
#include "gamep.h"
#include "gamebase.h"
#include "lab4.h"
#include "magicsq.h"
#include "rever.h"
#include "checker.h"
using namespace std;
shared_ptr<gamebase> gamebase:: ptrgbase = nullptr;
gamebase::gamebase(int cols, int rows, int moves)
	: cols(cols), rows(rows), moves(0) {
	whoseturn = true;
}
shared_ptr<gamebase> gamebase::instance() {
	if (ptrgbase != nullptr) {
		return ptrgbase;
	}
	else throw isanullptr;
}
void gamebase::gamestart(int argc, char* argv[]) {

	if (ptrgbase == nullptr) {
		if ((argc > magic_custom) || (argc < expected_argc)) {
			throw bad_argc;
		}
		else if ((string(argv[file_name]) != "Checkers") &&(string(argv[file_name]) != "MagicSquare") && (string(argv[file_name]) != "NineAlmonds") && (string(argv[file_name]) != "Reversi")) {
			throw bad_command_line;
		}
		else if ((argc == expected_argc) && (string(argv[file_name]) == "NineAlmonds")) {
			ptrgbase = make_shared<almondgame>();
		}
		else if ((string(argv[file_name]) == "MagicSquare") && (argc == expected_argc)) {
			//check the game to see if it is magic square default game	
			ptrgbase = make_shared<magicsquare>();
		}
		else if ((string(argv[file_name]) == "Reversi") && (argc == magic_custom)) {
			//if there are 4 arguments check if size is valid or not and start the game with start number
			ptrgbase = make_shared<reversi>(argv[expected_argc], argv[magic_default]);
		}
		else if ((string(argv[file_name]) == "Reversi") && (argc < magic_custom)) {
			//if there are 4 arguments check if size is valid or not and start the game with start number
			throw toofewargc;
		}
		else if ((string(argv[file_name]) == "Reversi") && (argc > magic_custom)) {
			//if there are 4 arguments check if size is valid or not and start the game with start number
			throw toomanyargc;
		}
		else if ((string(argv[file_name]) == "Checkers") && (argc == magic_custom)) {
			//if there are 4 arguments check if size is valid or not and start the game with start number
			ptrgbase = make_shared<checker>(argv[expected_argc], argv[magic_default]);
		}
		else if ((string(argv[file_name]) == "Checkers") && (argc < magic_custom)) {
			//if there are 4 arguments check if size is valid or not and start the game with start number
			throw toofewargc;
		}
		else if ((string(argv[file_name]) == "Checkers") && (argc > magic_custom)) {
			//if there are 4 arguments check if size is valid or not and start the game with start number
			throw toomanyargc;
		}
		else {
			ptrgbase = nullptr;
			throw bad_argc; 
		}
	}
	else throw notanullptr;
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
		if ((col < 0 || col >(rows - 1)) || (row < 0 || row >(cols - 1)))
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
	print();
	//call the subclass print method

	while ((!done()) && (!stalemate())) {
		try {
			turn();
			++moves;
		}
		catch (results_code quit_error) {//catch the error code 
			cout << "You quit the game and you have played " << moves << " moves" << endl;
			savegame();
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
void gamebase::savegame() {
	cout << "Do you want to save the game? Yes or No." << endl;
	string ans;
	//check if the user want to save the game or not
	getline(cin, ans);
	if (ans == "Yes") {
		ofstream myfile;
		int index = 0;
		myfile.open(gamename);
		myfile.clear();
		myfile << gamename << endl;
		myfile << moves << " " << long_string <<" "<<whoseturn<< endl;
		for (gp a : v) {
			//save every piece of game piece with their number and their coordinates
			myfile << enumtostring(a.color_)<<" ";
			myfile << a.name_ << " ";
			myfile << a.op_ << " ";
			int columnNUM = index / cols;
			int rowNUM = index%cols;
			myfile << columnNUM << " " << rowNUM << endl;
			++index;
		}
		myfile.close();
		throw quit_error;
	}
	else if (ans == "No") {//if the user does not want to save the game
		//open the file with gamename and clear the data inside it and rewrite no data
		ofstream myfile;
		myfile.open(gamename);
		myfile.clear();
		myfile << gamename << endl;
		myfile << "NO DATA";
		myfile.close();
		throw quit_error;
	}
	else return savegame();
}

