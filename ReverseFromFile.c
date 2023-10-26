//Date: 2023.10.26
//Purpose: Print the contents of a file in reverse order

#include <stdio.h>

int main() {

	//create the file, check for errors
	FILE* pFile = fopen("myfile.txt", "w+");
	if (pFile == NULL) {
		perror("Error opening the file");
		return 1;
	}
	//put content in it
	fputs("Hello this is to be reversed!", pFile);


	//jump to the end of the file, "cursor" position is saved in pFile of type FILE.
	// FILE type stores info about position, read or write, file name etc...
	fseek(pFile, 0, SEEK_END);
	//Store the position of the "cursor" in len variable, thus getting the length of the file
	long len = ftell(pFile); 
	char reverseString[50];
	char normalString[50];


	/*char* reverseString = (char*)malloc(len);
	if (reverseString == NULL) {
		perror("Error during memory allocation for reverseString");
		fclose(pFile);
		return 1;
	}*/

	//set the cursor back to the beginning of the file
	fseek(pFile, 0, SEEK_SET);

	//store the string in a variable
	int i = 0;
	while (i < len) {
		normalString[i] = fgetc(pFile);
		i++;
	}

	//Put a null terminator at the end.
	normalString[len] = '\0';

	printf("Original:%s\n", normalString);

	//store the reversed string
	i = 0;
	while (i < len) {
		reverseString[i] = normalString[(len-1) - i];
		i++;
	}
	reverseString[len] = '\0';

	printf("Modified:%s", reverseString);
	//close the file at the end
	fclose(pFile);
	pFile = NULL;
	return 0;
}