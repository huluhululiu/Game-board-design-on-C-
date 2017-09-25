// lab0.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "lab0_enum.h"
#include<iostream>
#include <string>   // For standard C++ strings.
#include <sstream>  // For standard string streams.
#include <cstring>  // For C-style string functions
#include <vector>
#include <fstream>
using namespace std;
int main(int argc, char*argv[])
{
	vector<string> read;
	vector<int> numbers;
	if (argc != expected_argc) {
		return usage(argv[program_name]); 
	}
	else {
		int value = parse(read, argv[1]);
		for (unsigned int i = 0;i <read.size();++i) {
			string temp = read[i];
			unsigned int acc = 0;
			int num;
			for (unsigned int j = 0;j <temp.size();++j) {
				if (isdigit(temp.at(j))) ++acc;
			}
			if (acc == temp.size()) {
				istringstream iss(temp);
				iss >> num;
				numbers.push_back(num);
			}
			else {
				cout << temp << endl;
			}
		}
		for (unsigned int i = 0; i < numbers.size();++i) {
			cout << numbers[i] << endl;
		}
		return value;
	}
	
}
int parse(vector<string> &read, char *file) {
	ifstream ifs(file);
	string cool;
	if (ifs.is_open()) {
		while (ifs >> cool) {
			read.push_back(cool);
			
		}
		return success;
	}
	else
		return file_open_failed;
}

int usage(char * program_name) {

	cout << "Usage: " << program_name << " <input_file_name>" << endl
		<< "Purpose: Parse the input string and differentiate the integers"
		<< endl;
	return bad_command_line;

}