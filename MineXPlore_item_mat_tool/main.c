#include "libraries.h"
#include "fileutils.h"
#include "strutils.h"

int main(void) {

	fileNmCmpnts* attribListFP;			//attributes list filepath init
	fileNmCmpnts* sourceFile;			//file to create copies from filepath
	fileNmCmpnts* destinationFile;		//File buffer to create copies at
	
	wordBank* wordBank;					//base words

	attNameList* fetchedAttribs;       	//attribute list


	char buff[BUFFER_LGT] = "";			//source file filename
	char buff1[BUFFER_LGT] = "";		//attribute list filename
	char buff2[BUFFER_LGT] = "";		//base attribute name
	char buff3[BUFFER_LGT] = "";		//item name

	sourceFile = fileNameCmpntsInit("", buff);
	attribListFP = fileNameCmpntsInit("", buff1);

	strcpy(buff, stringUserInput("file to create copies from file name: "));
	strcpy(buff, strRemoveRrtn(buff));


	strcpy(buff1, stringUserInput("attributes file name: "));
	strcpy(buff1, strRemoveRrtn(buff1));

	fetchedAttribs = wordBankInit(buff2,
								  buff3);

	strcpy(buff2, stringUserInput("target attribute to replace (usually 'white'): "));

	int nbLinesInAttFile = countNbLinesInFile(attribListFP);

	wordBank = wordBankInit(buff2,
							buff3);


	fileOpenRead(getFileName(sourceFile));
	
	char newFileNames[BUFFER_LGT] = "";
	strcpy(newFileNames, wordBank->attribList->AttribNameLwrC[1]);
	printf("%s", newFileNames);

	////strcpy(newFileNames, wordBank->baseAttribute);
	////strcat(newFileNames, attribListFP->undsc);
	////strcat(newFileNames, wordBank->itemName);

	////printf("%s", newFileNames);


};

