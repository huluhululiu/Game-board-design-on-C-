#ifndef LAB4_H
#define LAB4_H

#include <vector>
#include <string>
#include "gamep.h"
#include "gamebase.h"
#include <iostream>
#include "gameb.h"

//using namespace std;



enum ins { program_name = 0, file_name = 1, expected_argc = 2, magic_default = 3, magic_custom = 4, };
enum results_code {
	success, file_open_failed, bad_command_line, unknown_exception = -1, readyes_extractno = -3
	, unmatchvector_dim = 5, quit_error = 6, stuckedthere = 7, bad_argc = 8, gamepiece_invalid = 9, invalid_gamename = 10, not_null = 11,
	notanum = 12, wrong_game_size = 13, isanullptr, badalloca, notanullptr,toomanyargc,toofewargc,
};
int usage(char * program_name, int error_value);
#endif