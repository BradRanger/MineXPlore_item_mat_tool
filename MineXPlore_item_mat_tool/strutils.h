#ifndef STRUTILS_H
#define STRUTILS_H

#include "libraries.h"
#include "fileutils.h"

//List of colors/materials fetched from .txt databank
typedef struct t_attributeNamesList {

	char** AttribNameLwrC;	//lowercase reference word to replace in all files
	char** AttribNameUprC;	//Converted to uppercase reference word

}attNameList;



typedef struct t_wordBank {
	

	char* itemName;				//Item name to put in file name
	char* baseAttribute;		//Stores the target attribute to replace in the file
	attNameList* attribList;		//Stores lowercase and uppercase list

}wordBank;

//Takes in fileComponents to get a filename or a combination of filename and filepath
//attribQty to determine how many string allocations to make

//Creates memory allocation and stores lowercase and uppercase attributes.
attNameList* attribListInit(fileNmCmpnts* fileComponents,
							int attribQty);

//Asks user to initialize which words to find in .txt file
//baseAttribute should be a color or a material
wordBank* wordBankInit(const char* baseAttribute,
					   const char* itemName);


//User to define what text to display. objName should be ex: file name ; item name.
char* stringUserInput(const char* objName);

//Cleans the '\n' at the end of a string. 
char* strRemoveRrtn(char* string);

//Returns an uppercase version of the passed string.
char* strToUprC(char* string);

//Returns the number of times targetWord was found in string.
int countWordInString(const char* string,
					  const char* targetWord);

//Replaces targetWord with newWord in string.
char* replaceWordInString(const char* string,
					   	  const char* targetWord,
						  const char* newWord);

#endif