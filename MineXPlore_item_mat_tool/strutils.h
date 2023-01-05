#ifndef STRUTILS_H
#define STRUTILS_H

#include "libraries.h"


typedef struct wordBank {
	
	char* itemName;			//Item name to put in file name
	char* baseAttribName;	//reference word to replace in all files
	char** attribNames;		//List of colors/materials fetched from .txt databank

}wordBank;

wordBank* wordBankInit(const char baseAttribute,
					   const char itemName,
					   FILE* attribList,
					   int attribQty);

#endif