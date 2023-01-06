#ifndef STRUTILS_H
#define STRUTILS_H

#include "libraries.h"

//List of colors/materials fetched from .txt databank
typedef struct t_attributeNamesList {



	char** AttribNameLwrC;	//lowercase reference word to replace in all files
	char** AttribNameUprC;	//Converted to uppercase reference word

}attNameList;



typedef struct wordBank {
	
	char* itemName;				//Item name to put in file name
	char* baseAttribute;		//Stores the target attribute to replace in the file
	attNameList attribList;		//Stores lowercase and uppercase list

}wordBank;


wordBank* wordBankInit(const char baseAttribute,
					   const char itemName);

char* stringUserInput(const char* objName);

char* strRemoveRrtn(char* string);

#endif