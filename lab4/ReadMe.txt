******************************
Graded by: Rudy Zhou
Email: rudyzhou1234@gmail.com

Note: You can search your code for my initials "RZ" to see if I made any comments

Grade: 101/100

Deductions:
- (-1) It's reasonable to say that you didn't do any copy control, but you should mention why that is ok (in particular, we don't have a need t copy the game
because we only want a single game to exist.)
- other than that, the usage of the smart pointer and refactoring all look good
-(+2) checkers seems to initialize correctly, but I don't think actually making moves works
*******************************

Lab name: Lab4
Name: Jiangnan Liu
E-Mail: liu433@wustl.edu

Errors and warnings:
1.Severity	Code	Description	Project	File	Line	Suppression State
Warning	C4715	'gamebase::gamestart': not all control paths return a value	lab4	\\warehouse2.seasad.wustl.edu\home\liu433\my documents\visual studio 2015\projects\lab4\lab4\gamebas.cpp	76	

copy/control:
I did not use any copy control figures within the game design.
I used the smart pointer to start different game type. 
It handles the default destructors for game base and its derived class. 

comments within the files

Types of errors my programs can handle:
1. bad argument number:
	give out the usage message and tell the user the argument number is false.
2. bad argument game name:
	give out the usage message and tell the user the command line is bad.
3. quit error:
	since the user chooses quit, return quit error.
4. stucked there error:
	since there is no valid move on the board, return stucked error
5. too few game player error:
	tell the user there are too few players.
6. unknown exception error:
	other errors not recorded
7. bad allocation error:
	throw the specified bad alloc error and print out the usage message.
8.readyes_extractno error:
	tell the user if the file does not have valid lines
9. too many game player error:
	tell the user there are too many players


Saved game format:
 first line: the game name
 second line: NO DATA or moves longstring whosemove
 third line and following:
	each game piece's color name output and coordinates

My program's output:
H:\My Documents\Visual Studio 2015\Projects\lab4\Debug>lab4.exe Reversi alice
b

7
6
5
4       O X
3       X O
2
1
0
X 0 1 2 3 4 5 6 7

alice, where do you want to put your coin?
Position #,# or quit.
3,2
Choose a valid move.
alice, where do you want to put your coin?
Position #,# or quit.
3,5

7
6
5       X
4       X X
3       X O
2
1
0
X 0 1 2 3 4 5 6 7

bob, where do you want to put your coin?
Position #,# or quit.
5,3
Choose a valid move.
bob, where do you want to put your coin?
Position #,# or quit.
2,5

7
6
5     O X
4       O X
3       X O
2
1
0
X 0 1 2 3 4 5 6 7

alice, where do you want to put your coin?
Position #,# or quit.
2,4

7
6
5     O X
4     X X X
3       X O
2
1
0
X 0 1 2 3 4 5 6 7

bob, where do you want to put your coin?
Position #,# or quit.
2,3

7
6
5     O X
4     O X X
3     O O O
2
1
0
X 0 1 2 3 4 5 6 7

alice, where do you want to put your coin?
Position #,# or quit.
3,2

7
6
5     O X
4     O X X
3     O X O
2       X
1
0
X 0 1 2 3 4 5 6 7

bob, where do you want to put your coin?
Position #,# or quit.
2,1

7
6
5     O X
4     O X X
3     O X O
2       O
1     O
0
X 0 1 2 3 4 5 6 7

alice, where do you want to put your coin?
Position #,# or quit.
3,1

7
6
5     O X
4     O X X
3     O X O
2       X
1     O X
0
X 0 1 2 3 4 5 6 7

bob, where do you want to put your coin?
Position #,# or quit.
4,1

7
6
5     O X
4     O X X
3     O X O
2       O
1     O O O
0
X 0 1 2 3 4 5 6 7

alice, where do you want to put your coin?
Position #,# or quit.
4,2

7
6
5     O X
4     O X X
3     O X X
2       O X
1     O O O
0
X 0 1 2 3 4 5 6 7

bob, where do you want to put your coin?
Position #,# or quit.
3,6

7
6       O
5     O O
4     O O X
3     O O X
2       O X
1     O O O
0
X 0 1 2 3 4 5 6 7

alice, where do you want to put your coin?
Position #,# or quit.
4,0

7
6       O
5     O O
4     O O X
3     O O X
2       O X
1     O O X
0         X
X 0 1 2 3 4 5 6 7

bob, where do you want to put your coin?
Position #,# or quit.
4,5
Choose a valid move.
bob, where do you want to put your coin?
Position #,# or quit.
5,1

7
6       O
5     O O
4     O O X
3     O O X
2       O O
1     O O O O
0         X
X 0 1 2 3 4 5 6 7

alice, where do you want to put your coin?
Position #,# or quit.
6,2

7
6       O
5     O O
4     O O X
3     O O X
2       O O   X
1     O O O X
0         X
X 0 1 2 3 4 5 6 7

