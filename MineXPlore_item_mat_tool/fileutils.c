#include "fileutils.h"


fileNmCmpnts* fileNameCmpntsInit(char* file_path, char* file_name) {

	fileNmCmpnts* components;

	components = (fileNmCmpnts*)malloc(sizeof(fileNmCmpnts));
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

	strcpy(components->fileExtYml,".yml");

	components->file_name = (char*)malloc(sizeof(char) * (strlen(file_name) + 1));

	if (components->file_name == NULL) {
		free(components->fileExtYml);
		free(components->fileExtTxt);
		free(components->file_name);
		free(components);

		printf("Out of memory.");
		exit(EXIT_FAILURE);

	}

	components->file_name = file_name;

	components->file_path = (char*)malloc(sizeof(char) * (strlen(file_path) + 1));

	if (components->file_path == NULL) {
		free(components->fileExtYml);
		free(components->fileExtTxt);
		free(components->file_name);
		free(components->file_path);
		free(components);

		printf("Out of memory.");
		exit(EXIT_FAILURE);
	}
	components->file_path = file_path;

	components->temp_ext = "temp____";
	if (components->file_path == NULL) {
		
		free(components->fileExtYml);
		free(components->fileExtTxt);
		free(components->file_name);
		free(components->file_path);
		free(components->temp_ext);
		free(components);

		printf("Out of memory.");
		exit(EXIT_FAILURE);
	}



	components->undsc = '_';

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

	return filepath->file_name;
}

char* get_file_path(fileNmCmpnts* filepath) {

	return filepath->file_path;
}

char* get_temp_ext(fileNmCmpnts* filepath) {

	return filepath->temp_ext;
}

char* cat_path__file(fileNmCmpnts* filepath) {

	char buff[FILENAME_MAX] = { 0 };

	strcpy(buff, filepath->file_path);
	strcat(buff, filepath->file_name);

	return buff;
};

char* cat_temp__file(fileNmCmpnts* filepath) {

	char buff[FILENAME_MAX] = { 0 };

	strcat(buff, filepath->temp_ext);
	strcat(buff, filepath->file_name);

	return buff;
};

char* cat_path__temp__file(fileNmCmpnts* filepath) {

	char buff[FILENAME_MAX] = { 0 };

	strcpy(buff, filepath->file_path);
	strcat(buff, filepath->temp_ext);
	strcat(buff, filepath->file_name);

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