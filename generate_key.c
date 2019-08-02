/** Script for randomly generating key
 * Author: Maleakhi Agung Wijaya
 * Date: 11/09/2016
 * Student Number: 784091
 */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUMBER_OF_KEYS 5000
#define INPUT_ARG 1
#define OUTPUT_ARG 2

#define MAX_KEY 65
#define MAX_DATA 1466
#define NULL_BYTE_LENGTH 1

/** Main function to generate key */
int 
main(int argc, char *argv[]) {
	int i;
	int count = 0;

	FILE *fileIn = fopen(argv[INPUT_ARG], "r");
	FILE *fileOut = fopen(argv[OUTPUT_ARG], "w");

	char temporary[MAX_DATA + MAX_KEY + NULL_BYTE_LENGTH]; //store line
	char key[MAX_KEY]; // store key

	// Initialize Seed
	srand(time(NULL));

	while (count < NUMBER_OF_KEYS && (fgets(temporary, MAX_DATA + MAX_KEY + NULL_BYTE_LENGTH , fileIn) != NULL)) {
		/* Iterate through every character in the string until (,) and store
		 * in first string array consist of key, iterate through until \n and
		 * store in second string array consist of data
		 */
		for (i = 0; temporary[i] != ','; i ++) {
			key[i] = temporary[i];
		}
		// Close the string
		key[i] = '\0'; 

		// Random
		if ((rand() % 2) == 1) {
			// Print to output
			fprintf(fileOut, "%s\n", key);
			count ++;
		}
	}

	fclose(fileIn);
	fclose(fileOut);

	return 0;
}