bob, where do you want to put your coin?
Position #,# or quit.
4,5

7
6       O
5     O O O
4     O O O
3     O O O
2       O O   X
1     O O O X
0         X
X 0 1 2 3 4 5 6 7

alice, where do you want to put your coin?
Position #,# or quit.
4,6

7
6       O X
5     O O X
4     O O X
3     O O X
2       O X   X
1     O O X X
0         X
X 0 1 2 3 4 5 6 7

bob, where do you want to put your coin?
Position #,# or quit.
6,1

7
6       O X
5     O O X
4     O O X
3     O O X
2       O X   X
1     O O O O O
0         X
X 0 1 2 3 4 5 6 7

alice, where do you want to put your coin?
Position #,# or quit.
6,0

7
6       O X
5     O O X
4     O O X
3     O O X
2       O X   X
1     O O O X X
0         X   X
X 0 1 2 3 4 5 6 7

bob, where do you want to put your coin?
Position #,# or quit.
quit
You quit the game and you have played 17 moves
Do you want to save the game? Yes or No.
Yes


H:\My Documents\Visual Studio 2015\Projects\lab4\Debug>lab4.exe Reversi alice bo
b

7
6       O X
5     O O X
4     O O X
3     O O X
2       O X   X
1     O O O X X
0         X   X
X 0 1 2 3 4 5 6 7

bob, where do you want to put your coin?
Position #,# or quit.

H:\My Documents\Visual Studio 2015\Projects\lab4\Debug>lab4.exe NineAlmonds

4     A A
3     A
2
1   A     A
0
X 0 1 2 3 4

what's your start piece?
Position #,# or quit.

H:\My Documents\Visual Studio 2015\Projects\lab4\Debug>lab4.exe MagicSquare

2 5 9
1 4   7
0
X 0 1 2
Available pieces: 1 2 3 6 8
Which piece do you want to move?
Please enter an available piece number or quit.
quit

H:\My Documents\Visual Studio 2015\Projects\lab4\Debug>lab4.exe
Wrong argument number!
Usage: lab4.exe
Purpose: play the games
Type lab4.exe NineAlmonds or lab4.exe MagicSquare to start the game

H:\My Documents\Visual Studio 2015\Projects\lab4\Debug>lab4.exe
Wrong argument number!
Usage: lab4.exe
Purpose: play the games
Type lab4.exe NineAlmonds or lab4.exe MagicSquare or lab4.exe Reversi /Player A'
s name/ /Player B's name/ to start the game

H:\My Documents\Visual Studio 2015\Projects\lab4\Debug>lab4.exe alabala
Wrong command!
Usage: lab4.exe
Purpose: play the games
Type lab4.exe NineAlmonds or lab4.exe MagicSquare or lab4.exe Reversi /Player A'
s name/ /Player B's name/ to start the game

H:\My Documents\Visual Studio 2015\Projects\lab4\Debug>lab4.exe Reversi a
Type two players' names please.

H:\My Documents\Visual Studio 2015\Projects\lab4\Debug>lab4.exe Reversi a b c
Wrong argument number!
Usage: lab4.exe
Purpose: play the games
Type lab4.exe NineAlmonds or lab4.exe MagicSquare or lab4.exe Reversi /Player A'
s name/ /Player B's name/ to start the game

H:\My Documents\Visual Studio 2015\Projects\lab4\Debug>lab4.exe Reversi a b

7
6
5     X X X X X
4     X O O O X
3     X O   O X
2     X O O O X
1     X X X X X
0
X 0 1 2 3 4 5 6 7

a, where do you want to put your coin?
Position #,# or quit.
4,3

7
6
5     X X X X X
4     X X X X X
3     X X X X X
2     X X X X X
1     X X X X X
0
X 0 1 2 3 4 5 6 7

a!!!
a!!!
You won the game!!!!
You have played 16 moves


H:\My Documents\Visual Studio 2015\Projects\lab4\Debug>lab4.exe Reversi a b

7
6
5
4 X X O
3
2
1
0
X 0 1 2 3 4 5 6 7

b, you do not have a valid place to put your coin for this round.
a, where do you want to put your coin?
Position #,# or quit.
3,4

7
6
5
4 X X X X
3
2
1
0
X 0 1 2 3 4 5 6 7

a!!!
a!!!
You won the game!!!!
You have played 4 moves

H:\My Documents\Visual Studio 2015\Projects\lab4\Debug>
******extra credit********
Invali^C
H:\My Documents\Visual Studio 2015\Projects\lab4\Debug>lab4.exe Checkers a b

7   X   X   X   X
6 X   X   X   X
5   X   X   X   X
4
3
2 O   O   O   O
1   O   O   O   O
0 O   O   O   O
X 0 1 2 3 4 5 6 7

a, where do you want to start?
Position #,# or quit.
1,5
what's your end piece?
Position #,# or quit.
2,4