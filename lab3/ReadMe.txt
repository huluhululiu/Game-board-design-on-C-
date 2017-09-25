******************************
Graded by: charlie wu
Email: jiaye.wu@wustl.edu

Grade: 100/100

Deductions:

-2: Have to check argv[file_name] actually exists. Otherwise, the program will crash on 0 argument.
-3: failed the test case with 0 arguments, and didn't test or document the previous error in readme file.

.

+5: extra credit
*******************************

Lab name: Lab3
Name: Jiangnan Liu
E-Mail: liu433@wustl.edu

Errors and warnings:
1.Severity	Code	Description	Project	File	Line	Suppression State
Error (active)		expression must have integral or unscoped enum type	lab3	\\warehouse2.seasad.wustl.edu\home\liu433\My Documents\Visual Studio 2015\Projects\lab3\lab3\gamebas.cpp	93	
2.Severity	Code	Description	Project	File	Line	Suppression State
Error (active)		expression must have integral or unscoped enum type	lab3	\\warehouse2.seasad.wustl.edu\home\liu433\My Documents\Visual Studio 2015\Projects\lab3\lab3\gamebas.cpp	93	
3.Severity	Code	Description	Project	File	Line	Suppression State
Warning	C4715	'usage': not all control paths return a value	lab3	\\warehouse2.seasad.wustl.edu\home\liu433\my documents\visual studio 2015\projects\lab3\lab3\lab3.cpp	53	
4.Severity	Code	Description	Project	File	Line	Suppression State
Warning	C4018	'<=': signed/unsigned mismatch	lab3	\\warehouse2.seasad.wustl.edu\home\liu433\my documents\visual studio 2015\projects\lab3\lab3\magicsquare.cpp	138	
5.Severity	Code	Description	Project	File	Line	Suppression State
Error	C4700	uninitialized local variable 'size' used	lab3	\\warehouse2.seasad.wustl.edu\home\liu433\my documents\visual studio 2015\projects\lab3\lab3\gamebas.cpp	79	
6.Severity	Code	Description	Project	File	Line	Suppression State
Warning	C4715	'gamebase::gamestart': not all control paths return a value	lab3	\\warehouse2.seasad.wustl.edu\home\liu433\my documents\visual studio 2015\projects\lab3\lab3\gamebas.cpp	76	

comments within the files

My program's output:

H:\My Documents\Visual Studio 2015\Projects\lab3\Debug>lab3.exe MagicSquare

2
1
0
X012
Available pieces: 1 2 3 4 5 6 7 8 9
Which piece do you want to move?
Please enter an available piece number or quit.

1
Where do you want to move that game piece to on the game board?

Enter the coordinates
Position #,# or quit.
0,0

2
1
0 1
X 0 1 2
Available pieces: 2 3 4 5 6 7 8 9
Which piece do you want to move?
Please enter an available piece number or quit.

1
This piece number is invalid.
Please enter an available piece number or quit.

11
This piece number is invalid.
Please enter an available piece number or quit.

quit
You quit the game and you have played 1 moves

H:\My Documents\Visual Studio 2015\Projects\lab3\Debug>lab3.exe MagicSquare

2
1
0
X012
Available pieces: 1 2 3 4 5 6 7 8 9
Which piece do you want to move?
Please enter an available piece number or quit.

4
Where do you want to move that game piece to on the game board?

Enter the coordinates
Position #,# or quit.
0,0

2
1
0 4
X 0 1 2
Available pieces: 1 2 3 5 6 7 8 9
Which piece do you want to move?
Please enter an available piece number or quit.

9
Where do you want to move that game piece to on the game board?

Enter the coordinates
Position #,# or quit.
1,0

2
1
0 4 9
X 0 1 2
Available pieces: 1 2 3 5 6 7 8
Which piece do you want to move?
Please enter an available piece number or quit.

2
Where do you want to move that game piece to on the game board?

Enter the coordinates
Position #,# or quit.
2,0

2
1
0 4 9 2
X 0 1 2
Available pieces: 1 3 5 6 7 8
Which piece do you want to move?
Please enter an available piece number or quit.

3
Where do you want to move that game piece to on the game board?

Enter the coordinates
Position #,# or quit.
0,1

2
1 3
0 4 9 2
X 0 1 2
Available pieces: 1 5 6 7 8
Which piece do you want to move?
Please enter an available piece number or quit.

5
Where do you want to move that game piece to on the game board?

Enter the coordinates
Position #,# or quit.
1,1

2
1 3 5
0 4 9 2
X 0 1 2
Available pieces: 1 6 7 8
Which piece do you want to move?
Please enter an available piece number or quit.

7
Where do you want to move that game piece to on the game board?

Enter the coordinates
Position #,# or quit.
2,1

