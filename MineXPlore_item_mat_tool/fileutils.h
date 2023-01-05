#ifndef FILEUTILS_H
#define FILEUTILS_H

#include "libraries.h"


typedef struct fileNameComponents {

	char* fileExtTxt;  // contains ".txt"
	char* fileExtYml;  // contains ".yml"
	char  undsc;	   // contains "_"


}filNmCmpnts;


FILE* fileOpenRead(const char* fileName);

FILE* fileOpenWrite(char* fileName);



#endif