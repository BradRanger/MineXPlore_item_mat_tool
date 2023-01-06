#include "libraries.h"
#include "fileutils.h"
#include "strutils.h"

int main(void) {

	fileNmCmpnts* attribListFP;



	char buff[BUFFER_LGT] = "";
	char buff1[BUFFER_LGT] = "";
	strcpy(buff,stringUserInput("attributes file name"));
	strcpy(buff, strRemoveRrtn(buff));

	attribListFP = fileNameCmpntsInit("", buff);

	printf("%i\n",countNbLinesInFile(attribListFP));

	printf("%s\n", getFileName(attribListFP));

	
}


//FILE* file;

//bool keepReading = true;

//char buffer[BUFFER_LGT] = "";

//int count = 0;

//file = fopen("zcolors.txt", "r");

//if (file == NULL) {
//	printf("Couldn't open file.");
//	exit(EXIT_FAILURE);
//}

//do {

//	fgets(buffer, BUFFER_LGT, file);
//	if (feof(file)) {
//		keepReading = false;
//	};

//	strcpy(  )

//	count++;
//} while (keepReading);

//fclose(file);
//return count;
