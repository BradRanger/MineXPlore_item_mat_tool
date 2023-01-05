#include "strutils.h"


wordBank* wordBankInit(const char baseAttribute,
					   const char itemName,
					   FILE* attribList,
					   int attribQty) {

	wordBank* newWordBank;

	newWordBank = (wordBank*)malloc(sizeof(wordBank));
	if (newWordBank == NULL) {
		free(newWordBank);
		exit(EXIT_FAILURE);
	}

	newWordBank->baseAttribName = (char*)malloc(sizeof(char) * (strlen(baseAttribute) + 1));
	if (newWordBank->baseAttribName == NULL) {
		free(newWordBank->baseAttribName);
		free(newWordBank);
		exit(EXIT_FAILURE);
	}

	strcpy(newWordBank->baseAttribName, baseAttribute);

	newWordBank->itemName = (char*)malloc(sizeof(char) * (strlen(itemName) + 1));
	if (newWordBank->itemName == NULL) {
		
		free(newWordBank->itemName);
		free(newWordBank->baseAttribName);
		free(newWordBank);
		exit(EXIT_FAILURE);
	}

	strcpy(newWordBank->itemName, itemName);

	newWordBank->attribNames = (char**)malloc(sizeof(char*) * attribQty);


	  
	return newWordBank;

}