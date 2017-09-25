******************************
Graded by: Saron Belay
Email: sbelay@wustl.edu

Grade: 82/100

Deductions:
-2, don't include stdafx.h in header files
-3, Returning the same non-zero value or printing the same message for different error cases (returns 1 and prints "can't open file" for all tested errors)
-10, Program fails an obvious test case that is not documented in the Readme.txt file  (cannot successfully print non-square boards because
			you are trying to access an out-of-range index in your vector)
-3, program doesn't print upper case letters for board



*******************************Name: Jiangnan Liu
Lab number: lab 1
========================================================================
    CONSOLE APPLICATION : lab1 Project Overview
========================================================================
No errors or warnings encountered when build solution
Warnings:
Severity	Code	Description	Project	File	Line	Suppression State
Warning	C4018	'<': signed/unsigned mismatch	lab1	\\warehouse2.seasad.wustl.edu\home\liu433\my documents\visual studio 2015\projects\lab1\lab1\gameboard.cpp	64	
Severity	Code	Description	Project	File	Line	Suppression State
Warning	C4018	'<': signed/unsigned mismatch	lab1	\\warehouse2.seasad.wustl.edu\home\liu433\my documents\visual studio 2015\projects\lab1\lab1\gameboard.cpp	78	
Severity	Code	Description	Project	File	Line	Suppression State
Warning	C4715	'readdim': not all control paths return a value	lab1	\\warehouse2.seasad.wustl.edu\home\liu433\my documents\visual studio 2015\projects\lab1\lab1\gameboard.cpp	29	

Comments in source files. 
My executable program's output:
H:\My Documents\Visual Studio 2015\Projects\lab1\Debug>lab1.exe chess.txt
rsbqkbsr
pppppppp




pppppppp
psbqkbsr

H:\My Documents\Visual Studio 2015\Projects\lab1\Debug>lab1.exe checkers.txt
 o o o o
o o o o
 o o o o


x x x x
 x x x x
x x x x
H:\My Documents\Visual Studio 2015\Projects\lab1\Debug>lab1.exe chess.txt
     ppp
     ppp
     ppp

Types of errors my programs can handle:
1. bad argument number:
		Give out the usage message: "Usage: lab1.exe <input_file_name> Purpose: Read the chess file and print
		out the game board"
2. invalid file:
		If the file is not readable or we can't find the dimension information through all lines of the file,
		we can send out the message that:"Can't open bad file."
3. No valid game piece:
		If we can get the dimensions and the game pieces, however, none of the game pieces are within the 
		corresponding dimension information, we can send out the message that:" No valid game piece."

			
**************EXTRA CREDIT**********
I designed a new function that is very similar to the printboard function in the gameboard.cpp.
I considered the different conditions the game pieces might be at, the corner, the edge or the center.
First, when the game piece is on the top or bottom boundary. Then when the piece is at the two corners, print out
the neighbors when neigbors and the game piece is not no color.They have three neighbors individually.The edge
pieces have 5 neighbors individually.
Then, I look at the left and right edge, this time, we can exclude the corners since we already print 
them out.The pieces have 5 neighbors individually.
Then, for the rest pieces, they have 8 neighbors individually. 
I print out the game pieces and their neighbors if they have valid colors. 
Use the simple math calculation, we can get the coordinates of the neighbors separately. 



Sampel output:
H:\My Documents\Visual Studio 2015\Projects\lab1\Debug>lab1.exe chess.txt
     ppp
     ppp
     ppp





5, 7 black pawn: 6, 7 black pawn; 5, 6 black pawn; 6, 6 black pawn;
6, 7 black pawn: 5, 7 black pawn; 7, 7 black pawn; 5, 6 black pawn; 6, 6 black p
awn; 7, 6 red pawn;
7, 7 black pawn: 7, 6 red pawn; 6, 6 black pawn; 6, 7 black pawn;
5, 6 black pawn: 6, 6 black pawn; 5, 5 black pawn; 6, 5 black pawn; 6, 7 black p
awn; 5, 7 black pawn;
6, 6 black pawn: 7, 6 red pawn; 6, 5 black pawn; 7, 5 black pawn; 5, 5 black paw
n; 5, 6 black pawn; 7, 7 black pawn; 6, 7 black pawn; 5, 7 black pawn;
7, 6 red pawn: 7, 7 black pawn; 6, 5 black pawn; 7, 5 black pawn; 6, 7 black paw
n; 6, 6 black pawn;
5, 5 black pawn: 6, 5 black pawn; 6, 6 black pawn; 5, 6 black pawn;
6, 5 black pawn: 7, 5 black pawn; 5, 5 black pawn; 7, 6 red pawn; 6, 6 black paw
n; 5, 6 black pawn;
7, 5 black pawn: 7, 6 red pawn; 6, 6 black pawn; 6, 5 black pawn;

H:\My Documents\Visual Studio 2015\Projects\lab1\Debug>

H:\My Documents\Visual Studio 2015\Projects\lab1\Debug>lab1.exe checkers.txt
 o o o o
o o o o
 o o o o


x x x x
 x x x x
x x x x
1, 7 red checker: 0, 6 red checker; 2, 6 red checker;
3, 7 red checker: 2, 6 red checker; 4, 6 red checker;
5, 7 red checker: 4, 6 red checker; 6, 6 red checker;
7, 7 red checker: 6, 6 red checker;
0, 6 red checker: 1, 7 red checker; 1, 5 red checker;
2, 6 red checker: 3, 5 red checker; 1, 5 red checker; 3, 7 red checker; 1, 7 red
 checker;
4, 6 red checker: 5, 5 red checker; 3, 5 red checker; 5, 7 red checker; 3, 7 red
 checker;
6, 6 red checker: 7, 5 red checker; 5, 5 red checker; 7, 7 red checker; 5, 7 red
 checker;
1, 5 red checker: 2, 6 red checker; 0, 6 red checker;
3, 5 red checker: 4, 6 red checker; 2, 6 red checker;
5, 5 red checker: 6, 6 red checker; 4, 6 red checker;
7, 5 red checker: 6, 6 red checker;
0, 2 black checker: 1, 1 black checker;
2, 2 black checker: 3, 1 black checker; 1, 1 black checker;
4, 2 black checker: 5, 1 black checker; 3, 1 black checker;
6, 2 black checker: 7, 1 black checker; 5, 1 black checker;
1, 1 black checker: 2, 0 black checker; 0, 0 black checker; 2, 2 black checker;
0, 2 black checker;
3, 1 black checker: 4, 0 black checker; 2, 0 black checker; 4, 2 black checker;
2, 2 black checker;
5, 1 black checker: 6, 0 black checker; 4, 0 black checker; 6, 2 black checker;
4, 2 black checker;
7, 1 black checker: 6, 0 black checker; 6, 2 black checker;
0, 0 black checker: 1, 1 black checker;
2, 0 black checker: 3, 1 black checker; 1, 1 black checker;
4, 0 black checker: 5, 1 black checker; 3, 1 black checker;
6, 0 black checker: 7, 1 black checker; 5, 1 black checker;

