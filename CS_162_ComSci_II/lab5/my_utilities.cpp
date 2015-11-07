/* 
	The implementation file for my_utilities.h.

    Written by: Joseph Kramer
    Date: 08/06/14

    Sources: Text Book, course videos, in class examples
*/


#include "my_utilities.h"
#include <iostream>
using namespace std;

/* 
	This function reads an integer from the standard input and throws away the rest of the input line
    in: a_cPrompt
    return:  integer
*/
int readInt(const char a_cPrompt[]) {
	int		intVal;
	cout << endl << a_cPrompt;
	cin >> intVal;

	while (!cin) {
		cin.clear();
		cin.ignore(100, '\n');
		cout << "You've entered an illegal integer. Please try again: ";
		cin >> intVal;
	}

	cin.ignore(100, '\n');

	return intVal;
}


/* 
	This function reads a double from the standard input and throws away the rest of the input line.
    in: a_cPrompt
    return:  double
*/
double readDouble(const char a_cPrompt[]) {
	double		doubleVal;
	cout << endl << a_cPrompt;
	cin >> doubleVal;

	while (!cin) {
		
		cin.clear();
		cin.ignore(100, '\n');
		cout << "You've entered an illegal floating point value. Please try again: ";
		cin >> doubleVal;
	}
	cin.ignore(100, '\n');

	return doubleVal;
}

/* 
	This function reads a char from the standard input and throws away the rest of the input line.
    in: a_cPrompt
    return: a char
*/
char readChar(const char a_cPrompt[]) {
	char cChar;
	cout << endl << a_cPrompt;
	cin >> cChar;
	cin.ignore (100, '\n');
	return cChar;
}


/* 
	This function reads a c-string from the standard input and throws away the rest of the input line.
    in: a_cPrompt & a_cMaxChar: 
    out: a_cInputStr
*/
void readString (const char a_cPrompt[], char a_cInputStr[], int a_cMaxChar) {
	cout << endl << a_cPrompt;
	cin.get(a_cInputStr, a_cMaxChar, '\n');
	while(!cin) {
		cin.clear ();
		cin.ignore (100, '\n');
		cout << endl << a_cPrompt;
		cin.get(a_cInputStr, a_cMaxChar, '\n');
	}

	cin.ignore (100, '\n');
}



/*
	Used to pause the program
*/
void pause() {
	char	ch;
	cout << "Press any key to Quit...";
	cin >> ch;
}

/*
	Purpose:	Used to verify the user ment to select quit
	Out:		Will return cInCommand of 'y' or 'n'		
*/
char verifyQuit (char cInCommand) {
	char	cAnswer = ' ';
	
	if (cInCommand == 'q') {
		cout << "Are you sure you want to quit? (Y)es or (N)o" << endl;
		getYesOrNo (cAnswer);
		if (cAnswer == 'n') {
			cout << endl;
			return 'n';
		}
		else if (cAnswer == 'y') {
			return cInCommand;
		}
	}
}

/*
	This functions returns a character of 'y' or 'n' via refernce.
	in: r_YesOrNo --> which is referenced in by the calling fucntion
	out: r_YesOrNo via refernce
*/	
void getYesOrNo (char& r_YesOrNO) {
	char	yesno;
	cin >> yesno;
	yesno = tolower(yesno);
	while ((yesno !='y')&&(yesno !='n')) {
		cin.clear();
		cin.ignore(iMAX_CHAR, '\n');
		cout << "Please enter either (Y)es or (N)o ";
		cin >> yesno;
	}
	r_YesOrNO = yesno;
	cin.ignore(iMAX_CHAR, '\n');
}


