/* A header file for io.cpp

   Written by: Joseph Kramer
   Date: 07/11/14

   Sources: couse videos
*/


#ifndef IO_H
#define IO_H

//#include "db.h"
#include <fstream>

// Prototypes -- File Input && Output
void openTaskFile (const char a_cFileName[], task taskList[], int& iListSize ); 
void saveTaskFile(const char a_cFileName[], const task taskList[], int iListSize);


#endif