******************************
Graded by: Zhenghan Li
Email: li.zhenghan@wustl.edu

Grade: 100/100

Deductions:

*******************************
Name: Jiangnan Liu
Lab number: lab2


Errors and warnings: 
1.unsigned integer and signed integer mismatched warning
2.no return value for the done() method(corrected already)
3.Severity	Code	Description	Project	File	Line	Suppression State
Error	C2664	'int printboard(const std::vector &,unsigned int,unsigned int)': cannot convert argument 1 from 'const std::vector<gp,std::allocator<_Ty>>' to 'const std::vector &'	lab2	\\warehouse2.seasad.wustl.edu\home\liu433\my documents\visual studio 2015\projects\lab2\lab2\almondgame.cpp	31	
4.Severity	Code	Description	Project	File	Line	Suppression State
Error	C2923	'std::vector': 'gp' is not a valid template type argument for parameter '_Ty'	lab2	\\warehouse2.seasad.wustl.edu\home\liu433\my documents\visual studio 2015\projects\lab2\lab2\gameb.h	13	
5.Severity	Code	Description	Project	File	Line	Suppression State
Error	C3203	'allocator': unspecialized class template can't be used as a template argument for template parameter '_Alloc', expected a real type	lab2	\\warehouse2.seasad.wustl.edu\home\liu433\my documents\visual studio 2015\projects\lab2\lab2\gameb.h	13	
6.Severity	Code	Description	Project	File	Line	Suppression State
Error	C2923	'std::vector': 'gp' is not a valid template type argument for parameter '_Ty'	lab2	\\warehouse2.seasad.wustl.edu\home\liu433\my documents\visual studio 2015\projects\lab2\lab2\gameb.h	13	
7.Severity	Code	Description	Project	File	Line	Suppression State
Error	C2664	'int printboard(const std::vector,unsigned int,unsigned int)': cannot convert argument 1 from 'const std::vector<gp,std::allocator<_Ty>>' to 'const std::vector'	lab2	\\warehouse2.seasad.wustl.edu\home\liu433\my documents\visual studio 2015\projects\lab2\lab2\almondgame.cpp	33	
8.Severity	Code	Description	Project	File	Line	Suppression State
Error	C2065	'gp': undeclared identifier	lab2	\\warehouse2.seasad.wustl.edu\home\liu433\my documents\visual studio 2015\projects\lab2\lab2\gameb.h	12	

comments in source file

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
H:\My Documents\Visual Studio 2015\Projects\lab2\Debug>lab2.exe NineAlmonds

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
3. bad argument game name:
	give out the usage message and tell the user the command line is bad.
2. quit error:
	since the user chooses quit, return quit error.
3. stucked there error
	since there is no valid move on the board, return stucked error


