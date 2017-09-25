
#ifndef LAB0_ENUM_H
#define LAB0_ENUM_H
#include <vector>
#include <string>
#include <cstring>
#include <iostream>
#include "stdafx.h"
using namespace std;
enum ins { program_name = 0, file_name = 1,expected_argc=2 };
enum results_code { success, file_open_failed, bad_command_line, unknown_exception = -1 };
// Function prototypes
int usage(char * program_name);
int parse(vector<string>& read, char *file);

#endif /* PREFIX_ADDER_H */