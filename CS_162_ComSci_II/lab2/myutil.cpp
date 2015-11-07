// This is the Lab 2 / Personal Organizer (myutil.cpp)
// Written by: Joseph Kramer
// Class: CS162
// Date: 07/11/17
// Sources: Text Book, course videos, in class examples


#include "myutil.h"


/*
Purpose: Used to read in and validate strings
*/
void readInString (const char a_cPrompt[], char a_cInputStr[], int iMaxChar) {
	cout << endl << a_cPrompt;

	cin.get(a_cInputStr, iMaxChar, '\n');
	while(!cin) {
		cin.clear ();
		cin.ignore (100, '\n');
		cout << endl << a_cPrompt;
		cin.get(a_cInputStr, iMaxChar, '\n');
	}

	cin.ignore (100, '\n');
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


/*
Used to pause the program
*/
void pause() {
	char	ch;
	cout << "Press any key to Quit...";
	cin >> ch;
}