2
1 3 5 7
0 4 9 2
X 0 1 2
Available pieces: 1 6 8
Which piece do you want to move?
Please enter an available piece number or quit.

8
Where do you want to move that game piece to on the game board?

Enter the coordinates
Position #,# or quit.
0,2

2 8
1 3 5 7
0 4 9 2
X 0 1 2
Available pieces: 1 6
Which piece do you want to move?
Please enter an available piece number or quit.

1
Where do you want to move that game piece to on the game board?

Enter the coordinates
Position #,# or quit.
1,2

2 8 1
1 3 5 7
0 4 9 2
X 0 1 2
Available pieces: 6
Which piece do you want to move?
Please enter an available piece number or quit.

6
Where do you want to move that game piece to on the game board?

Enter the coordinates
Position #,# or quit.
2,2

2 8 1 6
1 3 5 7
0 4 9 2
X 0 1 2
Available pieces:
You won the game!!!!
You have played 9 moves

My program's output:

4
3   A A A
2   A A A
1   A A A
0
X 0 1 2 3 4



what's your start piece?
Position #,# or quit.
1,1
what's your end piece?
Position #,# or quit.
3,0
Move is not successful!
what's your start piece?
Position #,# or quit.
2,2
what's your end piece?
Position #,# or quit.
2,4

4     A
3   A   A
2   A   A
1   A A A
0
X 0 1 2 3 4

The piece has been moved to 2 4
Continue to move?Type Y or N
Y
what's your end piece?
Position #,# or quit.
4,2

4
3   A
2   A   A A
1   A A A
0
X 0 1 2 3 4

The piece has been moved to 4 2
Continue to move?Type Y or N
Y
what's your end piece?
Position #,# or quit.
2,0

4
3   A
2   A   A
1   A A
0     A
X 0 1 2 3 4

The piece has been moved to 2 0
Continue to move?Type Y or N
Y
what's your end piece?
Position #,# or quit.
0,2

4
3   A
2 A A   A
1     A
0
X 0 1 2 3 4

The piece has been moved to 0 2
Continue to move?Type Y or N
Y
what's your end piece?
Position #,# or quit.
2,4

4     A
3
2   A   A
1     A
0
X 0 1 2 3 4

The piece has been moved to 2 4
Continue to move?Type Y or N
N
what's your start piece?
Position #,# or quit.
2,1
what's your end piece?
Position #,# or quit.
1,3
Move is not successful!
what's your start piece?
Position #,# or quit.
2,1
what's your end piece?
Position #,# or quit.
0,3

4     A
3 A
2       A
1
0
X 0 1 2 3 4

