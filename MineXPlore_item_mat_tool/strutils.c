#include "strutils.h"
#include "fileutils.h"

wordBank* wordBankInit(const char baseAttribute,
					   const char itemName) {

	wordBank* newWordBank;

	newWordBank = (wordBank*)malloc(sizeof(wordBank));
	if (newWordBank == NULL) {
		free(newWordBank);
		exit(EXIT_FAILURE);
	}

	newWordBank->itemName = (char*)malloc(sizeof(char) * (strlen(itemName) + 1));
	if (newWordBank->itemName == NULL) {

		free(newWordBank->itemName);
		free(newWordBank);
		exit(EXIT_FAILURE);
	}

	  
	return newWordBank;

}

attNameList* attribListInit(FILE* sourceFile, 
							fileNmCmpnts* fileComponents,
							int attribQty) {


	char filenameBuff[BUFFER_LGT] = "";
	char attribBuff[BUFFER_LGT] = "";
	attNameList* attributeList;

	

	attributeList = (attNameList*)malloc(sizeof(attNameList));
	if (attributeList == NULL) {

		free(attributeList);
		exit(EXIT_FAILURE);
	}

	sourceFile = fileOpenRead(getFileName(fileComponents));

	attributeList->AttribNameLwrC = (char**)malloc(sizeof(char*) * attribQty);
	if (attributeList->AttribNameLwrC == NULL) {

		free(attributeList->AttribNameLwrC);
		free(attributeList);
		exit(EXIT_FAILURE);
	}



	fgets(attribBuff, BUFFER_LGT, sourceFile);
	strcpy(attributeList->AttribNameLwrC[0],attribBuff);

	return attributeList;
}


char* stringUserInput(const char* objName) {
	char buff[BUFFER_LGT] = "";

	do {
		printf("Please enter %s.\n",objName);
		fflush(stdin);
		fgets(buff, BUFFER_LGT, stdin);

	} while (buff == NULL);

	//buff[strcspn(buff, "\n")] = 0;

	return buff;

}


char* strRemoveRrtn(char* string) {
	char buff[BUFFER_LGT] = "";
	strcpy(buff, string);
	buff[strcspn(buff, "\n")] = 0;
	return buff;
}