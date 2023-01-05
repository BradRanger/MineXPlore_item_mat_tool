#include "fileutils.h"


filNmCmpnts* fileNameCmpntsInit() {

	filNmCmpnts* components;

	components = (filNmCmpnts*)malloc(sizeof(filNmCmpnts));
	if (components == NULL) {
		free(components);
		exit(EXIT_FAILURE);
	}

	components->fileExtTxt = (char*)malloc(sizeof(strlen(".txt")));
	if (components->fileExtTxt == NULL) {
		free(components->fileExtTxt);
		free(components);
		exit(EXIT_FAILURE);
	}

	strcpy(components->fileExtTxt, ".txt");

	components->fileExtYml = (char*)malloc(sizeof(strlen(".yml")));
	if (components->fileExtYml == NULL) {
		free(components->fileExtYml);
		free(components->fileExtTxt);
		free(components);
		exit(EXIT_FAILURE);
	}

	strcpy(components->fileExtYml, ".yml");


	components->undsc = "_";
}

FILE* fileOpenRead(const char* fileName) {

	FILE* file;
	file = fopen(fileName, "r");
	if (file == NULL) {
		exit(EXIT_FAILURE);
	}

	return file;
}

FILE* fileOpenWrite(char* fileName) {

	FILE* file;
	file = fopen(fileName, "w");
	if (file == NULL) {
		exit(EXIT_FAILURE);
	}

	return file;
}



int countNbLinesInFile(FILE* file) {

	char buffer[BUFFER_LGT] = "";
	if (fgets(buffer, BUFFER_LGT, file) > BUFFER_LGT) {
		printf("")
	
	};

}