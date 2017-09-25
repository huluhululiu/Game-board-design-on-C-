

#ifndef LAB1_H
#define LAB1_H
#include <vector>
#include <string>

#include <iostream>
//#include "stdafx.h"                                                             //Don't include this in header files, SB
using namespace std;
enum ins { program_name = 0, file_name = 1, expected_argc = 2 };
enum results_code { success, file_open_failed, bad_command_line, unknown_exception = -1, readyes_extractno = -3
, unmatchvector_dim};

// Function prototypes
int usage(char * program_name);
void lower(string& cool);

#endif