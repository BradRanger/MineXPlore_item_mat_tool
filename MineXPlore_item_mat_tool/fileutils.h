#ifndef FILEUTILS_H
#define FILEUTILS_H

#include "libraries.h"


typedef struct fileNameComponents {

	char* file_path;
	char* file_name;
	
	char* temp_ext; // stores "temp____"
	char* fileExtTxt;  // contains ".txt"
	char* fileExtYml;  // contains ".yml"
	char  undsc;	   // contains "_"


}fileNmCmpnts;

fileNmCmpnts* fileNameCmpntsInit(char* file_path, char* file_name);

FILE* fileOpenRead(const char* fileName);

FILE* fileOpenWrite(char* fileName);

//Returns file name.
char* getFileName(fileNmCmpnts* filepath);

//Returns file path.
char* get_file_path(fileNmCmpnts* filepath);

//Returns temp extension.
char* get_temp_ext(fileNmCmpnts* filepath);

//Returns concatenated filepath with filename.
char* cat_path__file(fileNmCmpnts* filepath);

//Returns concatenated temp extension with file name.
char* cat_temp__file(fileNmCmpnts* filepath);

//Returns concatenated filepath, temp extension and filename.
char* cat_path__temp__file(fileNmCmpnts* filepath);

//Return the number of lines of a .txt file
int countNbLinesInFile(fileNmCmpnts* filepath);
#endif