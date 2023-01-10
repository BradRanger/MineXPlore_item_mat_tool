#include "fileutils.h"


fileNmCmpnts* fileNameCmpntsInit(char* file_path, char* file_name) {

	fileNmCmpnts* components;

	components = (fileNmCmpnts*)malloc(sizeof(fileNmCmpnts));
	if (components == NULL) {
		free(components);
		exit(EXIT_FAILURE);
	}
	components->fileName = (char*)malloc(sizeof(char) * (strlen(file_path) + 1));
	if (components->fileName == NULL) {
		free(components->fileName);
		free(components);

		printf("Out of memory.");
		exit(EXIT_FAILURE);
	}
	components->fileName = file_name;

	components->filePath = (char*)malloc(sizeof(char) * (strlen(file_path) + 1));
	if (components->filePath == NULL) {
		free(components->fileName);
		free(components->filePath);
		free(components);

		printf("Out of memory.");
		exit(EXIT_FAILURE);
	}
	components->filePath = file_path;

	return components;
}

FILE* fileOpenRead(const char* fileName) {

	FILE* file;
	file = fopen(fileName, "r");
	if (file == NULL) {
		printf("File could not be opened.");
		exit(EXIT_FAILURE);
	}

	return file;
}

FILE* fileOpenWrite(char* fileName) {

	FILE* file;
	file = fopen(fileName, "w");
	if (file == NULL) {
		printf("File could not be opened.");
		exit(EXIT_FAILURE);
	}

	return file;
}

char* getFileName(fileNmCmpnts* filepath) {

	return filepath->fileName;
}

char* get_file_path(fileNmCmpnts* filepath) {

	return filepath->filePath;
}

char* get_temp_ext(fileNmCmpnts* filepath) {

	return filepath->temp_ext;
}

char* cat_path__file(fileNmCmpnts* filepath) {

	char buff[FILENAME_MAX] = { 0 };

	strcpy(buff, filepath->filePath);
	strcat(buff, filepath->fileName);

	return buff;
};

char* cat_temp__file(fileNmCmpnts* filepath) {

	char buff[FILENAME_MAX] = { 0 };

	strcat(buff, filepath->temp_ext);
	strcat(buff, filepath->fileName);

	return buff;
};

char* cat_path__temp__file(fileNmCmpnts* filepath) {

	char buff[FILENAME_MAX] = { 0 };

	strcpy(buff, filepath->filePath);
	strcat(buff, filepath->temp_ext);
	strcat(buff, filepath->fileName);

	return buff;
};

int countNbLinesInFile(fileNmCmpnts* filepath) {


	FILE* file;
	bool keepReading = true;

	char buffer[BUFFER_LGT] = "";

	int count = 0;

	file = fileOpenRead(getFileName(filepath));

	if (file == NULL) {
		printf("Couldn't open file.");
		exit(EXIT_FAILURE);
	}

	do {

		fgets(buffer, BUFFER_LGT, file);

		if (feof(file)) {
			keepReading = false;
		};
		count++;
	} while (keepReading);

	fclose(file);
	return count;
}