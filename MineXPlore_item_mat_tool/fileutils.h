#ifndef FILEUTILS_H
#define FILEUTILS_H

#include "libraries.h"


typedef struct fileNameComponents {

	char* filePath;
	char* fileName;

}fileNmCmpnts;

fileNmCmpnts* fileNameCmpntsInit(char* file_path, char* file_name);

FILE* fileOpenRead(const char* fileName);

FILE* fileOpenWrite(char* fileName);

//Returns file name.
char* getFileName(fileNmCmpnts* filepath);

//Returns file path.
char* get_file_path(fileNmCmpnts* filepath);

//Return the number of lines of a .txt file
int countNbLinesInFile(fileNmCmpnts* filepath);
#endif