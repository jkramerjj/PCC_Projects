/* A header file for the standard my_utilities.

   Written by: Joseph Kramer
   Date: 07-12-14

   Sources: None
*/

#ifndef MY_UTILITIES
#define MY_UTILITIES

// Constants
const int	iMAX_CHAR = 101;
const int	iCOL_SEARCH_WIDTH = 20;
const int	iCOL_WIDTH_NAME = 15;
const int	iCOL_WIDTH_DESCRIPTION = 30;
const int	iCOL_WIDTH_DUE_DATE = 15;
const int	iDATE_CHAR_MAX = 35;




//function prototypes
int readInt(const char a_cPrompt[]);
double readDouble(const char a_cPrompt[]);
char readChar(const char a_cPrompt[]);
void readString (const char a_cPrompt[], char a_cInputStr[], int a_cMaxChar);
void pause();
char verifyQuit(char cInCommand);
void getYesOrNo (char& r_YesOrNO);

#endif