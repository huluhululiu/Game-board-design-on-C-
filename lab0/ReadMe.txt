******************************
Graded by: Charlie Wu
Email: jiaye.wu@wustl.edu

Grade: 104/100

Deductions:

-1: Too little comments.



*******************************
Name: Jiangnan Liu
Lab number: lab 0

========================================================================
    CONSOLE APPLICATION : lab0 Project Overview
========================================================================
Error1: the parse command is not undefined
Warning2: line 22 '<' singed/unsigned mismatch
Warning3: line 26 '<' singed/unsigned mismatch
Warning4: line 38 '<' singed/unsigned mismatch

Errors that can be reported:
1. command line error(extra or less command arguments)
2. file can't be opened error
3. unknown exception error
What the executable program did for each trials:
trial1:
command line: lab0.exe input_file.txt
output:
these
all
are
strings
7string
str4ing
string2
0
1
2
3
5
7
11
13
17
19
Correct? Yes
trial2:
command line: lab0.exe
output:
Usage: lab0.exe<input_file_name>
Purpose: Parse the input string and differentiate the integers
Correct? Yes


***********EXTRA CREDIT**************
Attempting to create directory /home/warehouse/liu433/perl5
[liu433@shell ~]$ ^C

Errors occurred:
[liu433@shell lab0]$ make
g++ -o lab0extra -DUNIX   -Wall -W -g -pedantic lab0.cpp -lnsl
lab0.cpp:4:20: fatal error: stdafx.h: No such file or directory
 #include "stdafx.h"
                    ^
compilation terminated.
make: *** [lab0extra] Error 1
g++ -o lab0extra -DUNIX   -Wall -W -g -pedantic lab0.cpp -lnsl
lab0.cpp: In function âint main(int, char**)â:
lab0.cpp:22:31: warning: comparison between signed and unsigned integer expressions [-Wsign-compare]
   for (int i = 0;i <read.size();++i) {
                               ^
lab0.cpp:26:32: warning: comparison between signed and unsigned integer expressions [-Wsign-compare]
    for (int j = 0;j <temp.size();++j) {
                                ^
lab0.cpp:29:25: warning: comparison between signed and unsigned integer expressions [-Wsign-compare]
    if (acc == temp.size()) {
                         ^
lab0.cpp:38:36: warning: comparison between signed and unsigned integer expressions [-Wsign-compare]
   for (int i = 0; i < numbers.size();++i) {

After compile successfully:
[liu433@shell lab0]$ ls
lab0.cpp  lab0_enum.h  lab0extra  Makefile  Templates.DB
[liu433@shell lab0]$ ./lab0extra.exe input_file.txt
-bash: ./lab0extra.exe: No such file or directory
[liu433@shell lab0]$ ./lab0extra input_file.txt
these
all
are
strings
7string
str4ing
string2
str
gre4t
0
1
2
3
5
7
11
13
17
19
45
332
[liu433@shell lab0]$ ./lab0extra lab0lint1.txt
wo
shi
yao
ch4eng
wei
haizei
w5ang
d5
883
19
21
239403
123



