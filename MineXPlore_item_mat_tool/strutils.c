#include "strutils.h"


attNameList* attribListInit(fileNmCmpnts* fileComponents,
							int attribQty) {

	FILE* file;
	char filenameBuff[BUFFER_LGT] = "";
	char attribBuff[BUFFER_LGT] = "";
	attNameList* attributeList;



	attributeList = (attNameList*)malloc(sizeof(attNameList));
	if (attributeList == NULL) {

		free(attributeList);
		printf("Out of memory.");
		exit(EXIT_FAILURE);
	}

	file = fileOpenRead(getFileName(fileComponents));

	attributeList->AttribNameLwrC = (char**)malloc(sizeof(char*) * attribQty);
	if (attributeList->AttribNameLwrC == NULL) {

		free(attributeList->AttribNameLwrC);
		free(attributeList);
		printf("Out of memory.");
		exit(EXIT_FAILURE);
	}

	attributeList->AttribNameUprC = (char**)malloc(sizeof(char*) * attribQty);
	if (attributeList->AttribNameUprC == NULL) {

		free(attributeList->AttribNameLwrC);
		free(attributeList->AttribNameUprC);
		free(attributeList);
		printf("Out of memory.");
		exit(EXIT_FAILURE);
	}


	for (int i = 0; i < attribQty; i++) {

		fgets(attribBuff, BUFFER_LGT, file);
		attributeList->AttribNameLwrC[i] = (char*)malloc(sizeof(char) * strlen(attribBuff)+1);
		attributeList->AttribNameUprC[i] = (char*)malloc(sizeof(char) * strlen(attribBuff)+1);
		
		if (attributeList->AttribNameLwrC[i] == NULL) {
			do {
				free(attributeList->AttribNameLwrC[i]);
				free(attributeList->AttribNameUprC[i]);
				i--;
			} while (i != 0);

			free(attributeList->AttribNameLwrC);
			free(attributeList->AttribNameUprC);
			free(attributeList);
			printf("Out of memory.");

		}

		
		strcpy(attribBuff,strRemoveRrtn(attribBuff)); 
		strcpy(attributeList->AttribNameLwrC[i], attribBuff);
		strcpy(attributeList->AttribNameUprC[i], strToUprC(attribBuff));

	}
	fclose(file);

	return attributeList;
}

wordBank* wordBankInit(const char* baseAttribute,
					   const char* itemName){

	wordBank* newWordBank;

	newWordBank = (wordBank*)malloc(sizeof(wordBank));
	if (newWordBank == NULL) {
		free(newWordBank);
		printf("Out of memory.");
		exit(EXIT_FAILURE);
	} 

	newWordBank->baseAttribute = (char*)malloc(sizeof(char) * strlen(baseAttribute));
	if (newWordBank->baseAttribute == NULL) {
		free(newWordBank->baseAttribute);
		free(newWordBank);
		printf("Out of memory.");
		exit(EXIT_FAILURE);
	}
	strcpy(newWordBank->baseAttribute, baseAttribute);

	newWordBank->itemName = (char*)malloc(sizeof(char) * strlen(itemName));
	if (newWordBank->itemName == NULL) {
		free(newWordBank->baseAttribute);
		free(newWordBank->itemName);
		free(newWordBank);
		printf("Out of memory.");
		exit(EXIT_FAILURE);
	}

	strcpy(newWordBank->itemName, itemName);

	return newWordBank;

}

char* stringUserInput(const char* objName) {
	char buff[BUFFER_LGT] = "";

	do {
		printf("Please enter %s.",objName);
		fflush(stdin);
		fgets(buff, BUFFER_LGT, stdin);

	} while (buff == NULL);


	return buff;

}


char* strRemoveRrtn(char* string) {
	char buff[BUFFER_LGT] = "";
	strcpy(buff, string);
	buff[strcspn(buff, "\n")] = 0;
	return buff;
}

char* strToUprC(char* string) {

	char buff[BUFFER_LGT] = "";
	strcpy(buff, string);
	_strupr(buff);
	return buff;
}

int countWordInString(const char* string,
					  const char* targetWord) {
	
	int nbCount = 0;
	if (strlen(targetWord) == 0) return 0;

	for (int i = 0; string[i] != '\0'; i++) {

		//Returns first occurence of second parameter in first parameter
		if (strstr(string[i], targetWord) == string[i]) {
			nbCount++;
			i += strlen(targetWord) - 1;
		}
	}
	return nbCount;

}

char* replaceWordInString(const char* string,
						  const char* targetWord,
						  const char* newWord) {

	int newWordLen = strlen(newWord);	//Counts current word length
	int oldWordLen = strlen(targetWord);	//Counts target word length
	int stringLen = strlen(string);		//Counts current string lenght

	if (stringLen == 0 || oldWordLen == 0) {
		return NULL;
	}

	int nbInstances = countWordInString(string, targetWord);	//Checks if target word is present in string

	char* newLine = "";	//Stores line replacement 

	int oldPos = 0, 
		newPos = 0;

	while (nbInstances > 0) {	//While theres at least one instance of target word


		char* nextOldWordPos = strstr(string[oldPos], targetWord);


		int lenToCopyBefore = nextOldWordPos - string[oldPos];


		//string storage  where str 			where to stop copying
		//
		strncpy(&newLine[newPos], string[oldPos], lenToCopyBefore);   //
		newPos += lenToCopyBefore;

		strncpy(&newLine[newPos], newWord, newWordLen);
		newPos += newWordLen;

		oldPos += lenToCopyBefore + oldWordLen;
		nbInstances--;
	}
	int lenToCopy = string[stringLen] - string[oldPos];
	strncpy(&newLine[newPos], string[oldPos], lenToCopy);
	newLine[stringLen] = '\0';

	return newLine;

}
