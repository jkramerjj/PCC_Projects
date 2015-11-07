/* A header file for myutil.cpp

   Written by: Joseph Kramer
   Date: 07/11/14

   Sources: couse videos
*/


#ifndef MYUTIL_H
#define MYUTIL_H
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>

using namespace std;

const int	iMAX_CHAR = 101;
const int	iDATE_CHAR_MAX = 50;
const int	iLIST_SIZE = 101;

// Prototypes -- Basic Functions
void pause(); 
void getYesOrNo (char& r_YesOrNO);
void readInString (const char a_cPrompt[], char a_cInputStr[], int iMaxChar);
char verifyQuit(char cInCommand);


#endif