No valid moves left on the game board. You lost the game:(
H:\My Documents\Visual Studio 2015\Projects\lab3\Debug>lab3.exe NineAlmonds

4
3   A A A
2   A A A
1   A A A
0
X 0 1 2 3 4

what's your start piece?
Position #,# or quit.
2,2
what's your end piece?
Position #,# or quit.
0,2

4
3   A A A
2 A     A
1   A A A
0
X 0 1 2 3 4

The piece has been moved to 0 2
Continue to move?Type Y or N
N
what's your start piece?
Position #,# or quit.
qui
Invalid input, enter in the correct form
Position #,# or quit.
quit
You quit the game and you have played 1 moves



Types of errors my programs can handle:
1. bad argument number:
	give out the usage message and tell the user the argument number is false.
2. bad argument game name:
	give out the usage message and tell the user the command line is bad.
3. quit error:
	since the user chooses quit, return quit error.
4. stucked there error:
	since there is no valid move on the board, return stucked error
5. wrong game size error:
	when using the extra credit set up, if the user's input for game board dimension is less than 1, return the wrong game size error
6. unknown exception error:
	other errors not recorded

*********************extra credit***************
How I design:
I use a constructor that assign the game dimensions and start number with 3 and 1 as default if they are not defined.
Then in the gamestart() within gamebase class, I can check if the argument number is 2 or not. 
If it is 2 and the filename is MagicSquare, I can then start a default magic square game.
If it is 3, and the subsequent number is larger or equals to 1, then I can then 

Then I update the magic square class with a new private variable which is the start number and update every places where I need
to calculate and compare if the game piece number is available or not to check if it is within the range or not.



output:

H:\My Documents\Visual Studio 2015\Projects\lab3\Debug>lab3.exe MagicSquare 4 -2


3
2
1
0
X0123
Available pieces: -2 -1 0 1 2 3 4 5 6 7 8 9 10 11 12 13
Which piece do you want to move?
Please enter an available piece number or quit.

-2
Where do you want to move that game piece to on the game board?

Enter the coordinates
Position #,# or quit.
1,3

3     -2
2
1
0
X  0  1  2  3
Available pieces: -1 0 1 2 3 4 5 6 7 8 9 10 11 12 13
Which piece do you want to move?
Please enter an available piece number or quit.

-1
Where do you want to move that game piece to on the game board?

Enter the coordinates
Position #,# or quit.
3,2

3     -2
2           -1
1
0
X  0  1  2  3
Available pieces: 0 1 2 3 4 5 6 7 8 9 10 11 12 13
Which piece do you want to move?
Please enter an available piece number or quit.

0
Where do you want to move that game piece to on the game board?

Enter the coordinates
Position #,# or quit.
0,1

3     -2
2           -1
1  0
0
X  0  1  2  3
Available pieces: 1 2 3 4 5 6 7 8 9 10 11 12 13
Which piece do you want to move?
Please enter an available piece number or quit.

1
Where do you want to move that game piece to on the game board?

Enter the coordinates
Position #,# or quit.
2,0

3     -2
2           -1
1  0
0        1
X  0  1  2  3
Available pieces: 2 3 4 5 6 7 8 9 10 11 12 13
Which piece do you want to move?
Please enter an available piece number or quit.

2
Where do you want to move that game piece to on the game board?

Enter the coordinates
Position #,# or quit.
2,1

3     -2
2           -1
1  0     2
0        1
X  0  1  2  3
Available pieces: 3 4 5 6 7 8 9 10 11 12 13
Which piece do you want to move?
Please enter an available piece number or quit.

3
Where do you want to move that game piece to on the game board?

Enter the coordinates
Position #,# or quit.
0,0

3     -2
2           -1
1  0     2
0  3     1
X  0  1  2  3
Available pieces: 4 5 6 7 8 9 10 11 12 13
Which piece do you want to move?
Please enter an available piece number or quit.

4
Where do you want to move that game piece to on the game board?

Enter the coordinates
Position #,# or quit.
3,3

3     -2    4
2           -1
1  0     2
0  3     1
X  0  1  2  3
Available pieces: 5 6 7 8 9 10 11 12 13
Which piece do you want to move?
Please enter an available piece number or quit.

5
Where do you want to move that game piece to on the game board?

Enter the coordinates
Position #,# or quit.
1,2

3     -2    4
2     5     -1
1  0     2
0  3     1
X  0  1  2  3
Available pieces: 6 7 8 9 10 11 12 13
Which piece do you want to move?
Please enter an available piece number or quit.

6
Where do you want to move that game piece to on the game board?

Enter the coordinates
Position #,# or quit.
3,0

3     -2    4
2     5     -1
1  0     2
0  3     1  6
X  0  1  2  3
Available pieces: 7 8 9 10 11 12 13
Which piece do you want to move?
Please enter an available piece number or quit.

7
Where do you want to move that game piece to on the game board?

Enter the coordinates
Position #,# or quit.
1,1

3     -2    4
2     5     -1
1  0  7  2
0  3     1  6
X  0  1  2  3
Available pieces: 8 9 10 11 12 13
Which piece do you want to move?
Please enter an available piece number or quit.

8
Where do you want to move that game piece to on the game board?

Enter the coordinates
Position #,# or quit.
2,2

3     -2    4
2     5  8  -1
1  0  7  2
0  3     1  6
X  0  1  2  3
Available pieces: 9 10 11 12 13
Which piece do you want to move?
Please enter an available piece number or quit.

9
Where do you want to move that game piece to on the game board?

Enter the coordinates
Position #,# or quit.
0,3

3  9  -2    4
2     5  8  -1
1  0  7  2
0  3     1  6
X  0  1  2  3
Available pieces: 10 11 12 13
Which piece do you want to move?
Please enter an available piece number or quit.

10
Where do you want to move that game piece to on the game board?

Enter the coordinates
Position #,# or quit.
0,2

3  9  -2    4
2  10 5  8  -1
1  0  7  2
0  3     1  6
X  0  1  2  3
Available pieces: 11 12 13
Which piece do you want to move?
Please enter an available piece number or quit.

11
Where do you want to move that game piece to on the game board?

Enter the coordinates
Position #,# or quit.
2,3

3  9  -2 11 4
2  10 5  8  -1
1  0  7  2
0  3     1  6
X  0  1  2  3
Available pieces: 12 13
Which piece do you want to move?
Please enter an available piece number or quit.

12
Where do you want to move that game piece to on the game board?

Enter the coordinates
Position #,# or quit.
1,0

3  9  -2 11 4
2  10 5  8  -1
1  0  7  2
0  3  12 1  6
X  0  1  2  3
Available pieces: 13
Which piece do you want to move?
Please enter an available piece number or quit.

13
Where do you want to move that game piece to on the game board?

Enter the coordinates
Position #,# or quit.
3,1

3  9  -2 11 4
2  10 5  8  -1
1  0  7  2  13
0  3  12 1  6
X  0  1  2  3
Available pieces:
You won the game!!!!
You have played 16 moves
